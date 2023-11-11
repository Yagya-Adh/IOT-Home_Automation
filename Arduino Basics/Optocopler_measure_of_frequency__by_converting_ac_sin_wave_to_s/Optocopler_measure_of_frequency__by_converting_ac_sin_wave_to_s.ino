/**       Yagya-Code-Hollic      **/

const int pulsePin = 8; 

int pulseHigh; // Integer variable to capture High time of the incoming pulse
int pulseLow; // Integer variable to capture Low time of the incoming pulse
float pulseTotal; // Float variable to capture Total time of the incoming pulse
float frequency; // Calculated Frequency
void setup() {
  pinMode(8,INPUT);
  Serial.begin(9600);
}

void loop() {
    pulseHigh = pulseIn(pulsePin,HIGH);
    pulseLow = pulseIn(pulsePin,LOW);
    pulseTotal = pulseHigh + pulseLow;    // Time period of the pulse in microseconds
    frequency = 1000000/pulseTotal;       // Frequency in Hertz (Hz)
    Serial.print("Frequency  =");
    Serial.print(frequency);
    Serial.println(" Hz");
    delay(300);
}
