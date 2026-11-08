int potPin = A0;
int LEDPin = 6;
int potVal;

void setup() {
  pinMode(potPin, INPUT);
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  potVal = analogRead(potPin);
  analogWrite(LEDPin, potVal / 4);
}
