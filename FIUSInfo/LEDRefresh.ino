
String textToDisplay;
long lastRefresh;
int lastChar;
int emptyTicksRemaining;

void refreshLED() {

  if ((1000 / textSpeed) + lastRefresh < millis()) {
    /*Perform refresh*/
    lastRefresh = millis();

    /*Insert new char if needed*/
    insertChar();

    /*Shift the whole text one collumn to the left*/
    for (int i = 1; i < LED_WIDTH + FONT_WIDTH - 1; i++) {
      int firstIndexOfCollumn;
      if (i % 2 == 0) {
        firstIndexOfCollumn = i * LED_HEIGTH;
        for (int j = 0; j < LED_HEIGTH; j++) {
          leds[firstIndexOfCollumn - (1 + j)] = leds[firstIndexOfCollumn + j];
        }
      } else {
        firstIndexOfCollumn = (i + 1) * LED_HEIGTH - 1;
        for (int j = 0; j < LED_HEIGTH; j++) {
          leds[firstIndexOfCollumn - ((LED_HEIGTH * 2 - 1) - j)] = leds[firstIndexOfCollumn - j];
        }
      }
    }

    /*Display changes*/
    FastLED.show();

  }

}


void insertChar() {
  if (lastChar == 0) {

    int startIndex = LED_WIDTH * LED_HEIGTH;
    if (textToDisplay == "") {

      if (emptyTicksRemaining > 0) {
        /*The text is completly displayed, but empty space is inserted*/
        emptyTicksRemaining--;
        for (int i = 0; i < FONT_WIDTH * LED_HEIGTH; i++) {

          leds[startIndex + i] = CRGB::Black;

        }
        return;
      }
      /*The text is completly displayed, display it again*/
      textToDisplay = text;
      emptyTicksRemaining = emptyTicks;
    }
    lastChar = FONT_WIDTH + 1;
    char nextChar = textToDisplay.charAt(0);
    textToDisplay = textToDisplay.substring(1);

    /*Spawn new character*/
    for (int i = 0; i < FONT_WIDTH * LED_HEIGTH; i++) {
      if (font[nextChar][i] == 1) {
        leds[startIndex + i - 16] = color;
      } else {
        leds[startIndex + i - 16] = CRGB::Black;
      }
    }

  }
  if (isActive) {
    lastChar--;
  }
}
