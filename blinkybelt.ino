#include "FastLED.h"

#define DATA_PIN 4
#define NUM_LEDS 24
CRGB leds[20];

void setup() {
  // Register the lights
  FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  static uint8_t hue = 0;
  FastLED.showColor(CHSV(hue++, 255, 255));
  delay(10);
}
