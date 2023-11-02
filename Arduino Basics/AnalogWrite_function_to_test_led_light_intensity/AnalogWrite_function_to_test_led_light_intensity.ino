void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

// Tested value to see changes in brightness of led
//    analogWrite(6,0); //off
//    analogWrite(6,50); // on but dim
//
//    analogWrite(6,100); // on but low intensity 
    analogWrite(6,255); // on max brightness
}
