#include <Arduino.h>

const int ledPin = LED_BUILTIN; // the number of the LED pin
const long interval = 3000; // delay in milliseconds
int ledState = LOW; // variable to set the state of the LED

void setup() {
  // initialize digital pin as an output.
  pinMode(ledPin, OUTPUT);
}

unsigned long previousMillis = 0;


void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > interval) {
    // save the last time check
    previousMillis = currentMillis;

    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(ledPin, ledState);
  }

}
