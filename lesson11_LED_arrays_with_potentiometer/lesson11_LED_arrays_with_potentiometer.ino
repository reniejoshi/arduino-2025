int LED1 = 9;
int LED2 = 10;
int LED3 = 11;
int potPin = A0;
int potVal;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  potVal = analogRead(potPin);
  if (potVal <= 258) {
    analogWrite(LED1, 0);
    analogWrite(LED2, 0);
    analogWrite(LED3, 0);
  }
  else if (potVal <= 513) {
    analogWrite(LED1, potVal - 258);
    analogWrite(LED2, 0);
    analogWrite(LED3, 0);
  }
  else if (potVal <= 768) {
    analogWrite(LED1, 255);
    analogWrite(LED2, potVal - 513);
    analogWrite(LED3, 0);
  }
  else if (potVal <= 1023) {
    analogWrite(LED1, 255);
    analogWrite(LED2, 255);
    analogWrite(LED3, potVal - 768);
  }
}
