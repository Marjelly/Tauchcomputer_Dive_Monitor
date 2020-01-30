#include <SPI.h>
#include "Ucglib.h"
Ucglib_ST7735_18x128x160_SWSPI ucg(/*sclk=*/ 7, /*data=*/ 6, /*cd=*/ 9, /*cs=*/ 10, /*reset=*/ 8);

int menuLineColor_1 =255;
int menuLineColor_2 =255;
int menuLineColor_3 =255;

int menuExplanationsColor_1=255;
int menuExplanationsColor_2=255;
int menuExplanationsColor_3=255;

int depthColor_1=0;
int depthColor_2=255;
int depthColor_3=0;

int divetimeColor_1=255;
int divetimeColor_2=255;
int divetimeColor_3=0;

int ascendSpeedColor_1=255;
int ascendSpeedColor_2=0;
int ascendSpeedColor_3=0;

int noDecoTimeColor_1=255;
int noDecoTimeColor_2=105;
int noDecoTimeColor_3=0;

int safetyStopColor_1=30;
int safetyStopColor_2=175;
int safetyStopColor_3=15;
 
int temperatureColor_1=144;
int temperatureColor_2=50;
int temperatureColor_3=233;

int maxDepthColor_1=0;
int maxDepthColor_2=225;
int maxDepthColor_3=255;

int displayStatusPin=3;//on off
 
 

void setup() {
   digitalWrite(displayStatusPin,HIGH);
   delay(2000);
  ucg.begin(UCG_FONT_MODE_SOLID);
  ucg.clearScreen();
  ucg.setRotate270();
  ucg.setFont(ucg_font_fub30_hr);
  ucg.setFont(ucg_font_lucasfont_alternate_hr);
  ucg.setFontPosBottom();
  ucg.setPrintPos(0,0);
  pinMode(displayStatusPin,OUTPUT);
}

void loop() {
   
  drawMenuLine();
  drawDepth();
  drawDivetime();
  drawAscentSpeed();
  drawNoDecoTime();
  //drawSafetyStop();
  drawTemperature();
  drawMaxDepth();
  //drawDecoStops();

}
void drawMenuLine(){
 ucg.setColor(menuLineColor_1,menuLineColor_2,menuLineColor_3);
 ucg.drawLine( 0, 55, 160,55);
 ucg.drawLine(0,100,160,100);
 ucg.drawLine(90,0,90,128);
 
 
  
 
}
void drawDepth(){
  ucg.setFont(ucg_font_lucasfont_alternate_hr);
  ucg.setPrintPos(0,9);
  ucg.setColor(menuExplanationsColor_1,menuExplanationsColor_2,menuExplanationsColor_3);
  ucg.print("Depth");

 
  ucg.setPrintPos(82,45);
  ucg.setColor(depthColor_1,depthColor_2,depthColor_3);
  ucg.print("m");

  

  ucg.setFont(ucg_font_fub30_hr );
  ucg.setPrintPos(0,50);
  ucg.setColor(depthColor_1,depthColor_2,depthColor_3);
  ucg.print("39,7");
}
void drawDivetime(){
  ucg.setFont(ucg_font_lucasfont_alternate_hr);
  ucg.setPrintPos(95,9);
  ucg.setColor(menuExplanationsColor_1,menuExplanationsColor_2,menuExplanationsColor_3);
  ucg.print("Divetime");

 
  ucg.setPrintPos(145,45);
  ucg.setColor(divetimeColor_1,divetimeColor_2,divetimeColor_3);
  ucg.print("min");
  
  ucg.setFont(ucg_font_helvR24_hr);
  ucg.setPrintPos(91,50);
  ucg.setColor(divetimeColor_1,divetimeColor_2,divetimeColor_3);
  ucg.print("111");
}

void drawAscentSpeed(){
  ucg.setFont(ucg_font_lucasfont_alternate_hr);
  ucg.setPrintPos(0,65);
  ucg.setColor(menuExplanationsColor_1,menuExplanationsColor_2,menuExplanationsColor_3);
  ucg.print("Ascent Speed");

 
  ucg.setPrintPos(61,95);
  ucg.setColor(ascendSpeedColor_1,ascendSpeedColor_2,ascendSpeedColor_3);
  ucg.print("m/s");
  
  ucg.setFont(ucg_font_helvR24_hr);
  ucg.setPrintPos(5,100);
  ucg.setColor(ascendSpeedColor_1,ascendSpeedColor_2,ascendSpeedColor_3);
  ucg.print("-2,2");
}

void drawNoDecoTime(){
  ucg.setFont(ucg_font_lucasfont_alternate_hr);
  ucg.setPrintPos(93,65);
  ucg.setColor(menuExplanationsColor_1,menuExplanationsColor_2,menuExplanationsColor_3);
  ucg.print("No Deco Time");

 
  ucg.setPrintPos(145,95);
  ucg.setColor(noDecoTimeColor_1,noDecoTimeColor_2,noDecoTimeColor_3);
  ucg.print("min");
  
  ucg.setFont(ucg_font_helvR24_hr);
  ucg.setPrintPos(91,100);
  ucg.setColor(noDecoTimeColor_1,noDecoTimeColor_2,noDecoTimeColor_3);
  ucg.print("141");
}

void drawSafetyStop(){
  ucg.setFont(ucg_font_lucasfont_alternate_hr);
  ucg.setPrintPos(93,65);
  ucg.setColor(menuExplanationsColor_1,menuExplanationsColor_2,menuExplanationsColor_3);
  ucg.print("Safety Stop");

  ucg.setFont(ucg_font_helvR24_hr);
  ucg.setPrintPos(96,100);
  ucg.setColor(safetyStopColor_1,safetyStopColor_2,safetyStopColor_3);
  ucg.print("4");

  ucg.setFont(ucg_font_helvR24_hr);
  ucg.setPrintPos(110,98);
  ucg.setColor(safetyStopColor_1,safetyStopColor_2,safetyStopColor_3);
  ucg.print(":");
  
  ucg.setFont(ucg_font_helvR24_hr);
  ucg.setPrintPos(120,100);
  ucg.setColor(safetyStopColor_1,safetyStopColor_2,safetyStopColor_3);
  ucg.print("33");
}

void drawDecoStops(){
  ucg.setFont(ucg_font_lucasfont_alternate_hr);
  ucg.setPrintPos(93,65);
  ucg.setColor(menuExplanationsColor_1,menuExplanationsColor_2,menuExplanationsColor_3);
  ucg.print("Deco Stops");

 //Dekostop 1
  ucg.setPrintPos(145,75);
  ucg.setColor(noDecoTimeColor_1,noDecoTimeColor_2,noDecoTimeColor_3);
  ucg.print("min");
  
  ucg.setFont(ucg_font_7x14B_tr);
  ucg.setPrintPos(94,78);
  ucg.setColor(noDecoTimeColor_1,noDecoTimeColor_2,noDecoTimeColor_3);
  ucg.print("12");

  ucg.setPrintPos(118,78);
  ucg.print(":");

  ucg.setPrintPos(128,78);
  ucg.print("95");
  
  ucg.setFont(ucg_font_lucasfont_alternate_hr);
  ucg.setPrintPos(110,75);
  ucg.setColor(noDecoTimeColor_1,noDecoTimeColor_2,noDecoTimeColor_3);
  ucg.print("m");
  
  //Dekostop 2
  ucg.setPrintPos(145,75);
  ucg.setColor(noDecoTimeColor_1,noDecoTimeColor_2,noDecoTimeColor_3);
  ucg.print("min");
  
  ucg.setFont(ucg_font_7x14B_tr);
  ucg.setPrintPos(94,90);
  ucg.setColor(noDecoTimeColor_1,noDecoTimeColor_2,noDecoTimeColor_3);
  ucg.print("12");

  ucg.setPrintPos(118,78);
  ucg.print(":");

  ucg.setPrintPos(128,78);
  ucg.print("95");
  
  ucg.setFont(ucg_font_lucasfont_alternate_hr);
  ucg.setPrintPos(110,75);
  ucg.setColor(noDecoTimeColor_1,noDecoTimeColor_2,noDecoTimeColor_3);
  ucg.print("m");
}

void drawTemperature(){
  ucg.setFont(ucg_font_lucasfont_alternate_hr);
  ucg.setPrintPos(93,110);
  ucg.setColor(menuExplanationsColor_1,menuExplanationsColor_2,menuExplanationsColor_3);
  ucg.print("Temperature");

 
  ucg.setPrintPos(150,127);
  ucg.setColor(temperatureColor_1,temperatureColor_2,temperatureColor_3);
  ucg.print("c");
  
  ucg.drawCircle(157,120, 2, UCG_DRAW_ALL);
   
  
  ucg.setFont(ucg_font_courB18_tf);
  ucg.setPrintPos(91,132);
  ucg.setColor(temperatureColor_1,temperatureColor_2,temperatureColor_3);
  ucg.print("13,3");
}

void drawMaxDepth(){
  ucg.setFont(ucg_font_lucasfont_alternate_hr);
  ucg.setPrintPos(0,110);
  ucg.setColor(menuExplanationsColor_1,menuExplanationsColor_2,menuExplanationsColor_3);
  ucg.print("Max Depth");

 
  ucg.setPrintPos(71,127);
  ucg.setColor(maxDepthColor_1,maxDepthColor_2,maxDepthColor_3);
  ucg.print("m");

  
  ucg.setFont(ucg_font_courB18_tf);
  ucg.setPrintPos(8,132);
  ucg.setColor(maxDepthColor_1,maxDepthColor_2,maxDepthColor_3);
  ucg.print("15,5");
}
