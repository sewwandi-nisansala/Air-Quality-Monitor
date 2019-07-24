#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
float sensor_volt;
float sensorValue;
float humidity;
float temperature;

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
  publishAllData();
}

void publishAllData() {
  //Temperature Data
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
  //Gas Data
  Serial.print("sensor_volt = ");
  Serial.print(sensor_volt);
  Serial.println("V");
  //ToDo: Update those data to Web in here
}


void updateGasSensorData() {
  sensorValue = analogRead(A0);
  sensor_volt = sensorValue / 1024 * 5.0;
}

void updateTemperatureSensorData() {
  humidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
  temperature = dht.readTemperature();
}
