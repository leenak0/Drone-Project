#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 7
#define vib 2
bool red=true;

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
  delay(50);
  Serial.print("measurment = ");
  Serial.println(measurement);
  Serial.print("red = ");
  Serial.println(red);
  if(measurement > 1000){

    
    if(red==true){
    pixels.setPixelColor(0, 255,0,0);
    pixels.setPixelColor(1, 0,0,255);
    pixels.setPixelColor(2, 0,0,0);   // R,G,B의 색 표현
    pixels.setPixelColor(3, 0,255,0);   // R,G,B의 색 표현
    pixels.setPixelColor(4, 255,0,0);   // R,G,B의 색 표현
    pixels.setPixelColor(5, 0,0,255);   // R,G,B의 색 표현
    pixels.setPixelColor(6, 0,0,0);   // R,G,B의 색 표현
    pixels.setPixelColor(7, 0,255,0);   // R,G,B의 색 표현
    pixels.setPixelColor(8, 255,0,0);   // R,G,B의 색 표현
    pixels.setPixelColor(9, 0,0,0);   // R,G,B의 색 표현
    pixels.show();
    red=false;
    }else if(red==false){
      pixels.setPixelColor(0, 0,0,255);
    pixels.setPixelColor(1, 0,0,0);
    pixels.setPixelColor(2, 0,255,0);   // R,G,B의 색 표현
    pixels.setPixelColor(3, 255,0,0);   // R,G,B의 색 표현
    pixels.setPixelColor(4, 0,0,255);   // R,G,B의 색 표현
    pixels.setPixelColor(5, 0,0,0);   // R,G,B의 색 표현
    pixels.setPixelColor(6, 0,255,0);   // R,G,B의 색 표현
    pixels.setPixelColor(7, 255,0,0);   // R,G,B의 색 표현
    pixels.setPixelColor(8, 0,0,255);   // R,G,B의 색 표현
    pixels.setPixelColor(9, 0,0,0);   // R,G,B의 색 표현
    pixels.show();
    red=true;
    }
    delay(500);
  }
}

long TP_init(){
  delay(10);
  long measurement=pulseIn (vib, HIGH);
  return measurement;
}
