
String textToDisplay;
long lastRefresh;
int lastChar;
int emptyTicksRemaining;
int hue;
void refreshLED() {

  if (textSpeed + lastRefresh < millis()) {
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
    int nextChar = 0;
    if (textToDisplay.startsWith("/smile")) {
      textToDisplay = textToDisplay.substring(5);
      nextChar = 250;
    } else if (textToDisplay.startsWith("/ae")) {
      textToDisplay = textToDisplay.substring(2);
      nextChar = 228;
    } else if (textToDisplay.startsWith("/oe")) {
      textToDisplay = textToDisplay.substring(2);
      nextChar = 246;
    } else if (textToDisplay.startsWith("/ue")) {
      textToDisplay = textToDisplay.substring(2);
      nextChar = 252;
    } else if (textToDisplay.startsWith("/AE")) {
      textToDisplay = textToDisplay.substring(2);
      nextChar = 196;
    } else if (textToDisplay.startsWith("/OE")) {
      textToDisplay = textToDisplay.substring(2);
      nextChar = 214;
    } else if (textToDisplay.startsWith("/UE")) {
      textToDisplay = textToDisplay.substring(2);
      nextChar = 220;
    }  else {
      nextChar = textToDisplay.charAt(0);
    }


    textToDisplay = textToDisplay.substring(1);

    /*Spawn new character*/
    for (int i = 0; i < FONT_WIDTH * LED_HEIGTH; i++) {
      if (font[nextChar][i] > 0) {

        if (animationType == 0) {
          if (font[nextChar][i] == 1) {
            leds[startIndex + i - 16] = color;
          } else {
            CHSV hsv(font[nextChar][i], 255, 100);
            CRGB rgb;
            hsv2rgb_rainbow( hsv, rgb);
            leds[startIndex + i - 16] = rgb;
          }
        } else {
          CHSV hsv( hue, 255, 100);
          CRGB rgb;
          hsv2rgb_rainbow( hsv, rgb);
          leds[startIndex + i - 16] = rgb;
        }
      } else {
        leds[startIndex + i - 16] = CRGB::Black;
      }
    }
    hue += 20;
    hue %= 256;
  }
  if (isActive) {
    lastChar--;
  }
}
