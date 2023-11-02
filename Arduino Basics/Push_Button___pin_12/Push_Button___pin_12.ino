
// --Auth : Yagya-Code-Holic-- //

// program to read push button press , which is placed at pin 12 and GND in ardiuno.

void setup() {
  // put your setup code here, to run once:

    pinMode(12,INPUT_PULLUP);
    pinMode(13,OUTPUT);
    Serial.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
    int val = digitalRead(12);
    Serial.println(val); // println() prints our data in next line
    digitalWrite(13,val);

    
//   all folowings are same:
//      digitalWrite(13,val);
//      digitalWrite(13,1);  
//      digitalWrite(13,true);
//      digitalWrite(13,HIGH);
// or, 
//      digitalWrite(13,val);
//      digitalWrite(13,0);  
//      digitalWrite(13,false);
//      digitalWrite(13,LOW);

}
