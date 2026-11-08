int potPin = A0;
int LEDPin = 6;
int btnPin = 7;
int potVal;
int LEDState = LOW;
int lastButtonState = HIGH;

void setup() {
  pinMode(potPin, INPUT);
  pinMode(LEDPin, OUTPUT);
  pinMode(btnPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(btnPin);
  Serial.print(buttonState); //not working
  if (lastButtonState == HIGH && buttonState == LOW) {
    LEDState = !LEDState;
    analogWrite(LEDPin, 0);
  }
  if (LEDState == HIGH) {
    potVal = analogRead(potPin);
    analogWrite(LEDPin, potVal / 4);
  }
}