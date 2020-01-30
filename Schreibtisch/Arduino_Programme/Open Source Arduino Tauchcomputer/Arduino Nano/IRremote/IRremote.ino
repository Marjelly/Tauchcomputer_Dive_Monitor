#include "IRremote.h"

int receiver = 2;  

 
IRrecv irrecv(receiver);      
decode_results results;       

void setup()    
{
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn(); 

} 


void loop()    
{
  if (irrecv.decode(&results))  

  {
    translateIR(); 
    irrecv.resume();  
  }  
} 
 
void translateIR() 
 

{

 // Serial.println(results.value);
  

  switch(results.value)

  {

  case 3772784863 : Serial.println(" 1"); break;
  case 3772817503: Serial.println(" 2");  break;
  case 3772801183: Serial.println(" 3");    break;
  case 3772780783: Serial.println(" 4");   break;
  case 3772813423: Serial.println(" 5"); break;
  case 3772797103: Serial.println(" 6");    break;
  case 3772788943: Serial.println(" 7");    break;
  case 3772821583: Serial.println(" 8");    break;
  case 3772805263: Serial.println(" 9");    break;
  case 3772811383: Serial.println(" 0");    break;

  
  

  default: 
    Serial.println(" other button   ");

  }// End Case

  

}
 
