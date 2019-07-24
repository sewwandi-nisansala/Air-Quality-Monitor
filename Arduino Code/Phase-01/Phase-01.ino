#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("Air Quality Monitor."));

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
  updateTemperatureSensorData();
  updateGasSensorData();
}

void updateGasSensorData() {
  float sensor_volt;
  float sensorValue;

  sensorValue = analogRead(A1);
  sensor_volt = sensorValue / 1024 * 5.0;

  Serial.print("sensor_volt = ");
  Serial.print(sensor_volt);
  Serial.println("V");
  delay(1000);
}

void updateTemperatureSensorData() {
  float humidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  } else {
    Serial.print(F("Humidity: "));
    Serial.print(humidity);
    Serial.print(F("%  Temperature: "));
    Serial.print(temperature);
    Serial.println(F("°C "));
  }
}
