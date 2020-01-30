#include <Wire.h>

int Poti=A0;
long depthNumb=0;

 
void setup() {
  
 
 pinMode(Poti,INPUT);
 Serial.begin(9600);
 Wire.begin(); 
 
}

void loop() {
  depthNumb=analogRead(Poti);
  depthNumb=depthNumb/4;
  Serial.println(depthNumb);
  
  Wire.beginTransmission(8); 
  Wire.write(depthNumb);
  Wire.endTransmission();    
   
  delay(100);
  
  

}
 

 
   
