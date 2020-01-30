#include "SPI.h"
#include "ILI9341_t3.h"

#include "font_Arial.h"

// For the Adafruit shield, these are the default.
#define TFT_DC  9
#define TFT_CS 10

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
ILI9341_t3 tft = ILI9341_t3(TFT_CS, TFT_DC);
//*******************Variablen******************************************************************************************************************
int lineColor = 0x2FE0;
int diveLineLength = 200;
int diveLineWidth = 200;
int diveLineStartX = 50;
int diveLineStartY = 20;
//**********************************************************************************************************************************************

void setup() {
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_YELLOW);
  tft.setTextSize(2);
  Serial.begin(9600);
  tft.setRotation(3);
}

void loop() {
  printLines();
  printDepth();

}
void printLines() {
  tft.drawLine((diveLineLength / 2) + diveLineStartX, diveLineStartY, (diveLineLength / 2) + diveLineStartX, diveLineWidth + diveLineStartY, lineColor);
  tft.drawLine(diveLineStartX, (diveLineWidth / 2) + diveLineStartY, diveLineLength + diveLineStartX, (diveLineWidth / 2) + diveLineStartY, lineColor);
  tft.drawLine(diveLineStartX, diveLineStartY, diveLineLength + diveLineStartX, diveLineStartY, lineColor);
  tft.drawLine(diveLineStartX, diveLineStartY, diveLineStartX, diveLineWidth + diveLineStartY, lineColor);
  tft.drawLine(diveLineLength + diveLineStartX, diveLineStartY, diveLineLength + diveLineStartX, diveLineWidth + diveLineStartY, lineColor);
  tft.drawLine(diveLineLength + diveLineStartX, diveLineStartY, diveLineLength + diveLineStartX, diveLineWidth + diveLineStartY, lineColor);
  tft.drawLine(diveLineLength + diveLineStartX, diveLineWidth + diveLineStartY, diveLineStartX, diveLineWidth + diveLineStartY, lineColor);
}
void printDepth() {
  tft.setFont(ILI9341_t3_font_t&);
  tft.setCursor(0, 0);
  tft.setTextColor(0xF81E);
  tft.setTextSize(4);
  for (int i = 0 ; i < 100; i++) {

    tft.setCursor(0, 0);

    tft.setTextColor(0xF81E);
    tft.print(i);
    delay(500);
    tft.setCursor(0, 0);
    tft.setTextColor(0);
    tft.print(i);
  }
}
