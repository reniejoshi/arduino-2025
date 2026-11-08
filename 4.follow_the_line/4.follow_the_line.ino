const int A1B = 5;
const int A1A = 6;
const int B1B = 9;
const int B1A = 10;
const int lineTrack = 2;

void setup() {
  pinMode(A1B, OUTPUT);
  pinMode(A1A, OUTPUT);
  pinMode(B1B, OUTPUT);
  pinMode(B1A, OUTPUT);
  pinMode(lineTrack, INPUT);
}

void loop() {
  int speed = 255;

  int lineColor = digitalRead(lineTrack); // 0:white 1:black
  if (lineColor) { // lineColor == 1
    moveLeft(speed);
  }
  else {
    moveRight(speed);
  }
}

void moveLeft(int speed) {
  analogWrite(A1B, speed);
  analogWrite(A1A, 0);
  analogWrite(B1B, 0);
  analogWrite(B1A, 0);
}

void moveRight(int speed) {
  analogWrite(A1B, 0);
  analogWrite(A1A, 0);
  analogWrite(B1B, 0);
  analogWrite(B1A, speed);
}