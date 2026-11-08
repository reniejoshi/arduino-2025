#include <IRremote.h>

const int irReceiverPin = 12;

// motors
const int A1B = 5;
const int A1A = 6;
const int B1B = 9;
const int B1A = 10;

// line tracking module
const int lineTrack = 2;

// ultrasonic sensor
const int trigPin = 3;
const int echoPin = 4;

// IR obstacle avoidance modules
const int rightIR = 7;
const int leftIR = 8;

String function = "none";

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(irReceiverPin, ENABLE_LED_FEEDBACK); // Start the IR reciever

  pinMode(A1B, OUTPUT);
  pinMode(A1A, OUTPUT);
  pinMode(B1B, OUTPUT);
  pinMode(B1A, OUTPUT);

  pinMode(lineTrack, INPUT);

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);
}

void loop() {
  int speed = 150;

  if (IrReceiver.decode()) { // check for a completely recieved IR message
    String key = decodeKeyValue(IrReceiver.decodedIRData.command);

    if (key != "ERROR") {
      Serial.println(key);

      if (key == "+") {
        speed += 50;
      }
      else if (key == "-") {
        speed -= 50;
      }
      else if (key == "0") {
        stop();
      }
      else if (key == "2") {
        moveForward(speed);
        delay(1000);
      }
      else if (key == "1") {
        moveLeft(speed);
      }
      else if (key == "3") {
        moveRight(speed);
      }
      else if (key == "4") {
        turnLeft(speed);
      }
      else if (key == "6") {
        turnRight(speed);
      }
      else if (key == "7") {
        backLeft(speed);
      }
      else if (key == "9") {
        backRight(speed);
      }
      else if (key == "8") {
        moveBackward(speed);
        delay(1000);
      }
      else if (key == "CYCLE") {
        function = "follow the line";
      }
      else if (key == "U/SD") {
        function = "auto drive";
      }
      else if (key == "FORWARD") {
        function = "ultrasonic obstacle avoidance";
      }
      else if (key == "BACKWARD") {
        function = "ir obstacle avoidance";
      }
      else if (key == "EQ") {
        function = "follow your hand";
      }

      if (function == "follow the line") {
        followTheLine(speed);
      }
      else if (function == "auto drive") {
        autoDrive();
      }
      else if (function == "ultrasonic obstacle avoidance") {
        ultrasonicObstacleAvoidance();
      }
      else if (function == "ir obstacle avoidance") {
        irObstacleAvoidance();
      }
      else if (function == "follow your hand") {
        followYourHand();
      }

      if (speed >= 255) {
        speed = 255;
      }
      if (speed <= 0) {
        speed = 0;
      }
      delay(500);
      stop();

      IrReceiver.resume(); // Enable IR reciever to get next value
    }
  }
}

void followTheLine(int speed) {
  int lineColor = digitalRead(lineTrack); // 0:white 1:black

  if (lineColor) { // lineColor == 1
    moveLeft(speed);
  }
  else {
    moveRight(speed);
  }
}

void autoDrive(int speed) {
  int left = digitalRead(leftIR); // 0: Obstructed, false  1: Emptry, true
  int right = digitalRead(rightIR);
  
  if (left == 0 && right == 1) { // obstacle at left
    backLeft(speed);
  }
  else if (left == 1 && right == 0) { // obstacle at right
    backRight(speed);
  }
  else if (left == 0 && right == 0) { // obstacle at both left and right
    moveBackward(speed);
  }
  else {
    float distance = readSensorData();

    if (distance > 50) { // no obstacle yet
      moveForward(speed);
    }
    else if (distance < 10 && distance > 2) { // go around obstacle
      moveBackward(speed);
      delay(1000);
      backLeft(speed);
      delay(1000);
    }
    else {
      moveForward(speed);
    }
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

void ultrasonicObstacleAvoidance() {
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

void irObstacleAvoidance() {
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

void followYourHand() {
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
  analogWrite(A1B, speed);
  analogWrite(A1A, 0);
  analogWrite(B1B, 0);
  analogWrite(B1A, 0);
}

void backRight(int speed) {
  analogWrite(A1B, 0);
  analogWrite(A1A, 0);
  analogWrite(B1B, 0);
  analogWrite(B1A, speed);
}

void turnLeft(int speed) {
  analogWrite(A1B, 0);
  analogWrite(A1A, speed);
  analogWrite(B1B, 0);
  analogWrite(B1A, speed);
}

void turnRight(int speed) {
  analogWrite(A1B, speed);
  analogWrite(A1A, 0);
  analogWrite(B1B, speed);
  analogWrite(B1A, 0);
}

void moveLeft(int speed) {
  analogWrite(A1B, 0);
  analogWrite(A1A, speed);
  analogWrite(B1B, 0);
  analogWrite(B1A, 0);
}

void moveRight(int speed) {
  analogWrite(A1B, 0);
  analogWrite(A1A, 0);
  analogWrite(B1B, speed);
  analogWrite(B1A, 0);
}

String decodeKeyValue(long command)
{
  switch(command){
    case 0x16:
      return "0";
    case 0xC:
      return "1"; 
    case 0x18:
      return "2"; 
    case 0x5E:
      return "3"; 
    case 0x8:
      return "4"; 
    case 0x1C:
      return "5"; 
    case 0x5A:
      return "6"; 
    case 0x42:
      return "7"; 
    case 0x52:
      return "8"; 
    case 0x4A:
      return "9"; 
    case 0x9:
      return "+"; 
    case 0x15:
      return "-"; 
    case 0x7:
      return "EQ"; 
    case 0xD:
      return "U/SD";
    case 0x19:
      return "CYCLE";         
    case 0x44:
      return "PLAY/PAUSE";   
    case 0x43:
      return "FORWARD";   
    case 0x40:
      return "BACKWARD";   
    case 0x45:
      return "POWER";   
    case 0x47:
      return "MUTE";   
    case 0x46:
      return "MODE";       
    case 0x0:
      return "ERROR";   
    default :
      return "ERROR";
    }
}