

// Yagya-Code-Holic
      int count = 0;
      
      void setup() {
            // put your setup code here, to run once:
          
          pinMode(2,INPUT_PULLUP);
          pinMode(6,OUTPUT);
      }

      void loop() {
       // put your main code here, to run repeatedly:

        int val = digitalRead(2);
          
          if(val == 0)
          {
            count = count +1;
          }
          
          if(count == 1)
          {
              digitalWrite(6,100);  
          }
          else if(count == 2 )
          {
            digitalWrite(6,180);
          }
          else if(count == 3){
            digitalWrite(6,255);
          }
          else
          {
            digitalWrite(6,0);
            count = 0;
          }        
          delay(200);

}
