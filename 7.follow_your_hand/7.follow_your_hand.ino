const int A1B = 5;
const int A1A = 6;
const int B1B = 9;
const int B1A = 10;

const int trigPin = 3;
const int echoPin = 4;

const int rightIR = 7;
const int leftIR = 8;

void setup() {
  pinMode(A1B, OUTPUT);
  pinMode(A1A, OUTPUT);
  pinMode(B1B, OUTPUT);
  pinMode(B1A, OUTPUT);

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);
}

void loop() {
  float distance = readSensorData();

  int left = digitalRead(leftIR); // 0: Obstructed, false  1: Emptry, true
  int right = digitalRead(rightIR);
  int speed = 200;

  if (distance > 5 && distance < 10) {
    moveForward(speed);
  }
  else if (left == 0 && right == 1) { // hand at left
    backLeft(speed);
  }
  else if (left == 1 && right == 0) { // hand at right
    backRight(speed);
  }
  else {
    stop();
  }
}

float readSensorData() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); //sends out ultrasonic waves
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH); //pulseIn returns the time while echoPin is HIGH
  float distance = (duration * 0.0324) / 2; //formula to calculate distance
  Serial.println(distance);
  return distance;
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

void stop() {
  analogWrite(A1B, 0);
  analogWrite(A1A, 0);
  analogWrite(B1B, 0);
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