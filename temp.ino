#include <OneWire.h>
#include <DallasTemperature.h>

/// Define the pin for the DS18B20 temperature sensor
const int TEMP_PIN = 2;

/// Initialize the one-wire interface for the temperature sensor
OneWire oneWire(TEMP_PIN);

/// Initialize the DallasTemperature library
DallasTemperature sensors(&oneWire);

/// Setup Temperature sensor (DS18B21)
void setupTemp() {
  // Initialize the temperature sensor
  sensors.begin();
}

/// Read temperature value
float readTemp() {
  // Read the temperature value from the DS18B20 sensor
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);
  return temperature;
}