const int STcp = 12;
const int SHcp = 8;
const int DS = 3;

void setup() {
  pinMode(STcp, OUTPUT);
  pinMode(SHcp, OUTPUT);
  pinMode(DS, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 255; i++) {
    digitalWrite(STcp, LOW);
    shiftOut(DS, SHcp, MSBFIRST, i);
    digitalWrite(STcp, HIGH);
  }
}