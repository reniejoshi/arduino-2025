#include <LiquidCrystal_I2C.h>
#include <Servo.h>

const int VRX = A0;
const int VRY = A1;
LiquidCrystal_I2C lcd(0x27, 16, 2); // initializes LCD object with address 0x27, 16 columns per line, and 2 lines
Servo servo;

void setup() {
  lcd.init(); // initialize LCD
  lcd.clear();
  lcd.backlight(); // turn on backlight
  servo.attach(9);

  Serial.begin(9600);
}

void loop() {  
  int xVal = analogRead(VRX);
  int yVal = analogRead(VRY);

  lcd.setCursor(0, 0); // set cursor to character 0 on line 0
  lcd.print("x = ");
  lcd.print(xVal);
  lcd.setCursor(0, 1);
  lcd.print("y = ");
  lcd.print(yVal);

  xVal = map(xVal, 0, 1023, 0, 180);
  servo.write(xVal);

  delay(10);
}