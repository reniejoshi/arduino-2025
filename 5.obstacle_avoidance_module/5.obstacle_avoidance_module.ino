const int A1B = 5;
const int A1A = 6;
const int B1B = 9;
const int B1A = 10;

const int rightIR = 7;
const int leftIR = 8;

void setup() {
  pinMode(A1B, OUTPUT);
  pinMode(A1A, OUTPUT);
  pinMode(B1B, OUTPUT);
  pinMode(B1A, OUTPUT);

  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);
}

void loop() {
  int left = digitalRead(leftIR); // 0: Obstructed, false  1: Emptry, true
  int right = digitalRead(rightIR);
  int speed = 200;

  if (left == 0 && right == 1) { // obstacle at left
    moveBackward(speed);//backLeft(speed);
  }
  else if (left == 1 && right == 0) { // obstacle at right
    moveBackward(speed);//backRight(speed);
  }
  else if (left == 0 && right == 0) { // obstacle at left and right
    moveBackward(speed);
  }
  else { // no obstacle
    moveForward(speed);
  }
}

void moveForward(int speed) {
  analogWrite(A1B, speed);
  analogWrite(A1A, 0);
  analogWrite(B1B, 0);
  analogWrite(B1A, speed);
}

void moveBackward(int speed) {
  analogWrite(A1B, 0);
  analogWrite(A1A, speed);
  analogWrite(B1B, speed);
  analogWrite(B1A, 0);
}

void backLeft(int speed) {
  analogWrite(A1B, 0);
  analogWrite(A1A, speed);
  analogWrite(B1B, 0);
  analogWrite(B1A, 0);
}

void backRight(int speed) {
  analogWrite(A1B, 0);
  analogWrite(A1A, 0);
  analogWrite(B1B, speed);
  analogWrite(B1A, 0);
}