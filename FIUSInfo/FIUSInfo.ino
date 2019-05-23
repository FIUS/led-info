#include <FastLED.h>
#include <WiFi.h>
#include "WLAN_CONF.hpp"
String debugInfo;

struct HttpResponse {
  String httpCode;
  String html;
};

const int LED_WIDTH = 64;
const int LED_HEIGTH = 8;
const int FONT_WIDTH = 5;
const int NUM_LEDS = LED_WIDTH * LED_HEIGTH + FONT_WIDTH * LED_HEIGTH + LED_HEIGTH * 2;
const int ENDPOINT_COUNT = 10;
const int ALIAS_COUNT=2;
//Messing around with DATA_PIN can cause compile problems due library name collision
const int DATA_PIN = 4;

CRGB leds[NUM_LEDS];
String endpoints[ENDPOINT_COUNT];
const String alias[]={"/smile","/fius"};
char font[300][6 * 8];



int status = WL_IDLE_STATUS;

WiFiServer server(80);

//Status variables
bool isActive = true;
String text = "Fachgruppe Informatik";
CRGB color = CRGB(0, 50, 180);
int animationType = 0;
double textSpeed = 40;
int emptyTicks = 40;
//End variables


void setup() {

  /*Defining endpoints*/
  endpoints[0] = "text";
  endpoints[1] = "color";
  endpoints[2] = "speed";
  endpoints[3] = "on";
  endpoints[4] = "animationType";
  endpoints[5] = "showImage";
  endpoints[6] = "showImageColor";
  endpoints[7] = "get";
  endpoints[8] = "emptyTicks";
  endpoints[9] = "getDebug";

  /*Loading the font*/
  initFont();

  /*Initializing LEDs and serial port*/
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(9600);
  FastLED.show();

  /*Connecting to Wifi or starting accesspoint*/
  setupWlan();

}

void loop() {
  refreshPage();
  refreshLED();
}

void setProgress(int character, int startIndex, CRGB color) {

  for (int j = 0; j < FONT_WIDTH * LED_HEIGTH; j++) {
    if (font[character][j] == 1) {
      leds[startIndex + j] = color;
    } else {
      leds[startIndex + j] = CRGB::Black;
    }
  }
  FastLED.show();
}

void setupWlan() {

  /*Trying to connect to wifi*/
  for (int i = 0; i < 5 && status != WL_CONNECTED; i++) {
    Serial.print("Trying to connect to SSID: ");
    Serial.println(ssid);

    status = WiFi.begin(ssid, pass);

    Serial.println(status);
    Serial.println(WiFi.localIP());

    int startindex = (FONT_WIDTH * LED_HEIGTH + LED_HEIGTH) * i;
    setProgress('o', startindex, CRGB::Yellow);

    /*wait 5 seconds for retry*/
    delay(5000);
  }

  /*Clear leds*/
  for (int j = 0; j < NUM_LEDS; j++) {
    leds[j] = CRGB::Black;
  }
  FastLED.show();

  /*If could'nt connect to wifi then open acesspoint*/
  if (status != WL_CONNECTED) {
    WiFi.softAP("shield", "PeterDerWolf");

    setProgress('A', 0, CRGB::Green);
  } else {

    setProgress('W', 0, CRGB::Green);
  }

  /*Start webserver*/
  server.begin();
  delay(5000);
}

void refreshPage() {

  WiFiClient client = server.available();
  bool check = false;
  HttpResponse resp;
  if (client) {
    /*Client connected to webserver*/
    String parsingString = "";


    bool currentLineIsBlank = true;
    HttpResponse httpResponse;
    httpResponse.httpCode = "HTTP/1.1 405 METHOD NOT ALLOWED";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        parsingString += c;
        int startIndex = parsingString.indexOf("POST");


        if (parsingString.lastIndexOf("HTTP/1.1") != -1 && !check) {
          /*We received the whole url*/
          check = true;

          int endIndex = parsingString.lastIndexOf("HTTP/1.1");
          parsingString = parsingString.substring(startIndex, endIndex);
          parsingString = parsingString.substring(7, parsingString.length() - 1);
          if (parsingString.indexOf("favicon.ico") == -1) {
            httpResponse = reactOnHTTPCall(parsingString);

          }

        }

        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header

          client.println(httpResponse.httpCode);
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println();

          client.println(httpResponse.html);

          break;
        }
        if (c == '\n') {
          currentLineIsBlank = true;
        } else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }

    delay(1);

    client.stop();

  }
}

HttpResponse reactOnHTTPCall(String message) {
  //debugInfo += message + "\n";
  String temp = "";
  String output = "HTTP/1.1 200 OK";
  int match = -1;
  String html = "";
  //debugInfo += message + "\n";
  /*Finding out what endpoint is called*/
  for (int i = 0; i < ENDPOINT_COUNT; i++) {
    if (message.startsWith(endpoints[i])) {
      temp = message.substring(endpoints[i].length() + 1);
      Serial.println(temp);
      match = i;
    }
  }
  //debugInfo += temp + "\n";
  /*Replacing http substituted character*/
  temp.replace("%20", " ");
  //debugInfo += temp + "\n";

  /*Parsing the endpoint info*/
  if (match == 0) {
    temp.replace("%E4","/ae");
    temp.replace("%F6","/oe");
    temp.replace("%FC","/ue");

    temp.replace("%C4","/AE");
    temp.replace("%D6","/OE");
    temp.replace("%DC","/UE");

    temp.replace("%C3%A4","/ae");
    temp.replace("%C3%B6","/oe");
    temp.replace("%C3%BC","/ue");

    temp.replace("%C3%84","/AE");
    temp.replace("%C3%96","/OE");
    temp.replace("%C3%9C","/UE");
    
    temp.replace("%27","'");
    Serial.println(temp);
    text = temp;
  } else if (match == 1) {
    int r = temp.substring(0, 3).toInt();
    int g = temp.substring(3, 6).toInt();
    int b = temp.substring(6, 9).toInt();

    color = CRGB(r, g, b);

  } else if (match == 2) {
    textSpeed = temp.toDouble();
  } else if (match == 3) {
    if (temp == "true") {
      isActive = true;
    } else {
      isActive = false;
    }
  } else if (match == 4) {
    animationType = temp.toInt();
  } else if (match == 5) {
    //TODO
  } else if (match == 6) {
    //TODO
  } else if (match == 7) {

    int r = color.r;
    int g = color.g;
    int b = color.b;

    String colorOUT = "RGB(" + String(r) + "," + String(g) + "," + String(b) + ")";

    html = "{\"text\":\"" + text + "\",\"speed\":" + textSpeed + ",\"isActive\":" +
           isActive + ",\"animationType\":" + animationType + ",\"color\":\"" + colorOUT + "\",\"emptyTicks\":\"" + emptyTicks + "\"}";
  } else if (match == 8) {
    emptyTicks = temp.toInt();
  } else if (match == 9) {
    html = debugInfo;
  }
  if (match == -1) {
    output = "HTTP/1.1 404 NO ENDPOINT";
  }
  HttpResponse resp;
  resp.httpCode = output;
  resp.html = html;

  return resp;

}
