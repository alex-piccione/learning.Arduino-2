#include <Arduino.h>

#include <Adafruit_GFX.h>     // Include the Adafruit GFX library
#include <Adafruit_PCD8544.h> // Include the Adafruit PCD8544 library for Nokia 5110 LCD
#include <DHT.h>             // La librería principal del DHT
#include <DHT_U.h>           // La librería de DHT para sensores DHT21, DHT22, etc.

bool logging_enabled = true; // Enable or disable logging to Serial Monitor

// NTC data
const int ntc_pin = A0; // Pin for the NTC thermistor
const float ntc_R0 = 8300; // 9325.7; // NTC thermistor resistance at reference temperature (25 degrees Celsius), it should be 10 000.
const float ntc_T0 = 298.15; // Reference temperature in Kelvin (25 degrees Celsius + 273.15)
const float ntc_BETA = 4288.4; // 3950; // Beta value for the NTC thermistor
const float ntc_R_ref = 9990; // actual value of the 10K resistence used in the voltage divider (it seems to go up with temperature)

const float VCC = 5; // Voltage Common Collector = Positive alimentation of the circuit (5V for Arduino Uno)
float adcToVoltageFactor = VCC / 1024; // Factor to convert ADC value to voltage (values goes from 0 to 1023, so it has 1024 steps)

// DHT21 component data
const int dht_pin = 8;
#define DHTPIN 8     // Pin digital donde conectaste el cable de datos del DHT
#define DHTTYPE DHT21 // Tipo de sensor DHT (DHT11, DHT21, DHT22)

DHT dht(DHTPIN, DHTTYPE); // Inicializa el objeto DHT

// Nokia 5110 data
const int display_pin_RST = 2; // Reset pin for the LCD
const int display_pin_CE = 3; // Chip Enable pin for the LCD
const int display_pin_DC = 4; // Data/Command pin for the LCD
const int display_pin_DIN = 5; // Data In pin for the LCD
const int display_pin_CLK = 6; // Clock pin for the LCD

// function declarations
void printText(String text);
void logValue(String label, float value);
float calculateTemperature();
float readTemperature();
float calculateVoltage(float adcValue);

// define pins of the display, CLK, DIN, DC, CE, RST
Adafruit_PCD8544 display(display_pin_CLK, display_pin_DIN, display_pin_DC, display_pin_CE, display_pin_RST);

// define display dimensions (for clarity and for calculus)
#define DISPLAY_WIDTH 84  // Width of the Nokia 5110 LCD in pixels
#define DISPLAY_HEIGHT 48  // Height of the Nokia 5110 LCD in pixels


void setup() {
  Serial.begin(9600);

  pinMode(ntc_pin, INPUT); // Set the NTC pin as input
  pinMode(dht_pin, INPUT); // Set the DHT21 pin as input

  // Initialize the Nokia 5110 LCD
  display.begin(); // initialize SPI communication
  display.setContrast(40); // Set contrast for better visibility, from 40 to 60
  display.clearDisplay(); // Clear the display buffer
  //display.setCursor(0, 0);

  printText("Display OK!");
  delay(2000); // Wait for 2 seconds to show the initial message
}

void loop() {  
  float temperature = calculateTemperature();
  printText("Temperature:\n" + String(temperature, 2) + " " + (char)247 + "C\n\n");
  
  delay(1000); // Wait for a a little bit
  temperature = readTemperature(); 
  printText("Temperature:\n" + String(temperature, 2) + " " + (char)247 + "C\n\n");
  
  delay(3000); // Wait
}

void printText(String text) {
  display.clearDisplay(); // Clear the display buffer before printing new text
  display.setTextSize(1); // Set text size to 1
  display.setTextColor(BLACK); // Set text color to black (for monochromatic screen BLACK means pixel ON)
  display.setCursor(0, 0); // Set cursor to the top-left corner
  display.print(text); // Print the text on the display
  display.display();
}

void logValue(String label, float value) {
  if (logging_enabled) {
    Serial.print(label);
    Serial.print(": ");
    Serial.println(value);
  }
}

float calculateTemperature() {
  Serial.print("Calculating temperature...\n");

  // Read the analog value from the NTC thermistor
  float adcValue = (float)analogRead(ntc_pin);
  logValue("ADC Value", adcValue);

  // Convert the ADC value to voltage
  float adc_voltage = calculateVoltage(adcValue);
  logValue("ADC Voltage", adc_voltage);
  
  // Calculate the resistance of the NTC thermistor
  //float ntc_R = (ntc_R_ref * (VCC-adc_voltage)) / adc_voltage;
  float ntc_R = (ntc_R_ref * adc_voltage) / (VCC-adc_voltage);
  logValue("NTC Resistance", ntc_R);
  
  // Calculate the temperature in Kelvin using the Beta formula
  // T_k = 1 / (1/T_0 + 1/B_value * log(R_ntc/R_0)) -->
  float temperature_K = 1. / ((1./ntc_T0) + (1./ntc_BETA) * log(ntc_R / ntc_R0));

  
  // Convert Kelvin to Celsius
  float temperature_C = temperature_K - 273.15;
  logValue("Temperature in Celsius", temperature_C);

  return temperature_C;
}

float calculateVoltage(float adcValue) {
  // Convert the ADC value to voltage
  return adcValue * adcToVoltageFactor; // V = ADC value * (VCC / 1024)
}

float readTemperature() {
  Serial.println("Reading DHT Sensor...");

  // Leer la humedad
  //float h = dht.readHumidity();
  // Leer la temperatura en Celsius
  float t = dht.readTemperature();

  //if (isnan(h) || isnan(t)) {
  if (isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    // Puedes mostrar un error en el LCD si quieres
    // printText("DHT Read Error!");
    return 0.0; // Retorna 0.0 en caso de error
  }

  //logValue("Humidity", h);
  logValue("Temperature", t);

  return t; // Placeholder for actual temperature reading logic
}