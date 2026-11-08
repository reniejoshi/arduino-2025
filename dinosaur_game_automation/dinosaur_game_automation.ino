#include <Servo.h>

const int ldrPin = A0;

Servo servo;

void setup() {
  pinMode(ldrPin, INPUT);

  servo.attach(9);
  
  Serial.begin(9600);
}

void loop() {
  int ldrVal = analogRead(ldrPin);
  Serial.println(ldrVal);
}
