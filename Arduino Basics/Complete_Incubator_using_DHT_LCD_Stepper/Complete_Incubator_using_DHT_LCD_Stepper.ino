#include <DHT.h>
#include <LiquidCrystal.h>
#include <AccelStepper.h>

#define DHT_PIN 2     // Replace with your DHT sensor pin
#define DHT_TYPE DHT11  // Use DHT11 for the DHT sensor
#define FAN_PIN 9      // Replace with the pin connected to the fan relay
#define LED_PIN 10     // Replace with the pin connected to the LED

DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal lcd(7, 6, 5, 4, 3, 1); // Initialize the LCD with the appropriate pins
AccelStepper stepper(1, 11, 12, 13, 8);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);  // Set up the LCD to have 16 columns and 2 rows
  stepper.setMaxSpeed(1000); // Adjust as needed
  stepper.setAcceleration(500); // Adjust as needed
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

    fanFun(temperature);
    ledFun(temperature);
    stepFun();

    // Delay for a moment
    delay(1000);
  } else {
    Serial.println("Failed to read temperature from DHT sensor!");
  }
}

void fanFun(float temperature) {
  if (temperature > 39.0) {
    digitalWrite(FAN_PIN, HIGH); // Turn the fan on
  } else {
    digitalWrite(FAN_PIN, LOW); // Turn off the fan
  }
}

void ledFun(float temperature) {
  if (temperature > 41.0) {
    digitalWrite(LED_PIN, LOW); // Turn off the LED
  } else {
    digitalWrite(LED_PIN, HIGH); // Turn on the LED
  }
}

void stepFun() {
  // Control the stepper motor
  int steps = 200; // Adjust the number of steps for your application
  stepper.setSpeed(100); // Adjust the speed (RPM)

  // Rotate the motor clockwise
  stepper.move(steps);
  stepper.runToPosition();

  // Delay for a moment
  delay(1000);

  // Rotate the motor counterclockwise
  stepper.move(-steps);
  stepper.runToPosition();

  // Delay for a moment
  delay(1000);
}
