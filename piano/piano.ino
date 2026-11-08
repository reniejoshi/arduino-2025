const int buzzerPin = 3;
const int btnPins[] = {5, 6, 7, 8, 9, 10, 11};
const int keys[] = {220, 247, 262, 294, 330, 350, 392};
const int sizeOfBtnPins = sizeof(btnPins) / sizeof(btnPins[0]);

void setup() {
  pinMode(buzzerPin, OUTPUT);

  for (int i = 0; i < sizeOfBtnPins; i++) {
    pinMode(btnPins[i], INPUT_PULLUP);
  }
}

void loop() {
  int btnPinsState[8];
  for (int i = 0; i < sizeOfBtnPins; i++) {
    btnPinsState[i] = digitalRead(btnPins[i]);

    if (btnPinsState[i] == 0) { // btn pressed
      tone(buzzerPin, keys[i], 1000);
    }
    else {
      noTone(buzzerPin);
    }
  }
/*
  for (int i = 0; i < sizeOfBtnPins; i++) {
    int btnPinsState = digitalRead(btnPins[i]);

    if (btnPinsState == HIGH) { // btn pressed
      tone(btnPins[i], keys[i]);
      Serial.print(btnPins[i]);
      Serial.print(" is ");
      Serial.println(btnPinsState);
    }
  }*/
}