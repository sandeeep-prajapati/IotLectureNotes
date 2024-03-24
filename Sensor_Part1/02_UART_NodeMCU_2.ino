//Arduino <-> NodeMCU UART 통신, NodeMCU 코드

#include <SoftwareSerial.h>  //SoftwareSerial 라이브러리사용
SoftwareSerial NodeMCU_S(D6,D5);  //(Rx, Tx)
int data;

void setup(){
  Serial.begin(9600);
  NodeMCU_S.begin(9600);
  pinMode(D1, INPUT);
}

void loop(){
  int swState = digitalRead(D1);
  Serial.print("swState = ");
  Serial.println(swState);
  
  if(swState ==LOW){
    NodeMCU_S.write(0);
  }else {
    NodeMCU_S.write(1);
  }
  
  if( NodeMCU_S.available() > 0 ){
    data = NodeMCU_S.read();
    Serial.println(data);
  }
  delay(1000);
}
