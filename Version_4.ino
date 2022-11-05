// C++ code
//
#include <WS2812FX.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define PIN2 8
#define LED_COUNT 8    

#define LED_PIN 6
#define LED_PIN2 8

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(LED_COUNT, PIN2, NEO_GRB + NEO_KHZ800);
WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
WS2812FX ws2812fx2 = WS2812FX(LED_COUNT, LED_PIN2, NEO_GRB + NEO_KHZ800);

#define Solenoid_borttagen1 2
#define Solenoid1 3
#define Solenoid2 4
#define Solenoid3 5
#define Solenoid_borttagen2 12
#define Solenoid4 11
#define Solenoid5 10
#define Solenoid6 9
#define Button 7
#define Button_test 15
int buttonOld;
int prevButtonState;
int s;
int Solenoids;
int antal = 0;
int RandomSolenoid;
int dt = 500;
int lednr;
int start_delay = 5000;

int testmode = 0;

void setup(){

Serial.begin(9600);
Serial.println("ledidle");
pinMode(Solenoid1, OUTPUT);
pinMode(Solenoid2, OUTPUT);
pinMode(Solenoid3, OUTPUT);
pinMode(Solenoid4, OUTPUT);
pinMode(Solenoid5, OUTPUT);
pinMode(Solenoid6, OUTPUT);

pinMode(Button, INPUT_PULLUP);
pinMode(Button_test, INPUT_PULLUP);
digitalWrite(Solenoid1,LOW);
digitalWrite(Solenoid2,LOW);
digitalWrite(Solenoid3,LOW);
digitalWrite(Solenoid4,LOW);
digitalWrite(Solenoid5,LOW);
digitalWrite(Solenoid6,LOW);



  ws2812fx.init();
  ws2812fx.setBrightness(100);
  ws2812fx.setSpeed(200);
  ws2812fx.setMode(11);
  ws2812fx.start();

  ws2812fx2.init();
  ws2812fx2.setBrightness(100);
  ws2812fx2.setSpeed(200);
  ws2812fx2.setMode(11);
  ws2812fx2.start();
}



void loop(){


ledidle();

Solenoids_reset();


int buttonState = digitalRead(Button);
int buttonStatetest = digitalRead(Button_test);


Serial.println(buttonStatetest);


if(buttonStatetest == LOW) {
  test_loop();
}
    
if(buttonState==LOW){
  ledstart();
  Serial.println("ledstart");
  delay(start_delay);
  int Solenoids[] = {Solenoid1, Solenoid2, Solenoid3, Solenoid4, Solenoid5, Solenoid6};
  
      
  
   
  
    while (antal < 4){
      RandomSolenoid = random(0,6); 
      if (Solenoids[RandomSolenoid] != 0){
        digitalWrite(Solenoids[RandomSolenoid],HIGH);
        ledstop(RandomSolenoid);
        delay(dt);
        digitalWrite(Solenoids[RandomSolenoid],LOW);  
        delay(random(1000,2500));
        antal += 1;
        Solenoids[RandomSolenoid] = 0;  
        }       
    } 
    Serial.println("ledidle");  
    } 
}

   


void ledstop(int lednr){
  Serial.println(lednr);
  int lednr1;
  int lednr2;
  
  Serial.println("ledstop");
  if (lednr <= 2) {
    lednr1 = lednr * 2 + 2;
    lednr2 = lednr1 + 1;
    pixels.setPixelColor(lednr1, pixels.Color(300,0,0));
    pixels.setPixelColor(lednr2, pixels.Color(300,0,0));  
    pixels.show();  
  }
  else {
    lednr = lednr;
    lednr1 = lednr + lednr - 4;
    lednr2 = lednr1 + 1;
    pixels2.setPixelColor(lednr1, pixels2.Color(300,0,0));
    pixels2.setPixelColor(lednr2, pixels2.Color(300,0,0));  
    pixels2.show();  
  }  
}

void ledstart(){
  for(int i=0;i<LED_COUNT;i++){
     // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(0,300,0)); 
      pixels.show();
      pixels2.setPixelColor(i, pixels.Color(0,300,0)); 
      pixels2.show();   
  }
}
void ledidle(){
  pixels.begin(); // This initializes the NeoPixel library.
  pixels2.begin(); // This initializes the NeoPixel library.
  
  ws2812fx.service();
  ws2812fx2.service();
}

void Solenoids_reset(){
  
  antal = 0;
  int i =0;
 
  return i;
  return antal;
}

void test_loop(){
int Solenoids[] = {Solenoid1, Solenoid2, Solenoid3, Solenoid4, Solenoid5, Solenoid6};
ledstart();
  while (antal < 6){
      
      if (Solenoids[antal] != 0){
        digitalWrite(Solenoids[antal],HIGH);
        ledstop(antal);
        delay(dt);
        digitalWrite(Solenoids[antal],LOW);  
        delay(1000);
        Solenoids[antal] = 0;
        antal += 1;
        } 

  }



}
