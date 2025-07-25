/*
 * Automatic Plant Irrigation System
 *
 * This Arduino sketch controls an automatic plant irrigation system. It uses a
 * rain/snow sensor to detect moisture and a soil moisture sensor to monitor the
 * soil's moisture level. If the soil is dry and it is not raining, the system
 * activates a water pump via a relay to water the plants.
 */

// Pin definitions
const int rainSensorPin = 6; // Digital pin connected to rain sensor
const int soilMoisturePin = A0; // Analog pin connected to soil moisture sensor
const int relayPin = 3; // Digital pin connected to relay

// Soil moisture threshold
const int soilMoistureThreshold = 500;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize pin modes
  pinMode(rainSensorPin, INPUT);
  pinMode(soilMoisturePin, INPUT);
  pinMode(relayPin, OUTPUT);

  // Ensure the relay is off initially
  digitalWrite(relayPin, LOW);
}

void loop() {
  // Read the rain sensor value
  int rainSensorValue = digitalRead(rainSensorPin);
  // Read the soil moisture sensor value
  int soilMoistureValue = analogRead(soilMoisturePin);

  // Print sensor values to the serial monitor
  Serial.print("Rain Sensor: ");
  Serial.print(rainSensorValue);
  Serial.print("\tSoil Moisture: ");
  Serial.println(soilMoistureValue);

  // Check if it is not raining and the soil is dry
  if (rainSensorValue == LOW && soilMoistureValue < soilMoistureThreshold) {
    // Turn on the relay to activate the water pump
    digitalWrite(relayPin, HIGH);
  } else {
    // Turn off the relay to deactivate the water pump
    digitalWrite(relayPin, LOW);
  }

  // Wait for a second before the next loop
  delay(1000);
}