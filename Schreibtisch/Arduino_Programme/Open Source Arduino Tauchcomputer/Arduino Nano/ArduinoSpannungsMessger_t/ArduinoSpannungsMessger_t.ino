float voltage=0;
int analogVoltage;
void setup() {
  Serial.begin(9600);
  
  pinMode(A4,INPUT);

}

void loop() {
  
analogVoltage=analogRead(A4);
voltage=(analogVoltage*(5.0/1023.0));
Serial.println(voltage);
delay(100);
}
