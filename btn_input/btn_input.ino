const int btnPin = 12;
const int buzzerPin = 3;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(btnPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  tone(buzzerPin, 400, 1000);

}