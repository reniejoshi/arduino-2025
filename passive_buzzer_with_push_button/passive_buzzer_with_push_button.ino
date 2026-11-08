const int btn1Pin = 2;
const int btn2Pin = 3;
const int buzzerPin = 9;

void setup() {
  pinMode(btn1Pin, INPUT_PULLUP);
  pinMode(btn2Pin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int btn1State = digitalRead(btn1Pin);
  int btn2State = digitalRead(btn2Pin);

  if (btn1State == 0) {
    tone(buzzerPin, 262, 500);
  }
  else if (btn2State == 0) {
    tone(buzzerPin, 330, 500);
  }
  else {
    noTone(buzzerPin);
  }
}
