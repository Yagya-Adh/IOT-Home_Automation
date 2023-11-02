
//-- Yagya-Code-Holic --//

//#define LED1 2;
//#define LED1 3;
//
//void setup() {
//  // put your setup code here, to run once:
//
//  pinMode(LED1, OUTPUT);
//  pinMode(LED2, OUTPUT);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//    blinkLED(LED1);
//}
//
//
//void blinkLED(int pin){
//
//  digitalWrite(LED1, HIGH);
//  delay(1000);
//  digitalWrite(LED1, LOW);
//  delay(1000);
//  
//}
 
 

#define LED1 2;
#define LED1 3;

void setup() {
  // put your setup code here, to run once:

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}
 
void loop() {
  // put your main code here, to run repeatedly:
    blinkLED(LED1,500);
}


void blinkLED(int pin, int delay_val){

  digitalWrite(pin, HIGH);
  delay(delay_val);
  digitalWrite(pin, LOW);
  delay(delay_val);
  
}
