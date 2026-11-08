const int A1B = 5;
const int A1A = 6;
const int B1B = 9;
const int B1A = 10;

void setup() {
  pinMode(A1B, OUTPUT);
  pinMode(A1A, OUTPUT);
  pinMode(B1B, OUTPUT);
  pinMode(B1A, OUTPUT);
}

void loop() {
  for (int speed = 130; speed <= 255; speed += 5) {
    moveForward(speed);
    delay(100);
  }
  stop();
  delay(1000);
  for (int speed = 255; speed >= 130; speed -= 5) {
    moveForward(speed);
    delay(100);
  }
  stop();
  delay(1000);
}

void moveForward(int speed) {
  analogWrite(A1B, speed);
  analogWrite(A1A, 0);
  analogWrite(B1B, 0);
  analogWrite(B1A, speed);
}

void stop() {
  analogWrite(A1B, 0);
  analogWrite(A1A, 0);
  analogWrite(B1B, 0);
  analogWrite(B1A, 0);
}