const int buzzerPin = 3;
const int btnPins[] = {4, 5, 6, 7, 8, 9, 10};
const int keys[] = {220, 247, 262, 294, 330, 350, 392};
const int sizeOfBtnPins = sizeof(btnPins) / sizeof(btnPins[0]);

void setup() {
  pinMode(buzzerPin, OUTPUT);

  for (int i = 0; i < sizeOfBtnPins; i++) {
    pinMode(btnPins[i], INPUT_PULLUP);
  }
}

void loop() {
  int btnAState = digitalRead(btnPins[0]);
  int btnBState = digitalRead(btnPins[1]);
  int btnCState = digitalRead(btnPins[2]);
  int btnDState = digitalRead(btnPins[3]);
  int btnEState = digitalRead(btnPins[4]);
  int btnFState = digitalRead(btnPins[5]);
  int btnGState = digitalRead(btnPins[6]);

  if (btnAState == 0) {
    tone(buzzerPin, keys[0]);
  }
  else if (btnBState == 0) {
    tone(buzzerPin, keys[1]);
  }
  else if (btnCState == 0) {
    tone(buzzerPin, keys[2]);
  }
  else if (btnDState == 0) {
    tone(buzzerPin, keys[3]);
  }
  else if (btnEState == 0) {
    tone(buzzerPin, keys[4]);
  }
  else if (btnFState == 0) {
    tone(buzzerPin, keys[5]);
  }
  else if (btnGState == 0) {
    tone(buzzerPin, keys[6]);
  }
  else {
    noTone(buzzerPin);
  }
}