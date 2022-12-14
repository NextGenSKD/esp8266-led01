#include <Arduino.h>
#define LED_PIN 5
#define LED_NUM 100
#include "FastLED.h"

CRGB leds[LED_NUM];

void setup() {
  Serial.begin(921600);
  Serial.println("SETUP! Success!");
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LED_NUM);
  FastLED.setBrightness(50);
}
byte counter;
int colour1;
void loop() {
  FastLED.clear();
  Serial.print("\rCounter:");
  Serial.print(counter);
 // leds[counter] = 0xffff00;
 // leds[counter+1] = 0xff0000;
 // leds[counter+2] = 0x00ff00;
 // leds[counter+3] = 0x0000ff;
//  leds[counter+4] = 0xffff00;
 if (++counter >= LED_NUM) counter = 0;
//for (int o=0;o<=90;o++) 
 // {
//    colour1 = 128+sin(counter)*64;
//int colour1 = random(0xff);
    Serial.print("  Colour1: ");
    Serial.print(colour1);
    for (int i=counter;i<=LED_NUM;i++) 
        {
          colour1 = 128+sin(i*(3.2/LED_NUM)*128);
          leds[i] = i*3;
          //Serial.print(colour1);
          }
  FastLED.show();
  delay(100);
//  }
}