#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  
  Serial.println("Hello, World!");

  int result = myFunction(5, 7);
  Serial.print("Result of myFunction(5, 7): "); 
  Serial.println(result);
  Serial.println("Waiting for 1 second...");

  delay(1000); // Wait for a second
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}