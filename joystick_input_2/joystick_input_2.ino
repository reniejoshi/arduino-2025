const int VRX = A0;
const int VRY = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int xVal = analogRead(VRX);
  int yVal = analogRead(VRY);

  Serial.print("x = ");
  Serial.print(xVal);
  Serial.print(", y = ");
  Serial.println(yVal);
  delay(200);
}
