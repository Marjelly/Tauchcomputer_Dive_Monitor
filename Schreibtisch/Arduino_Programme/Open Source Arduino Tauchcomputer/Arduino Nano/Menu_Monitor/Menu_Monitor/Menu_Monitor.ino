#include <SPI.h>
#include "Ucglib.h"
Ucglib_ST7735_18x128x160_SWSPI ucg(/*sclk=*/ 7, /*data=*/ 6, /*cd=*/ 9, /*cs=*/ 10, /*reset=*/ 8);

int displayStatusPin=3;//on off 
int batteryProzent=0;
void setup() {
  digitalWrite(displayStatusPin,HIGH);
  delay(2000);
  ucg.begin(UCG_FONT_MODE_SOLID);
  ucg.clearScreen();
  ucg.setRotate270();  
pinMode(displayStatusPin,OUTPUT);
}

void loop() {
  
  printBatterystatus();
  printDate();
  printTime();
  printLastDiveInfos();

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

     
  
  
