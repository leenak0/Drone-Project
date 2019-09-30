#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 7
#define vib 2
int red=0;

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 9

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(vib, INPUT);
  Serial.begin(9600); //시리얼통신 설정 9600
  Serial.println("----------------------vibration demo------------------------");
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  pixels.begin(); // strip을 선언하고
  pixels.show();  // 모든 LED를 끕니다.
}

void loop() {
  long measurement =TP_init();
  if(measurement > 5000){
    if(red==0){
      led_red();
      Serial.print("measurment = ");
      Serial.println(measurement);
      Serial.print("red = ");
      Serial.println(red);
      red++;
      }else if(red==1){
        led_blue();
        Serial.print("measurment = ");
        Serial.println(measurement);
        Serial.print("red = ");
        Serial.println(red);
        red--;
        }
        delay(500);
   }
   delay(50);
}

void led_red(){
  for(int i=0; i<NUMPIXELS; i++){pixels.setPixelColor(i, 255,0,0);}
  pixels.show();
}

void led_blue(){
  for(int i=0; i<NUMPIXELS; i++){pixels.setPixelColor(i, 0,0,255);}
  pixels.show();
}

long TP_init(){
  long measurement=pulseIn (vib, HIGH);
  return measurement;
}
