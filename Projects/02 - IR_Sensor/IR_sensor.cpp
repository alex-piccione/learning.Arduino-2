/* 
This is a simple example of how to use an IR sensor to detect obstacles.

When the sensor register an obstacle the led should start to blink.
After N seconds of non-registering the obstacle the led should stop blinking.

*/

#include <Arduino.h>

const int sensorPin = 2; // Pin for the IR sensor
const int ledPin = 12; // Pin for the LED
const int buzzerPin = 11; // Pin for the buzzer

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT); 
  pinMode(buzzerPin, OUTPUT);  

  // Turn off built-in LED
  pinMode(LED_BUILTIN, OUTPUT); 
  digitalWrite(LED_BUILTIN, LOW);  
}

int sensorState = LOW; // value of the sensor

void loop() {
  // Check the state of the IR sensor
  sensorState = digitalRead(sensorPin);
  if (sensorState == LOW) {
    // Obstacle detected
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    // No obstacle
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(50); // Small delay for stability
}


void buzz(int duration) {
  digitalWrite(buzzerPin, HIGH);
  delay(duration);
  digitalWrite(buzzerPin, LOW);
}