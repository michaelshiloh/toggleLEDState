/*
  toggleLEDState

  Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
  press), the output pin is toggled from LOW to HIGH or HIGH to LOW.

  The circuit:
   LED attached from pin 13 to ground
   pushbutton attached from pin 2 to +5V
   10K resistor attached from pin 2 to ground

  Based on debounce by David Mellis

  8 June 2017 - Michael Shiloh - Created

  This example code is in the public domain.

*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int lastButtonState = LOW;   // the previous reading from the input pin

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
}

void loop() {

  // read the state of the switch into a local variable:
  int currentButtonState = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH)

  if (lastButtonState == LOW && currentButtonState == HIGH) {

    // If the LED was off, turn it on, and if it was on, turn it off
    ledState = !ledState;
  }

  // set the LED according to the ledState variable:
  digitalWrite(ledPin, ledState);

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = currentButtonState;
}
