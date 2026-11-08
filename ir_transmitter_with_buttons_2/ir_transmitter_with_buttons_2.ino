#include <IRremote.h>

const int btn1 = 5;
const int btn2 = 6;
const int btn3 = 7;

void setup() {
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
}

void loop() {
  int btn1Val = digitalRead(btn1);
  int btn2Val = digitalRead(btn2);
  int btn3Val = digitalRead(btn3);
  
  if (btn1Val == LOW) {
    IrSender.sendNEC(0x18, 32);
  }
  if (btn2Val == LOW) {
    IrSender.sendNEC(0x18, 32);
  }
  if (btn3Val == LOW) {
    IrSender.sendNEC(0x18, 32);
  }
}
