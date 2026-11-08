int LEDPin = 5;
int potPin = A0;
int potVal;

void setup() {
  pinMode(LEDPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  potVal = analogRead(potPin);
  analogWrite(LEDPin, potVal / 4);
}