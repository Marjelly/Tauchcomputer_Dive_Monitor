#include <SPI.h>
#include "Ucglib.h"
Ucglib_ST7735_18x128x160_SWSPI ucg(/*sclk=*/ 12, /*data=*/ 11, /*cd=*/ 9, /*cs=*/ 10, /*reset=*/ 8);

 

void setup() {
  ucg.begin(UCG_FONT_MODE_SOLID);
  ucg.clearScreen();
  ucg.setRotate90();
  ucg.setFont(ucg_font_fub30_hr);
  ucg.setFont(ucg_font_lucasfont_alternate_hr);
  ucg.setColor(0, 255, 0);
  ucg.setFontPosTop();
  ucg.setPrintPos(0,25);
}

void loop() {
  ucg.print("Depth");

}
   
