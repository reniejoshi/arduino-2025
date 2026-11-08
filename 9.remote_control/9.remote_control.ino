#include <IRremote.h>

const int irReceiverPin = 12; // IR Reciever

// Motors
const int A1B = 5;
const int A1A = 6;
const int B1B = 9;
const int B1A = 10;

int speed = 255;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(irReceiverPin, ENABLE_LED_FEEDBACK); // Start the IR reciever

  Serial.println("Begin");

  pinMode(A1B, OUTPUT);
  pinMode(A1A, OUTPUT);
  pinMode(B1B, OUTPUT);
  pinMode(B1A, OUTPUT);
}

void loop() {
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
      else if (key == "2") {
        moveForward(speed);
        delay(1000);
        Serial.print("Here");
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
  else {
    Serial.println("No key");
  }
}

void moveForward(int speed) {
  Serial.print("in moveFoward() function");
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