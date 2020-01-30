#include <SPI.h>
#include <SD.h>
File myFile;


#include "Ucglib.h"
Ucglib_ST7735_18x128x160_SWSPI ucg(/*sclk=*/ 7, /*data=*/ 6, /*cd=*/ 9, /*cs=*/ 10, /*reset=*/ 8);
int displayStatusPin=3;

double lipoVoltage=0.0;
int lipoAnalogVoltage=0;

void setup() {
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
   
  
  digitalWrite(displayStatusPin,HIGH);
  delay(2000);
  ucg.begin(UCG_FONT_MODE_SOLID);
  ucg.clearScreen();
  ucg.setRotate270();  
pinMode(displayStatusPin,OUTPUT);

pinMode(A1,INPUT);


 if (!SD.begin(4)) {
    Serial.println("SD-Karte nicht gefunden");
    while (1);
  }
   
}

void loop() {
   lipoAnalogVoltage=analogRead(A1);
   lipoVoltage=lipoAnalogVoltage*(5.0/1023.0);
  
   
   myFile = SD.open("lipov.txt", FILE_WRITE);
  myFile.println(lipoVoltage);
   myFile.close();
  delay(100);
   
   

    ucg.setFont(ucg_font_helvR12_hr );
    ucg.setColor(255,255,255);
    ucg.setPrintPos(90,60);
    ucg.print(lipoVoltage);

    Serial.println(lipoVoltage);
  delay(99900);
   
    
  
  
}
