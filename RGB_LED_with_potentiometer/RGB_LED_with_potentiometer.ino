int redPin = 5;
int greenPin = 6;
int bluePin = 7;
int potPin = A0;
int redVal;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  redVal = analogRead(potPin);
  setColor(redVal, 0, 0); //random(256), random(256));
  delay(100);
}

void setColor(int redVal, int greenVal, int blueVal) {
  analogWrite(redPin, redVal);
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, blueVal);
}