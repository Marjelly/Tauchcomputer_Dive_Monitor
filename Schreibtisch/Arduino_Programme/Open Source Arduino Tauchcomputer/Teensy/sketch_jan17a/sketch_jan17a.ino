#include "SPI.h"
#include "ILI9341_t3.h"

// For the Adafruit shield, these are the default.
#define TFT_DC  9
#define TFT_CS 10

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
ILI9341_t3 tft = ILI9341_t3(TFT_CS, TFT_DC);


void setup() {
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_YELLOW);
  tft.setTextSize(2);
  Serial.begin(9600);
}

void loop() {
  printLines();
  Serial.println(ILI9341_BLACK);
}
void printLines() {
  tft.drawLine(0, 0, 100, 100, 0x2FE0);

}
