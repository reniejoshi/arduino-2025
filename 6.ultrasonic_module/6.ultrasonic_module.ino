const int A1B = 5;
const int A1A = 6;
const int B1B = 9;
const int B1A = 10;

const int trigPin = 3;
const int echoPin = 4;

void setup() {
  pinMode(A1B, OUTPUT);
  pinMode(A1A, OUTPUT);
  pinMode(B1B, OUTPUT);
  pinMode(B1A, OUTPUT);

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float distance = readSensorData();
  if (distance > 25) {
    moveForward(200);
  }
  else if (distance < 10 && distance > 2) {
    moveBackward(200);
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