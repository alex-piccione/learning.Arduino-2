#include <Arduino.h>

#include <Adafruit_GFX.h>     // Include the Adafruit GFX library
#include <Adafruit_PCD8544.h> // Include the Adafruit PCD8544 library for Nokia 5110 LCD

// NTC data
const int ntc_pin = A0; // Pin for the NTC thermistor
const float ntc_R0 = 10000; // NTC thermistor resistance at reference temperature (25 degrees Celsius)
const float ntc_BETA = 4050; // Beta value for the NTC thermistor
const float ntc_R_ref = 9850; // actual value of hte resistence used in the voltage divider
const float ntc_T0 = 298.15; // Reference temperature in Kelvin (25 degrees Celsius + 273.15)

const float ADC_MAX = 1023; // Maximum ADC value for a 10-bit ADC
const float VCC = 5;

// Nokia 5110 data
const int display_pin_RST = 2; // Reset pin for the LCD
const int display_pin_CE = 3; // Chip Enable pin for the LCD
const int display_pin_DC = 4; // Data/Command pin for the LCD
const int display_pin_DIN = 5; // Data In pin for the LCD
const int display_pin_CLK = 6; // Clock pin for the LCD

// function declarations
void printText(String text);
float calculateTemperature();

// define pins of the display, CLK, DIN, DC, CE, RST
Adafruit_PCD8544 display(display_pin_CLK, display_pin_DIN, display_pin_DC, display_pin_CE, display_pin_RST);

// define display dimensions (for clarity and for calculus)
#define DISPLAY_WIDTH 84  // Width of the Nokia 5110 LCD in pixels
#define DISPLAY_HEIGHT 48  // Height of the Nokia 5110 LCD in pixels

//const int ntcPin = A0; // Pin for the NTC thermistor
//const float beta = 3950.0; // Beta value for the NTC thermistor

void setup() {
  Serial.begin(9600);

  // Initialize the Nokia 5110 LCD
  display.begin(); // initialize SPI communication
  display.setContrast(40); // Set contrast for better visibility, from 40 to 60
  display.clearDisplay(); // Clear the display buffer
  //display.setCursor(0, 0);

  printText("Display OK!\n\nHello world");
  delay(2000); // Wait for 2 seconds to show the initial message
}

void loop() {  
  float tempersture = calculateTemperature();
  printText("Temperature:\n" + String(tempersture, 2) + " " + (char)247 +  (char)176 + "C\n\n");
  /*for (int x = 255; x <= 500; x++) { "C\n\n");
  for (int x = 255; x <= 500; x++) {
    printText(String(x) + " " + (char)x + "\n");
    delay(1000);
  }*/

  delay(3000); // Wait for a second
}

void printText(String text) {
  display.clearDisplay(); // Clear the display buffer before printing new text
  display.setTextSize(1); // Set text size to 1
  display.setTextColor(BLACK); // Set text color to black (for monochromatic screen BLACK means pixel ON)
  display.setCursor(0, 0); // Set cursor to the top-left corner
  display.print(text); // Print the text on the display
  display.print((char)248); // Stampa il simbolo del grado
  display.print((char)176); // Stampa il simbolo del grado
  display.display();
}

float calculateTemperature() {
  Serial.print("Calculating temperature...\n");

  // Read the analog value from the NTC thermistor
  float adcValue = (float)analogRead(ntc_pin);
  Serial.print("ADC Value: ");
  Serial.println(adcValue);
  
  // Convert the ADC value to voltage
  float voltage = (adcValue / ADC_MAX) * VCC;
  Serial.print("voltage: ");
  Serial.println(voltage);
  
  // Calculate the resistance of the NTC thermistor
  //float ntc_R = (ntc_R_ref * (VCC / voltage)) - ntc_R_ref;
  float ntc_R = ntc_R_ref * adcValue / (ADC_MAX - adcValue);

  Serial.print("NTC Resistance: ");
  Serial.println(ntc_R);
  
  // Calculate the temperature in Kelvin using the Beta formula
  float temperatureK = (ntc_BETA * ntc_T0) / (ntc_BETA + (ntc_T0 * log(ntc_R / ntc_R0)));
  
  // Convert Kelvin to Celsius
  float temperatureC = temperatureK - 273.15;

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  return temperatureC;
}