#include <SPI.h>
#include <SD.h>
boolean newDive = true;
boolean diveMode = true;
int diveNumber = 0;
int sdLinesDepth = 0;
int sdLinesTemp = 0;
String filename = "dive" ;

String datum = "08.07.2003";
String timeDiveBeginn = "17:13";
String timeDiveEnd = "17:45";
int diveTime = 59;
float depth = 39.7;
float temp = 10.8;

long sdLogDuringDiveTime = millis();
int  sdLogDuringDiveT = 5000;

File myFile;

#include <SPI.h>
#include "Ucglib.h"
Ucglib_ST7735_18x128x160_SWSPI ucg(/*sclk=*/ 7, /*data=*/ 6, /*cd=*/ 9, /*cs=*/ 10, /*reset=*/ 8);

int displayStatusPin = 3; //on off
int batteryProzent = 0;

void setup() {
  digitalWrite(displayStatusPin, HIGH);
  delay(2000);
  ucg.begin(UCG_FONT_MODE_SOLID);
  ucg.clearScreen();
  ucg.setRotate270();
  pinMode(displayStatusPin, OUTPUT);


  Serial.begin(9600);
  while (!Serial) {

  }

  
}
void loop() {
  printBatterystatus();
  printDate();
  printTime();
  printLastDiveInfos();
  sdLogBeforeDive();
  sdLogDuringDive();
  sdLogAfterDive();
}
void sdLogWriteBeforeDive() {
  if (!SD.begin(4)) {
    Serial.println("SD-Karte nicht gefunden");
    while (1);
  }
  /////////Before Dive////////////
  diveNumberSdRead();


  diveNumber++;
  filename += diveNumber;
  Serial.println(filename);
  myFile = SD.open(filename.c_str(), FILE_WRITE);
  filename = "dive";
  myFile.print("Tauchgang Nr:");
  myFile.println(diveNumber);

  myFile.print("Datum: ");
  myFile.println(datum);

  myFile.print("Beginn: ");
  myFile.print(timeDiveBeginn);
  myFile.println(" Uhr");








}
/////////During the Dive//////////////////////////
void sdLogWriteDuringDive() {
  Serial.println("DuringDive");
  myFile.println(depth);
  sdLinesDepth++;

  myFile.println(temp);
  sdLinesTemp++;

}




//////////After Dive///////////////
void sdLogWriteAfterDive() {


  myFile.print("Ende: ");
  myFile.print(timeDiveEnd);
  myFile.println(" Uhr");
  myFile.println("");

  myFile.print("Tauchzeit: ");
  myFile.print(diveTime);
  myFile.println(" min");
  myFile.println("");




  myFile.close();

  diveNumberSdWrite();

}

void sdLogBeforeDive() {
  if (newDive == true) {
    newDive = false;
    int sdLinesTemp = 0;
    int sdLinesDepth = 0;
    sdLogWriteBeforeDive();
  }
}

void sdLogDuringDive() {
  if (diveMode == true) {
    if (millis() > sdLogDuringDiveTime) {
      sdLogDuringDiveTime = millis() + sdLogDuringDiveT;

      sdLogWriteDuringDive();
      Serial.println(millis());

    }
  }
}

void sdLogAfterDive() {
  if (millis() > 23000) {

    sdLogWriteAfterDive();
    diveMode = false;
    Serial.println(sdLinesDepth);
    Serial.println(sdLinesTemp);
    Serial.println("DiveEnd");
    delay(15000);
  }
}

void diveNumberSdWrite() {
  if (SD.exists("divenumber") == true) {
    SD.remove("divenumber");
  }
  myFile = SD.open("divenumber", FILE_WRITE);
  myFile.print(diveNumber);
  myFile.close();

}

void diveNumberSdRead() {
  myFile = SD.open("diveNumber");
  diveNumber = myFile.read();
  myFile.close();

}

void printBatterystatus(){
  ucg.setFont(ucg_font_lucasfont_alternate_hr);
  
  ucg.setColor(255,255,255);
  ucg.drawLine( 138, 1, 160,1);
  ucg.drawLine( 138,11, 160,11);
  ucg.drawLine( 159,1, 159,11);
  ucg.drawLine( 138,1, 138,4);
  ucg.drawLine( 138,8, 138,11);
  ucg.drawLine( 136,4, 136,8);
  ucg.drawLine( 136,4, 138,4);
  ucg.drawLine( 136,8, 138,8);
  
batteryProzent=33;
  if(batteryProzent>99){
  ucg.setColor(0,255,0);
  ucg.drawBox(137,5,2,3);
  ucg.drawBox(158,2,1,9);
    
  ucg.setPrintPos(140,10);
  ucg.setColor(255,255,255);
  ucg.print(batteryProzent);
  }
  
  if(batteryProzent<100 && batteryProzent>9){
   
    if(batteryProzent<19){
     ucg.setColor(255,0,0);
    }

     if(batteryProzent>19){
     ucg.setColor(255,165,0);
    }
    
     if(batteryProzent>39){
     ucg.setColor(255,255,0);
    }
    
    if(batteryProzent>59){
     ucg.setColor(0,255,0);
    }
     
    ucg.drawBox(139,2,4,9);
    ucg.drawBox(156,2,3,9);
    ucg.drawBox(137,5,2,3);

    ucg.setColor(255,255,255);
    ucg.setPrintPos(144,10);
    ucg.print(batteryProzent);
    }
  
  if(batteryProzent<10){
    ucg.setColor(255,0,0);
    ucg.drawBox(139,2,7,9);
    ucg.drawBox(151,2,8,9);
    ucg.drawBox(137,5,2,3);

    ucg.setColor(255,255,255);
    ucg.setPrintPos(146,10);
    ucg.print(batteryProzent);
    }
}
void printDate(){
    ucg.setFont(ucg_font_lucasfont_alternate_hr);
    ucg.setColor(255,255,255);
    ucg.setPrintPos(1,10);
    ucg.print("08.07.2003");
}
void printTime(){
    ucg.setFont(ucg_font_helvR12_hr );
    ucg.setColor(255,255,255);
    ucg.setPrintPos(64,15);
    ucg.print("Di 18:20");
}
void printLastDiveInfos(){
    ucg.setFont(ucg_font_lucasfont_alternate_hr);
    ucg.setColor(255,255,255);
    ucg.setPrintPos(50,30);
    ucg.print("last dive:");
  }

     
  
  
