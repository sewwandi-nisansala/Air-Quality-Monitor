float gas_sensor_1_value;
float gas_sensor_2_value;
float temperature_value;
float huminity_value;

void setup() {
  Serial.begin(9600);
  Serial.println(F("Air Quality Monitor."));

}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  update_all_sensor_data();
  publish_all_data();
}

/**
   Publish All data to Serial monitor/ Web/ Display
*/
void publish_all_data() {
  //Gas Data
  Serial.print("gas sensor 1 data = ");
  Serial.print(gas_sensor_1_value);
  Serial.println("V");
  Serial.print("gas sensor 2 data = ");
  Serial.print(gas_sensor_2_value);
  Serial.println("V");
  Serial.print("Temperature = ");
  Serial.print(temperature_value);
  Serial.println("C");
  Serial.print("Hiuminity = ");
  Serial.print(huminity_value);
  Serial.println("%");
  //ToDo: Update those data to Web in here
}


/**
   Update Gas sensor data
   Sensor 1 = SO2
   Sensor 2 = CO
*/
void update_all_sensor_data() {
  float temp_sensor_val_1 = 0;
  float temp_sensor_val_2 = 0;
  // Get sensor reading for 1 seconds & avarage
  for (int i = 0; i < 20; i++) {
    temp_sensor_val_1 += analogRead(A0);
    temp_sensor_val_2 += analogRead(A1);
    delay(50);
  }

  // [tempVal / (20) ]*5/1024 = tempVal / (4*1024)
  gas_sensor_1_value = temp_sensor_val_1 / (4 * 1024);
  gas_sensor_2_value = temp_sensor_val_2 / (4 * 1024);
  temperature_value = 0;
  huminity_value = 0;
}
