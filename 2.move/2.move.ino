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
  moveForward();
  delay(1000);
  turnLeft();
  delay(200);
  moveForward();
  delay(1000);
  turnRight();
  delay(200);
  moveBackward();
  delay(1000);
  stop();
  delay(2000);
}

void moveForward() {
  digitalWrite(A1B, HIGH);
  digitalWrite(A1A, LOW);
  digitalWrite(B1B, LOW);
  digitalWrite(B1A, HIGH);
}

void moveBackward() {
  digitalWrite(A1B, LOW);
  digitalWrite(A1A, HIGH);
  digitalWrite(B1B, HIGH);
  digitalWrite(B1A, LOW);
}

void turnLeft() {
  digitalWrite(A1B, LOW);
  digitalWrite(A1A, HIGH);
  digitalWrite(B1B, LOW);
  digitalWrite(B1A, HIGH);
}

void turnRight() {
  digitalWrite(A1B, HIGH);
  digitalWrite(A1A, LOW);
  digitalWrite(B1B, HIGH);
  digitalWrite(B1A, LOW);
}

void stop() {
  digitalWrite(A1B, LOW);
  digitalWrite(A1A, LOW);
  digitalWrite(B1B, LOW);
  digitalWrite(B1A, LOW);
}