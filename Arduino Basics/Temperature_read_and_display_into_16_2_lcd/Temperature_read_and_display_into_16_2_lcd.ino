#include <DHT.h>
#include <LiquidCrystal.h>

#define DHT_PIN 2     // Replace with your DHT sensor pin
#define DHT_TYPE DHT22  // Use DHT11, DHT21, or DHT22 depending on your sensor

DHT dht(DHT_PIN, DHT_TYPE);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Initialize the LCD with the appropriate pins

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);  // Set up the LCD to have 16 columns and 2 rows

  dhtRead();  // Call the function to read DHT data and display on the LCD
}

void loop() {
  // Your loop code, if needed
}

void dhtRead() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  lcd.clear();  // Clear the LCD screen

  lcd.setCursor(0, 0);  // Set the cursor to the start of the first row
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print("C");

  lcd.setCursor(0, 1);  // Set the cursor to the start of the second row
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");
}
