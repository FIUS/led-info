/*const int LED_WIDTH = 32;
const int LED_HEIGTH = 8;
const int FONT_WIDTH = 5;
const int NUM_LEDS = LED_WIDTH * LED_HEIGTH + FONT_WIDTH * LED_HEIGTH;
const int ENDPOINT_COUNT = 8;

bool isActive = true;
String text = "";
//CRGB color = CRGB::White;
int animationType = 0;
double textSpeed = 0;
int leds[NUM_LEDS];*/
//----------------------------------------

String textToDisplay;
long lastRefresh;
int lastChar;

void refreshLED() {

  if ((1000 / textSpeed) + lastRefresh < millis()) {
    //Perform refresh
    lastRefresh = millis();
    if (textToDisplay == "") {
      textToDisplay = text;
    }
    for (int i = LED_HEIGTH; i < NUM_LEDS; i++) {
      leds[i - LED_HEIGTH] = leds[i];
    }
    insertChar();

  }
}

void insertChar() {
  if (lastChar == 0) {
    lastChar = FONT_WIDTH;
    char nextChar = textToDisplay.charAt(0);
    textToDisplay = textToDisplay.substring(1);
    int startIndex = LED_WIDTH * LED_HEIGTH;
    for (int i = 0; i < FONT_WIDTH * LED_HEIGTH; i++) {
      leds[startIndex + i] = font[1][i];
    }

  }
  if (isActive) {
    lastChar--;
  }
}

