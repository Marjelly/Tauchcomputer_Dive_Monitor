#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin();
  
}

void loop() {
  tempSensorRequest();
}

void tempSensorRequest(){
   sensors.requestTemperatures();
     Serial.println(sensors.getTempCByIndex(0));  
     }
