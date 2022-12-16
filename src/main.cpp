#include <Arduino.h>
#define LED_PIN 5
#define LED_NUM 100
#include <FastLED.h>

CRGB leds[LED_NUM];

byte counter = 0;
int col_b;
int col_r;
int col_g;
byte combi = 0;
byte combi1 = 1;
byte combi2 = 0;
int uskor =1;
bool c_flag = true;
bool combi_flag = true;

void select_anim (byte combix)
{
          if (combix == 1) {col_b=0;};
          if (combix == 2) {col_r=0;};
          if (combix == 3) {col_g=0;};
          if (combix == 4) {col_b=0; col_r=0;};
          if (combix == 5) {col_g=0; col_r=0;};
          if (combix == 6) {col_b=0; col_g=0;};
          if (combix == 7) {col_b=0; col_g=0; col_r=128;};
          if (combix == 8) {col_b=0; col_g=128; col_r=0;};
          if (combix == 9) {col_b=128; col_g=0; col_r=0;};
          if (combix == 10) {col_b=128; col_g=0; col_r=128;};
          if (combix == 11) {col_b=128; col_g=128; col_r=0;};
          if (combix == 12) {col_b=128; col_g=0; col_r=128;};
          if (combix == 13) {col_b=128; col_g=128; col_r=128;};
}

void setup() {
  Serial.begin(921600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LED_NUM);
  FastLED.setBrightness(50);
  Serial.println("SETUP! Success!");
}

void loop() {
  // Debug info
  Serial.print("\r Counter:");
  Serial.print(counter);
  Serial.print(" c_flag:");
  Serial.print(c_flag);
  Serial.print(" combi:");
  Serial.print(combi);
  Serial.print(" combi1:");
  Serial.print(combi1);
  Serial.print(" combi2:");
  Serial.print(combi2);
  Serial.print(" combi_flag:");
  Serial.print(combi_flag);
  Serial.print(" uskor:");
  Serial.print(uskor);
  Serial.print("   ");
  // End Debug  
 uskor = abs (sin(counter)*5);
 if (counter>= LED_NUM) {c_flag=false; combi=combi2;  combi2=random(13);}
 if (counter<= 0) {c_flag=true; combi1=combi2; combi=combi; combi2=random(13);}
 if (c_flag) counter+=2;  else counter-=2;
 //if (combi>= 6) combi_flag=false; 
 //if (combi== 0) combi_flag=true;
   //  Serial.print("  col_b: ");
  //  Serial.print(col_b);
    for (int i=0;i<=counter;i++) 
        {
          col_b = 128+sin(i/10)*100;
          col_r = 128+sin(i+counter/10)*100;
          col_g = 128+cos(i+counter/10)*100;
          //if (c_flag) col_g=col_r; else col_g=col_b;
          select_anim (combi1);

          leds[i] = col_b+(col_r<<8)+(col_g<<16);
          //Serial.print(" ");
          //Serial.print(col_b);
          } 
    
    for (int i=counter;i<=LED_NUM;i++) 
        {
          col_b = 128+sin(i+counter/10)*100;
          col_r = 128+cos(i+counter/10)*100;
          col_g = 128+cos(i/10)*100;//if (c_flag) col_g=col_b; else col_g=col_r;
          select_anim (combi);
 
          leds[i] = col_b+(col_r<<8)+(col_g<<16);
          //Serial.print(" ");
          //Serial.print(col_b);
          }
          
        /*
        //For test brightness     
        for (int i=0;i<=LED_NUM;i++) 
          { int col = 120+sin(i)*64;
            leds[i] = 0+(col<<8)+(0<<16);} 
        // */
  FastLED.show();
  delay(100);
  FastLED.clear();
}