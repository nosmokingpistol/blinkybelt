#include "FastLED.h"

#define DATA_PIN 4
#define NUM_LEDS 24
CRGB leds[NUM_LEDS];

void setup() {
  // Register the lights
  FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  rainbowPulse();
}

void rainbowPulse() {
  static uint8_t hue = 0;
  FastLED.showColor(CHSV(hue++, 255, 255));
  delay(10);
}

void epileptic() {
  static uint8_t hue = 0;
  for(int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CHSV(hue++, 255, 255);
  }
  LEDS.show();
  delay(20);
}


void flame() {
  //-m22-FLAMEISH EFFECT
  int idelay = random(0,35);
  float hmin = 0.1; float hmax = 45.0;
  float hdif = hmax-hmin;
  int randtemp = random(0,3);
  float hinc = (hdif/float(NUM_LEDS/2))+randtemp;
  int ihue = hmin;
  for(int i = 0; i <= NUM_LEDS; i++ ) {
    ihue = ihue + hinc;
    leds[i] = CHSV(ihue, 255, 255);
    LEDS.show();    
    delay(idelay);
  }
}

void cylon() {
    // First slide the led in one direction
  for(int i = 0; i < NUM_LEDS; i++) {
    // Set the i'th led to red 
    leds[i] = CRGB::Red;
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    leds[i] = CRGB::Black;
    // Wait a little bit before we loop around and do it again
    delay(30);
  }

  // Now go in the other direction.  
  for(int i = NUM_LEDS-1; i >= 0; i--) {
    // Set the i'th led to red 
    leds[i] = CRGB::Red;
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    leds[i] = CRGB::Black;
    // Wait a little bit before we loop around and do it again
    delay(30);
  }
}

