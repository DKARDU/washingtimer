#include <TM1637Display.h>
#define trig_pin 11
#define echo_pin 10
#define CLK 6
#define DIO 7
#define buzzer 8
long duration;
float cm;
const uint8_t Clear[] = {0, 0, 0, 0};

TM1637Display display(CLK, DIO);
void setup(){ 
  
  pinMode(trig_pin, OUTPUT); 
  pinMode(echo_pin, INPUT); 
  pinMode(buzzer,OUTPUT); 
  display.setBrightness(4);
  display.setSegments(Clear);


}
void countdown() {
  for(int i=29; i>=0; i--) {
    display.showNumberDec(i, true, 2, 2);
    delay(1000);
  }
}

void loop() {
    digitalWrite(trig_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10);
    duration = pulseIn(echo_pin, HIGH);
    cm = duration * 0.034 /2;
  if (cm < 8 && cm >= 1) {
      tone(8,800,40);
      countdown();
      tone(8,800,40);
      display.setSegments(Clear);
  }
}




  
