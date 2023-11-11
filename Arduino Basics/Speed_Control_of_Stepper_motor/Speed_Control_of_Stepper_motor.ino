#include <AccelStepper.h>

// Define motor connections
#define motorPin1 2
#define motorPin2 3
#define motorPin3 4
#define motorPin4 5

// Create an AccelStepper object
AccelStepper stepper(1, motorPin1, motorPin2, motorPin3, motorPin4);

int motorSpeed = 10; // set motor speed

void setup() {
  // Set the maximum speed and acceleration
  stepper.setMaxSpeed(1000); // Adjust as needed
  stepper.setAcceleration(500); // Adjust as needed
}

void loop() {
  // Set the number of steps and direction
  int steps = 200; // Adjust the number of steps for your application
  stepper.setSpeed(motorSpeed); // Adjust the speed (RPM)

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
