#include <DHT.h>

// Define the DHT sensor type and the pin it's connected to
#define DHT_PIN 2  // Replace with the actual pin number you've connected the sensor to
#define DHT_TYPE DHT22  // Use DHT11, DHT21, or DHT22 depending on your sensor

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Read temperature and humidity from the DHT sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if any reading failed and exit early if so
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the temperature and humidity to the serial monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  delay(2000); // Delay for 2 seconds before taking another reading
}
