const int redPin = 6;
const int greenPin = 5;
const int bluePin = 3;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  analogWrite(redPin, random(256));
  analogWrite(greenPin, random(256));
  analogWrite(bluePin, random(256));
  delay(1000);
}