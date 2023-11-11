/**        Yagya-Code-Hollic       **/

#include <DHT.h>
#include <LiquidCrystal.h>

#define DHT_PIN 2       // Replace with your DHT sensor pin
#define DHT_TYPE DHT11  // Use DHT11, DHT21, or DHT22 depending on your sensor
#define FAN_PIN 8       // Replace with the pin connected to the fan relay
#define LED_PIN 9       // Replace with the pin connected to the LED

DHT dht(DHT_PIN, DHT_TYPE);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Initialize the LCD with the appropriate pins

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);            // Set up the LCD to have 16 columns and 2 rows
  pinMode(FAN_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  float temperature = dht.readTemperature();

  if (!isnan(temperature)) {
    lcd.clear();  // Clear the LCD screen

    lcd.setCursor(0, 0);  // Set the cursor to the start of the first row
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print("C");

    if (temperature > 39.0) {
      digitalWrite(FAN_PIN, HIGH); // Turn the fan on
      digitalWrite(LED_PIN, LOW);   // Turn off the LED
      lcd.setCursor(0, 1); // Set cursor to the second row
      lcd.print("Fan: ON");
    } else if (temperature < 35.0) {
      digitalWrite(FAN_PIN, LOW);  // Turn off the fan
      digitalWrite(LED_PIN, HIGH); // Turn on the LED
      lcd.setCursor(0, 1); // Set cursor to the second row
      lcd.print("LED: ON");
    } else {
      digitalWrite(FAN_PIN, LOW);  // Turn off the fan
      digitalWrite(LED_PIN, LOW);  // Turn off the LED
      lcd.setCursor(0, 1); // Set cursor to the second row
      lcd.print("Fan: OFF  LED: OFF");
    }
  } else {
    Serial.println("Failed to read temperature from DHT sensor!");
  }

  delay(2000); // Delay for 2 seconds before taking the next reading
}
