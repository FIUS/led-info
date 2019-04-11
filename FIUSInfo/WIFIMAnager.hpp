#pragma once

class LedStrip;

class WIFIManager {
  public:
    WIFIManager();
    String refreshPage();

  private:
    void Initialize();




    const CRGB red = CRGB(120, 0, 0);
    const CRGB green = CRGB(40, 120, 0);
    const CRGB spark = CRGB(255, 255, 0);
    const int sparkSize=5;
    const int lightSize=10; 
    LedStrip &strip;
    int cstate=0;
};
