#include <SPI.h>
#include "Ucglib.h"
Ucglib_ST7735_18x128x160_SWSPI ucg(/*sclk=*/ 12, /*data=*/ 11, /*cd=*/ 9, /*cs=*/ 10, /*reset=*/ 8);

int menuLineColor_1 =255;
int menuLineColor_2 =255;
int menuLineColor_3 =255;

int menuExplanationsColor_1=255;
int menuExplanationsColor_2=255;
int menuExplanationsColor_3=255;
 
 
 

void setup() {
  ucg.begin(UCG_FONT_MODE_SOLID);
  ucg.clearScreen();
  ucg.setRotate90();
  ucg.setFont(ucg_font_fub30_hr);
  ucg.setFont(ucg_font_lucasfont_alternate_hr);
  ucg.setFontPosTop();
  ucg.setPrintPos(0,0);
  
}

void loop() {
  //drawMenuLine();
  drawDepth();

}
void drawMenuLine(){
ucg.setColor(menuLineColor_1,menuLineColor_2,menuLineColor_3);
 ucg.drawLine( 0, 55, 160,55);
 ucg.drawLine(0,110,160,110);
 ucg.drawLine(82,0,82,110);
 //ucg.drawLine(120,0,120,55);
 
}
void drawDepth(){
  ucg.setFont(ucg_font_lucasfont_alternate_hr);
  ucg.setPrintPos(0,0);
  ucg.setColor(menuExplanationsColor_1,menuExplanationsColor_2,menuExplanationsColor_3);
  ucg.print("Depth");

  ucg.setFont(ucg_font_fub30_hr );
  ucg.setPrintPos(0,13);
  ucg.setColor(0, 255, 0);
  ucg.print("39,7");
}
