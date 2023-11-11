//-- Yagya-Code-Holic --//
//
//#include <Servo.h>
//
//Servo myservo; // created object
//
//void setup() {
//  // put your setup code here, to run once:
//
//    myservo.attach(9,600,2300);
//  }
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  myservo.write(0);  // positioning servo motor at angle 0deg.
//
//  delay(1000);
//
//  myservo.write(90);
//  delay(500);
//
//  myservo.write(135);
//  delay(500);
//
//  myservo.write(180);
//  delay(500);
//   
//}


// -- multiple servo motor control -- //

#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup() {
  servo1.attach(8);
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);
  servo5.attach(12);
}

void loop() {
  // move all servos to position 0
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);
  servo5.write(0);
  delay(2000);

  // move all servos to position 90
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
  servo5.write(90);
  delay(2000);

  // move all servos to position 180
  servo1.write(180);
  servo2.write(180);
  servo3.write(180);
  servo4.write(180);
  servo5.write(180);
  delay(2000);
}
