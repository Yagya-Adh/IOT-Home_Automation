
int var[6]= {2,3,4,5,6,7};

// Yagya -code -holic
void setup() {
  // put your setup code here, to run once:

// Array
int val[6] = {2,3,4,5,6,7};

//This all below are same:
// int val[6]; vs int val[];
// int val[]={2,3,4,5}; vs this way we define size of array ---->  int val[4] = {2,3,4,5}; 
// char val[]="abcd"; char val[4]="abcd"; ---> this way we can define array 

// array has index number to take array value.

Serial.begin();
Serial.print(var[1]);
//output: 3

}

void loop() {
  // put your main code here, to run repeatedly:

}
