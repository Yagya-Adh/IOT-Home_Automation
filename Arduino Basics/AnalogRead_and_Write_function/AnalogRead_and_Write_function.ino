//--- Yagya-Code-Holic --//

// analog valur read using gas sensor .


void setup() {
  // put your setup code here, to run once:


Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

// analog input pin A0 to A5
  int val = analogRead(A0);

  Serial.println(val);
  delay(1000);
}  
