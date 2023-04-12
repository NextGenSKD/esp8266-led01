#include <Arduino.h>
#define LED_PIN 5
#define LED_NUM 100
#include <FastLED.h>

CRGB leds[LED_NUM];
struct led_RGB
{
  byte r;
  byte g;
  byte b;
};



byte led_tentacle = 9;
byte led_tentacle_l = 11;
byte led_q = 0;
int counter = 0;
int col_b = 64;
int col_r = 128;
int col_g = 32;
int bright = 32;
led_RGB scr1[12][10];






void select_anim (byte combix)
{
          if (combix == 0) {};
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
  Serial.print("   ");
  Serial.print("Led_q:");
   Serial.print(led_q);
   Serial.print("   ");
 

  // End Debug
  }  

void pulsator()

{
    if (counter < 180)
    {
      for (int i=0;i<=LED_NUM;i++)

      {
          col_b = 64+sin(i*100+counter)*bright;
          col_r = 64+cos(i*100+counter)*bright;
          col_g = 0;
        leds[i] = col_b+(col_r<<8)+(col_g<<16);}
    }
    else {
    //col_b = bright+sin(led_q/10)*bright;
    //col_r = bright+cos(led_q/10)*bright;
    //col_g = 0;
    //select_anim(led_q);

    counter = 0; 
    if (led_q<=180) {led_q++;} else {led_q=0;}
     }

}
void roller()

{
//print_pixels
byte rnd = random(10);
int x = 0;
int y = random(led_tentacle);
if (rnd==1) {
       scr1[x][y].b = 120;
       scr1[x][y].r = 120;
       scr1[x][y].g = 0;
} 
if (rnd==2) {
       scr1[x][y].b = 120;
       scr1[x][y].r = 80;
       scr1[x][y].g = 0;
}

if (rnd==3) {
       scr1[x][y].b = 80;
       scr1[x][y].r = 120;
       scr1[x][y].g = 0;
}
  
 // scroll

for (int x=led_tentacle_l;x>0;x--)
    {
      
      for (int y=0;y<=led_tentacle;y++)
      { 
       byte led_r = scr1[x-1][y].r;
       byte led_g = scr1[x-1][y].g;
       byte led_b = scr1[x-1][y].b;   
       scr1[x][y].b = led_b;
       scr1[x][y].r = led_r;
       scr1[x][y].g = led_g;
        if (led_r > 20) led_r-=20; else led_r=0;
        if (led_g > 20) led_g-=20; else led_g=0;
        if (led_b > 40) led_b-=20; else led_b=20;
       scr1[x-1][y].b = led_b;
       scr1[x-1][y].r = led_r;
       scr1[x-1][y].g = led_g;
       
        }
    
    }


//print_to_led
for (int y=0;y<=led_tentacle;y++) 
      {
        for (int x=0;x<=led_tentacle_l;x++)
        {
          leds[y*led_tentacle+x] = ((scr1[x][y].b)+(scr1[x][y].r<<8)+(scr1[x][y].g<<16));
        }

}





}

void setup() {
  Serial.begin(921600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LED_NUM);
  FastLED.setBrightness(20);
  Serial.println("\r SETUP Success!");
 //init masive
for (int x=0; x<=led_tentacle_l; x++) 
      {
        for (int y=0;y<=led_tentacle; y++)
        {
          scr1[x][y].r = 0;
          scr1[x][y].g = 0;
          scr1[x][y].b = 20;
        }

      }


}

void loop() {


  //pulsator();


      
//for (byte i=0; i<=led_tentacle_l;i++)
 roller();


  FastLED.show();
  delay(50);
  debug();
  //FastLED.clear();
  counter++;
  

}