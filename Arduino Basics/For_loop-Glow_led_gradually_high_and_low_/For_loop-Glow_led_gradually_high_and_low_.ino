
//--- Yagya-Code-Holic ---//

//    program to glow led high and low gradually.

  void setup() {
      // put your setup code here, to run once:


    // we dont need to assign PWM pins pinMode here (analogWrite AnalogRead ) here ...
    }

void loop() {
  // put your main code here, to run repeatedly:

    
    for( int i = 0; i <= 255; i++)
    {

      // PWM pin 10 is set as output here
      
      analogWrite(10,i);
      delay(10);
    }
    for(int j = 255; j >= 0; j--)
    {
      analogWrite(10,j);
      delay(10);
    }

    
}
