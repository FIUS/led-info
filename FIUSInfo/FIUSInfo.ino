#include <FastLED.h>
#include <WiFi.h>


const int LED_WIDTH = 32;
const int LED_HEIGTH = 8;
const int NUM_LEDS = LED_WIDTH * LED_HEIGTH;

//Messing around with DATA_PIN can cause compile problems due library name collision
const int DATA_PIN = 4;

CRGB leds[NUM_LEDS];

char ssid[] = "yourNetwork";      // your network SSID (name)
char pass[] = "secretPassword";   // your network password

int status = WL_IDLE_STATUS;

WiFiServer server(80);

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(9600);
  setupWlan();
  leds[10] = CRGB::White; FastLED.show();
}

void loop() {
  // listen for incoming clients
  refreshPage();
  //refreshLED();
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
  if (client) {
    String parsingString = "";

    // an http request ends with a blank line
    bool currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        parsingString += c;
        int startIndex = parsingString.indexOf("GET");
      //  Serial.print(c);
        if (parsingString.lastIndexOf("HTTP/1.1") != -1 && !check) {
          check = true;

          int endIndex = parsingString.lastIndexOf("HTTP/1.1");
          parsingString = parsingString.substring(startIndex, endIndex);
          parsingString = parsingString.substring(5, parsingString.length() - 1);
          if (parsingString.indexOf("favicon.ico") == -1) {
            reactOnHTTPCall(parsingString);
          }

        }
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println();

          client.println("<!DOCTYPE HTML>");
          client.println("<html>");

          client.println("OK");

          client.println("</html>");
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

void reactOnHTTPCall(String message) {
  Serial.println(message);
}

void refreshLED() {

}
