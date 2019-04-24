#include <FastLED.h>
#include <WiFi.h>

struct HttpResponse {
  String httpCode;
  String html;
};

const int LED_WIDTH = 64;
const int LED_HEIGTH = 8;
const int FONT_WIDTH = 5;
const int NUM_LEDS = LED_WIDTH * LED_HEIGTH+FONT_WIDTH*LED_HEIGTH+LED_HEIGTH*2;
const int ENDPOINT_COUNT = 9;

//Messing around with DATA_PIN can cause compile problems due library name collision
const int DATA_PIN = 4;

CRGB leds[NUM_LEDS];
String endpoints[ENDPOINT_COUNT];
char ssid[] = "yourNetwork";      // your network SSID (name)
char pass[] = "secretPassword";   // your network password

int status = WL_IDLE_STATUS;

WiFiServer server(80);

//Status variables
bool isActive = true;
String text = "AB";
CRGB color = CRGB::Green;
int animationType = 0;
double textSpeed = 10;
int emptyTicks=20;
//End variables


void setup() {
  endpoints[0] = "text";
  endpoints[1] = "color";
  endpoints[2] = "speed";
  endpoints[3] = "on";
  endpoints[4] = "animationType";
  endpoints[5] = "showImage";
  endpoints[6] = "showImageColor";
  endpoints[7] = "get";
  endpoints[8] = "emptyTicks";
initFont();
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(9600);
  setupWlan();
  leds[100] = CRGB::White; FastLED.show();
}

void loop() {
  // listen for incoming clients
  refreshPage();
  refreshLED();
}

void setupWlan() {
  WiFi.softAP(ssid, "");
  server.begin();
  return;
  // atparsingStringt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("AtparsingStringting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);




    // wait 10 seconds for connection:
    delay(5000);
  }
  server.begin();
}

void refreshPage() {
  WiFiClient client = server.available();
  bool check = false;
  HttpResponse resp;
  if (client) {
    String parsingString = "";

    // an http request ends with a blank line
    bool currentLineIsBlank = true;
    HttpResponse httpResponse;
    httpResponse.httpCode = "HTTP/1.1 405 METHOD NOT ALLOWED";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        parsingString += c;
        int startIndex = parsingString.indexOf("POST");
        //  Serial.print(c);

        if (parsingString.lastIndexOf("HTTP/1.1") != -1 && !check) {
          check = true;

          int endIndex = parsingString.lastIndexOf("HTTP/1.1");
          parsingString = parsingString.substring(startIndex, endIndex);
          parsingString = parsingString.substring(8, parsingString.length() - 1);
          if (parsingString.indexOf("favicon.ico") == -1) {
            httpResponse = reactOnHTTPCall(parsingString);

          }

        }
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
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
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();

  }
}

HttpResponse reactOnHTTPCall(String message) {
  String temp = "";
  String output = "HTTP/1.1 200 OK";
  int match = -1;
  String html = "";
  for (int i = 0; i < ENDPOINT_COUNT; i++) {
    if (message.indexOf(endpoints[i]) != -1) {
      temp = message.substring(endpoints[i].length());
      Serial.println(temp);
      match = i;
    }
  }

  if (match == 0) {
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
           isActive + ",\"animationType\":" + animationType + ",\"color\":\"" + colorOUT + "\"}";
  }else if (match == 8) {
    emptyTicks=temp.toInt();
  }
  if (match == -1) {
    output = "HTTP/1.1 404 NO ENDPOINT";
  }
  HttpResponse resp;
  resp.httpCode = output;
  resp.html = html;
  Serial.println(text);
  return resp;

}
