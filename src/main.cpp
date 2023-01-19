#include <Arduino.h>
#define LED_PIN 5
#define LED_NUM 100
#include <FastLED.h>

CRGB leds[LED_NUM];

int counter = 0;
int col_b;
int col_r;
int col_g;
byte combi = 0;
byte combi1 = 1;
byte combi2 = 0;
int uskor =1;
bool c_flag = true;
bool combi_flag = true;
byte bright = 64;
bool test = false;
bool stars = false;
byte counterbyte;
struct test_st
{
  byte b1;
  byte b2;
  byte b3;
};
test_st t;



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


void debug()   {
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
  Serial.print(" t.b1:");
  Serial.print(t.b1);
  Serial.print(" t.b2:");
  Serial.print(t.b2);
  Serial.print(" t.b3:");
  Serial.print(t.b3);
  Serial.print("   ");


  // End Debug
  }  

void setup() {
  Serial.begin(921600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LED_NUM);
  FastLED.setBrightness(20);
  Serial.println("SETUP! Success!");
 //Serial.print("[31;40m");
}

void loop() {

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
          col_b = bright+sin(i/10)*bright;
          col_r = bright+sin(i+counter/10)*bright;
          col_g = bright+cos(i+counter/10)*bright;
          //if (c_flag) col_g=col_r; else col_g=col_b;
          select_anim (combi1);

          leds[i] = col_b+(col_r<<8)+(col_g<<16);
          //Serial.print(" ");
          //Serial.print(col_b);
          } 
    
    for (int i=counter;i<=LED_NUM;i++) 
        {
          col_b = bright+sin(i/10-counter/10)*bright;
          col_r = bright+cos(i/10+counter/10)*bright;
          col_g = bright+cos(i/10)*bright;
          //if (c_flag) col_g=col_b; else col_g=col_r;
          select_anim (combi);
 
          leds[i] = col_b+(col_r<<8)+(col_g<<16);
          //Serial.print(" ");
          //Serial.print(col_b);
          } 
    // Stars
    if (stars) {       
      for (int i=0;i<=10;i++)   {
          leds[random(LED_NUM)] = 128+(128<<8)+(128<<16);
            }
        }   //end start  
      
        //For test brightness     
      if (test) {
         for (int i=0;i<=LED_NUM;i++) 
          { //if (counterbyte<=)
            
            //leds[i] = col_b+(col_r<<8)+(col_g<<16);} 
            leds[i] = i+(i<<8)+(i<<16);} 
                }
        // end test brightness
  FastLED.show();
   //delay(100);
  debug();
  FastLED.clear();
  counterbyte++;
  t.b2++;

}