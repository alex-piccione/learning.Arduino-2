#include <Arduino.h>

#include <DHT.h>             // La librería principal del DHT
#include <DHT_U.h>           // La librería de DHT para sensores DHT21, DHT22, etc.


// DHT21 component data
#define DHTPIN 2     // Pin digital donde conectaste el cable de datos del DHT
#define DHTTYPE DHT21 // Tipo de sensor DHT (DHT11, DHT21, DHT22)

DHT dht(DHTPIN, DHTTYPE); // Inicializa el objeto DHT

bool logging_enabled = true; 

struct DHT_Values {
  bool isReadOk;
  float temperature;
  float humidity;
};

// Functions
void logValue(String label, float value);
DHT_Values readData();

void setup() {
  Serial.begin(9600);
  Serial.println("Hello, World!");

  // pinMode(DHTPIN, INPUT); // Configura el pin del DHT como entrada
  dht.begin(); // Inicializa el sensor DHT
}

void loop() {  
  Serial.println("Read Temperature and Humidity...");

  DHT_Values values = readData();

  if (! values.isReadOk ) {  
    Serial.println("Failed to read from DHT sensor!");
  } else {
    logValue("Temperature", values.temperature);
    logValue("Humidity", values.humidity);
  }

  delay(2000); 
}

void logValue(String label, float value) {
  if (logging_enabled) {
    Serial.print(label);
    Serial.print(": ");
    Serial.println(value);
  }
}

DHT_Values readData() {
  Serial.println("Reading DHT Sensor...");
  
  DHT_Values values;
  values.temperature = dht.readTemperature();
  values.humidity = dht.readHumidity();
  values.isReadOk = !isnan(values.temperature) && !isnan(values.humidity);

  return values;
}