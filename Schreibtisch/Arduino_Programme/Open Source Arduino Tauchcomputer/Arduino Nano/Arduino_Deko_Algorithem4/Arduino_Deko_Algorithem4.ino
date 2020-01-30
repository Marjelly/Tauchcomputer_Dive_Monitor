
double b_1=0.5050;
double b_1b=0.5578;
double b_2=0.6514;
double b_3=0.7222;
double b_4=0.7825;
double b_5=0.8126;
double b_6=0.8434;
double b_7=0.8693;
double b_8=0.8910;
double b_9=0.9092;
double b_10=0.9222;
double b_11=0.9319;
double b_12=0.9403;
double b_13=0.9477;
double b_14=0.9544;
double b_15=0.9602;
double b_16=0.9653;


double a_1=1.2599;
double a_1b=1.1696;
double a_2=1.0000;
double a_3=0.8618;
double a_4=0.7562;
double a_5=0.6670;
double a_6=0.5933;
double a_7=0.5282;
double a_8=0.4701;
double a_9=0.4187;
double a_10=0.3798;
double a_11=0.3497;
double a_12=0.3223;
double a_13=0.2971;
double a_14=0.2737;
double a_15=0.2523;
double a_16=0.2327;

double t12_1=4.00;
double t12_1b=5.00;
double t12_2=8.00;
double t12_3=12.50;
double t12_4=18.50;
double t12_5=27.00;
double t12_6=38.30;
double t12_7=54.30;
double t12_8=77.00;
double t12_9=109.00;
double t12_10=146.00;
double t12_11=187.00;
double t12_12=239.00;
double t12_13=305.00;
double t12_14=390.00;
double t12_15=498.00;
double t12_16=635.00;

 
double Piig=0;      //Einatemdruck
double airp=1.01325;//Luftdruck
double Pamb=airp;//Umgebungsdruck
double PsH2o=0.063; //Sättigungsdampfdruck von Wasser
double fig=78.08;   //Anteil des Inertgases im Atemgemisch in %

double Nz=999;
double Nz_G=0;

double Pigt0_1=(airp-PsH2o)*(fig/100);
double Pigt0_1b=(airp-PsH2o)*(fig/100);
double Pigt0_2=(airp-PsH2o)*(fig/100);
double Pigt0_3=(airp-PsH2o)*(fig/100);
double Pigt0_4=(airp-PsH2o)*(fig/100);
double Pigt0_5=(airp-PsH2o)*(fig/100);
double Pigt0_6=(airp-PsH2o)*(fig/100);
double Pigt0_7=(airp-PsH2o)*(fig/100);
double Pigt0_8=(airp-PsH2o)*(fig/100);
double Pigt0_9=(airp-PsH2o)*(fig/100);
double Pigt0_10=(airp-PsH2o)*(fig/100);
double Pigt0_11=(airp-PsH2o)*(fig/100);
double Pigt0_12=(airp-PsH2o)*(fig/100);
double Pigt0_13=(airp-PsH2o)*(fig/100);
double Pigt0_14=(airp-PsH2o)*(fig/100);
double Pigt0_15=(airp-PsH2o)*(fig/100);
double Pigt0_16=(airp-PsH2o)*(fig/100);
 
double Pigt0[]={ Pigt0_1 , Pigt0_1b , Pigt0_2 , Pigt0_3 , Pigt0_4 , Pigt0_5 , Pigt0_6 , Pigt0_7 , Pigt0_8 , Pigt0_9 , Pigt0_10 , Pigt0_11 , Pigt0_12 , Pigt0_13 , Pigt0_14 , Pigt0_15 , Pigt0_16 };  //Inertgasdruck im Gewebe zu beginn der Expositionszeit tE
double tE=0;        //Einwirkzeit in min
double t12[]={ t12_1 , t12_1b , t12_2 , t12_3 , t12_4 , t12_5 , t12_6 , t12_7 , t12_8 , t12_9 , t12_10 , t12_11 , t12_12 , t12_13 , t12_14 , t12_15 , t12_16};    //Halbwärtszeit des Gewebes  
double PigtE[]={0.0,0.0 ,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
int   numGewebe=17;
double Pambtol=0;   //Von einem Gewebe noch Tolerierter Druck, bei dem noch keine Gasbasen auftreten
double PtTol=0;
double Pambtolmax=0;//Das Gewebe mit dem höchsten noch Tolerierter Druck, bei dem noch keine Gasbasen auftreten
double x=0; //Wert bei der Nullzeitberechnung
double y=0; //Wert bei der 2 Dekoberechnung
double a[]={ a_1 , a_1b , a_2 , a_3 , a_4 , a_5 , a_6 , a_7 , a_8 , a_9 , a_10 , a_11 , a_12 , a_13 , a_14 , a_15 , a_16}; //Gewebefaktoren
double b[]={ b_1 , b_1b , b_2 , b_3 , b_4 , b_5 , b_6 , b_7 , b_8 , b_9 , b_10 , b_11 , b_12 , b_13 , b_14 , b_15 , b_16}; //Gewebefaktoren 


void setup() {
  Serial.begin(9600);
  pinMode(A5,INPUT);
}
   

void loop() { 
  
  // Pamb=(analogRead(A5)/400)+airp;
  Pamb=2.0+airp;
   Dekogleichung1();
   Dekogleichung2_3();
 
   Serial.print("Pamb:");
   Serial.println(Pamb);
   Serial.print("Piig: ");
   Serial.println(Piig);
   Serial.print("Tauchzeit:");
   Serial.println(tE);
   Serial.println("Pambtolmax:");
   Serial.println(Pambtolmax);
   Serial.println("Nullzeit");
   Serial.println(Nz);
    
      
   tE=tE+1;
   
   delay(2000);
}
void DekodatenAuslesen(){
//Pamb=digitalRead(Drucksensor);
}

void Dekogleichung1(){  
  Piig=(Pamb-PsH2o)*(fig/100);  //Funktioniert
}

void Dekogleichung2_3(){
   
  Pambtolmax=0;
  Nz=999;
  for(int i=0;i<numGewebe;i++){
   
  
   PigtE[i]= Pigt0[i] + ((Piig - Pigt0[i]) * (1 - pow(2, (-tE/t12[i])))); //Funktioniert 
     
   
    
     
     
  
   // PtTol=Pamb*(1/b[i])+a[i];
    
    
    //Serial.println(t12[i]);
    Serial.println(i);
   // Serial.print("Pigt0:");
    //Serial.println(Pigt0[i],8);
    
   
  
  Pambtol=(PigtE[i]-a[i])*b[i];
  //Serial.println(Pambtol);
  
  if(Pambtol>Pambtolmax){
    Pambtolmax=Pambtol;
  }

x= (-1)*(airp/b[i]+a[i]-Pigt0[i])/(Piig-Pigt0[i])+1;
  
  if(x>0){
    
    Nz_G= (-1)* log(x)/log(2)*t12[i];
  }
    if(Nz_G<Nz){
      Nz=Nz_G;
      
      
    }
    Serial.print("Nullzeit Gewebe    ");
    Serial.println(Nz_G);
    
 
  

 Pigt0[i]=PigtE[i];
  
  } 
   
  
 
}

    
    
   
    
  
  

 
