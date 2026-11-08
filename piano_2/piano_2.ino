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
  int btnsState[sizeOfBtnPins];
  bool isBtnsPressed = false;
  for (int i = 0; i < sizeOfBtnPins; i++) {
    btnsState[i] = digitalRead(btnPins[i]);

    if (btnsState[i] == 0) { // btn pressed
      isBtnsPressed = true;
      tone(buzzerPin, keys[i]);
    }
  }

  if (isBtnsPressed == false) {
    noTone(buzzerPin);
  }
}