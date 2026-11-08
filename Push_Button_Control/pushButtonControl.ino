#define LED 13 // the pin for the LED
#define BUTTON 7 // the input pin where the pushbutton is connected

int val = 0; // val will be used to store the state of the input pin

int oldVal = 0; // this variable stores the previous value of val

int state = 0; // 0 = LED off while 1 = LED on

void setup() {
  pinMode(LED, OUTPUT); // tell Arduino LED is an output
  pinMode(BUTTON, INPUT); // and BUTTON is an input
}

void loop() {
  val = digitalRead(BUTTON); // read input value and store it

  //check if there was a transition
  if ((val == HIGH) && (oldVal == LOW)) {
    state = 1 - state;
    delay(10);
  }

  oldVal = val; // val is now old, let's store it

  if (state == 1) {
    digitalWrite(LED, HIGH); // turn LED on
  }
  else {
    digitalWrite(LED, LOW); // turn LED off
  }
}