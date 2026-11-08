int LEDPin = 5;
int potPin = A0;
int btnPin = 4;
int potVal;
int btnState;
int prevBtnState = HIGH;
int LEDState = LOW;

void setup() {
  pinMode(LEDPin, OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(btnPin, INPUT_PULLUP);
}

void loop() {
  btnState = digitalRead(btnPin); // LOW means btn is pressed, HIGH means btn is NOT pressed
  if (btnState == LOW && prevBtnState == HIGH) {
    LEDState = !LEDState;
  }
  prevBtnState = btnState;

  if (LEDState == HIGH) {
    potVal = analogRead(potPin);
    analogWrite(LEDPin, potVal / 4);
  }
  else if (LEDState == LOW) {
    analogWrite(LEDPin, 0);
  }

  // When btn is pressed once, the LED should turn on, but when the btn is pressed once again, the LED is turned off, and so on.
}