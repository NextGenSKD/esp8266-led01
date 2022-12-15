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
byte counter = 0;
int colour1;
int colour2;
int colour3;
byte combi = 0;
int uskor =1;
bool c_flag = true;
bool combi_flag = true;
void loop() {
  FastLED.clear();
  Serial.print("\rCounter:");
  Serial.print(counter);
  Serial.print(" c_flag:");
  Serial.print(c_flag);
  Serial.print(" combi:");
  Serial.print(combi);
  Serial.print(" combi_flag:");
  Serial.print(combi_flag);
  Serial.print(" uskor:");
  Serial.print(uskor);
  uskor = abs (sin(counter)*5);
 // leds[counter] = 0xffff00;
 // leds[counter+1] = 0xff0000;
 // leds[counter+2] = 0x00ff00;
 // leds[counter+3] = 0x0000ff;
//  leds[counter+4] = 0xffff00;
 if (counter>= LED_NUM) {c_flag=false; if (combi_flag) combi=random(6);}//combi++;  else combi--;}
 if (counter<= 0) {c_flag=true;}
 if (c_flag) counter+=2;  else counter-=2;
 if (combi>= 6) combi_flag=false; 
 if (combi== 0) combi_flag=true;
 
 

//for (int o=0;o<=90;o++) 
 // {
//    colour1 = 128+sin(counter)*64;
//int colour1 = random(0xff);
    Serial.print("  Colour1: ");
    Serial.print(colour1);
    for (int i=counter;i<=LED_NUM;i++) 
        {
          colour1 = 100+sin(i+counter/5)*100;
          colour2 = 100+cos(i+counter/5)*100;
          if (c_flag) colour3=colour1; else colour3=colour2;
          if (combi == 1) {colour1=0;};
          if (combi == 2) {colour2=0;};
          if (combi == 3) {colour3=0;};
          if (combi == 4) {colour1=0; colour2=0;};
          if (combi == 5) {colour3=0; colour2=0;};
          if (combi == 6) {colour1=0; colour3=0;};
//          if (combi == 7) {colour=0; colour2=0};
 //         if (combi == 8) {colour1=0; colour2=0};


          leds[i] = colour1+(colour2<<8)+(colour3<<16);//i*3<<16;//random(3);
          //Serial.print(" ");
          //Serial.print(colour1);
          }
  FastLED.show();
  delay(100);
//  }
}