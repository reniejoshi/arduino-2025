#include <IRremote.h>

const int btn1 = 5;
const int btn2 = 6;
const int btn3 = 7;

void setup() {
  Serial.begin(9600);
  IrSender.begin(3, ENABLE_LED_FEEDBACK, USE_DEFAULT_FEEDBACK_LED_PIN);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
}

void loop() {
  
  if (digitalRead(btn1) == LOW) {
    IrSender.sendNECMSB(0x18, 8);
    Serial.println("Code sent!");
    delay(30);
  }
  else if (digitalRead(btn2) == LOW) {
    IrSender.sendNECMSB(0x52, 8);
    Serial.println("Code sent!");
    delay(30);
  } 
  else if (digitalRead(btn3) == LOW) {
    IrSender.sendNECMSB(0x9, 8);
    Serial.println("Code sent!");
    delay(30);
  } 
  else {
    Serial.println("Nothing to send");
    delay(30);
  } 
}

void loop() {
  uint8_t sAddress = 0x02;
  uint8_t sCommand = 0x34;
  uint8_t sRepeats = 0;

  sendNEC(3, sAddress, sCommand, sRepeats, true);
}