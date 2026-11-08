const int ledPin = 6;
const int potPin = A0;
const int btnPin = 7;
int potVal = 0;
int lastBtnState = HIGH;
int ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  //pinMode(potPin, INPUT);
  pinMode(btnPin, INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() {
  int btnState = digitalRead(btnPin);
  Serial.print("Button State: ");
  Serial.println(btnState);
  
  if (lastBtnState == HIGH && btnState == LOW) { //btn is pressed
    ledState = !ledState;
  }
  
  if (ledState == HIGH) {
    potVal = analogRead(potPin);
    analogWrite(ledPin, potVal / 4);
    Serial.print("Pot val: ");
    Serial.println(potVal);
  }
  else if (ledState == LOW) {
    analogWrite(ledPin, 0);
  }
  
  lastBtnState = btnState;
  delay(200);
}