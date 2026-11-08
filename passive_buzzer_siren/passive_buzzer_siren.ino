const int buzzerPin = 9;

void setup() {

}

void loop() {
  for (int freq = 100; freq <= 1000; freq += 10) {
    tone(buzzerPin, freq);
    delay(20);
  }
  for (int freq = 1000; freq >= 1000; freq -= 10) {
    tone(buzzerPin, freq);
    delay(20);
  }
}