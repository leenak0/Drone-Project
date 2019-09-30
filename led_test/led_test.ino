#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define vib 2
#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);
// strip이라는 네오픽셀 객체를 선언합니다. 60개의 네오픽셀과, PIN(D6)의 핀에 네오픽셀이 연결되었음을 선언합니다.
void setup() {
  pinMode(vib, INPUT); //센서핀 입력
  Serial.begin(9600); //시리얼통신 설정 9600
  Serial.println("----------------------vibration demo------------------------");
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  strip.begin(); // strip을 선언하고
  strip.show();  // 모든 LED를 끕니다.
}
void loop() {
  strip.setPixelColor(0, 255, 0, 0);  // 1번째의 LED에 빨 255, 초 0, 파 0을 출력합니다.
  long measurement =TP_init();
  delay(50);
  Serial.print("measurment = ");
  Serial.println(measurement);
  if (measurement > 1000){
    Serial.println("shock!!");
  }
  else{
    Serial.println("-");
  }
}
long TP_init(){
  delay(10);
  long measurement=pulseIn (vib, HIGH);
  return measurement;
}
