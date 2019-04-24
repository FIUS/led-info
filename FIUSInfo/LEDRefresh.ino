
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
int emptyTicksRemaining;

void refreshLED() {

  if ((1000 / textSpeed) + lastRefresh < millis()) {
    //Perform refresh
    lastRefresh = millis();

    for (int i = 1; i < LED_WIDTH + FONT_WIDTH - 1; i++) {
      int firstIndexOfCollumn = i * LED_HEIGTH;
      if (i % 2 == 0) {
        for (int j = 0; j < LED_HEIGTH; j++) {
          Serial.println(firstIndexOfCollumn - (1 + 2 * j)+"<-"+firstIndexOfCollumn + j);
          leds[firstIndexOfCollumn - (1 + 2 * j)] = leds[firstIndexOfCollumn + j];
        }
      } else {
        for (int j = 0; j < LED_HEIGTH; j++) {
          Serial.println(firstIndexOfCollumn - ((LED_HEIGTH * 2 - 1) - 2 * j)+"<-"+firstIndexOfCollumn + j);
          leds[firstIndexOfCollumn - ((LED_HEIGTH * 2 - 1) - 2 * j)] = leds[firstIndexOfCollumn + j];
        }
      }
    }
    insertChar();
    FastLED.show();

  }

}


void insertChar() {
  if (lastChar == 0) {
    int startIndex = LED_WIDTH * LED_HEIGTH;
    if (textToDisplay == "") {
      if (emptyTicksRemaining > 0) {
        emptyTicksRemaining--;
        for (int i = 0; i < FONT_WIDTH * LED_HEIGTH; i++) {

          leds[startIndex + i] = CRGB::Black;

        }
        return;
      }
      textToDisplay = text;
      emptyTicksRemaining = emptyTicks;
    }
    lastChar = FONT_WIDTH;
    char nextChar = textToDisplay.charAt(0);
    textToDisplay = textToDisplay.substring(1);

    for (int i = 0; i < FONT_WIDTH * LED_HEIGTH; i++) {
      if (font[1][i]) {
        leds[startIndex + i] = color;
      } else {
        leds[startIndex + i] = CRGB::Black;
      }
    }

  }
  if (isActive) {
    lastChar--;
  }
}

