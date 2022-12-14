#include <Arduino.h>
#define LED_PIN 5
#define LED_NUM 100
#include "FastLED.h"

CRGB leds[LED_NUM];

void setup() {
  Serial.begin(115200);
  Serial.println("SETUP! Success!");
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LED_NUM);
  FastLED.setBrightness(50);
}
byte counter;
void loop() {
  FastLED.clear();
  Serial.print("\r");
  Serial.print(counter);
  leds[counter] = CRGB::Red;
  if (++counter >= LED_NUM) counter = 0;
  FastLED.show();
  delay(30);
}