const int a = 220;
const int b = 247;
const int c = 262;
const int d = 294;
const int e = 330;
const int f = 350;
const int g = 392;

const int buzzerPin = 3;
const int btnAPin = 4;
const int btnBPin = 5;
const int btnCPin = 6;
const int btnDPin = 7;
const int btnEPin = 8;
const int btnFPin = 9;
const int btnGPin = 10;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(btnAPin, INPUT_PULLUP);
  pinMode(btnBPin, INPUT_PULLUP);
  pinMode(btnCPin, INPUT_PULLUP);
  pinMode(btnDPin, INPUT_PULLUP);
  pinMode(btnEPin, INPUT_PULLUP);
  pinMode(btnFPin, INPUT_PULLUP);
  pinMode(btnGPin, INPUT_PULLUP);
}

void loop() {
  int btnAState = digitalRead(btnAPin);
  int btnBState = digitalRead(btnBPin);
  int btnCState = digitalRead(btnCPin);
  int btnDState = digitalRead(btnDPin);
  int btnEState = digitalRead(btnEPin);
  int btnFState = digitalRead(btnFPin);
  int btnGState = digitalRead(btnGPin);

  if (btnAState == 0) {
    tone(buzzerPin, a);
  }
  else if (btnBState == 0) {
    tone(buzzerPin, b);
  }
  else if (btnCState == 0) {
    tone(buzzerPin, c);
  }
  else if (btnDState == 0) {
    tone(buzzerPin, d);
  }
  else if (btnEState == 0) {
    tone(buzzerPin, e);
  }
  else if (btnFState == 0) {
    tone(buzzerPin, f);
  }
  else if (btnGState == 0) {
    tone(buzzerPin, g);
  }
  else {
    noTone(buzzerPin);
  }
}