#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  // Print a message to the LCD
  lcd.print("Hello, World!");
}

void loop() {
  // Set the cursor to the start of the second line
  lcd.setCursor(0, 1);
  // Print a message on the second line
  lcd.print("Arduino LCD");

  delay(2000); // Wait for 2 seconds
  lcd.clear();  // Clear the LCD screen
  delay(1000); // Wait for 1 second
}
