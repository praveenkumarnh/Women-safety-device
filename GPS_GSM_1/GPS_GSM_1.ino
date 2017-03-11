#include<SoftwareSerial.h>
#include "TinyGPS++.h"
TinyGPSPlus gps1;
int once = 0;
SoftwareSerial GSM1(3,2);
SoftwareSerial GPS(10,11);

void setup() {
  Serial.begin(9600);
  GSM1.begin(9600);
  GPS.begin(9600);
}

void loop() {
  if(Serial.available()){
    sendGSM("72.49.14.9,19.02.39.2");
    }
    GPSData();
}

void GPSData(){
  String Raw = "";
    if(GPS.available()){
    char serialData = GPS.read();
    Raw += serialData;
  }
  Serial.print(Raw);
}

void sendGSM(String toSend){
if(Serial.available() && once==0){  
    Serial.println(" SENDING MESSAGE ");
    GSM1.println();
    GSM1.println("AT+CMGF=1");
    delay(1300);
    GSM1.println();
    GSM1.print("AT+CMGS=\"");
    GSM1.print("+919167172549");
    GSM1.println("\"");
    delay(1000);
    GSM1.print(toSend); 
    delay(500);
    GSM1.write(0x1A);
    GSM1.write(0x0D);
    GSM1.write(0x0A);
  }
  once++;
}

