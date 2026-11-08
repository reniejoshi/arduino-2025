const int VRX = A0;
const int VRY = A1;
int xVal = 0;
int yVal = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  xVal = analogRead(VRX);
  yVal = analogRead(VRY);

  Serial.print("x = ");
  Serial.print(xVal);
  Serial.print(", y = ");
  Serial.println(yVal);
  delay(200);
}
