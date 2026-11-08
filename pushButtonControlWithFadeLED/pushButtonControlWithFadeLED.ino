#define LED 9 // the pin for the LED
#define BUTTON 7 // input pin of the pushbutton
int val = LOW; // stores the state of the input pin (7)

int old_val = 0; // store the previous value of val
int state = 0; // 0 = LED off, 1 = LED on

int brightness = 128; // stores the brightness value
unsigned long startTime = 0; // when did we begin pressing?

void setup() {
  pinMode(LED, OUTPUT); // tell Arduino LED is an output
  pinMode(BUTTON, INPUT); // BUTTON is an input
}

void loop() {
  val = digitalRead(BUTTON); // read input value and store it

  // check if there was a change
  if ((val == HIGH) && (old_val == LOW)) {
    state = 1 - state; // change the state from off to on or vice versa

    startTime = millis(); // millis() is the Arduino clock
    // it returns how many milliseconds have passed since the Arduino board has been reset
    // (this line remembers when the button was last pressed)
    delay(10);
  }

  // check if the button is being pressed
  if ((val == HIGH) && (old_val == HIGH)) {
    // if the button is held for more than 500ms
    if (state == 1 && (millis() - startTime) > 500) {
      brightness++; // increment brightness by 1
      delay(10);

      if (brightness > 255) { // 255 is the max brightness
        brightness = 0; // if we go over 255, let's go back to 0
      }
    }
  }

  old_val = val; // val is now old, let's store it
  
  if (state == 1) {
    analogWrite(LED, brightness); // turn LED on at the current brightness level
  }
  else {
    analogWrite(LED, 0); // turn LED off
  }
}