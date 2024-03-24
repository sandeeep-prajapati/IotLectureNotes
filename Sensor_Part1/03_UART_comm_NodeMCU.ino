// NodeMCU  Arduino UART 통신
// NodeMCU 코드

#include <SoftwareSerial.h>  //SoftwareSerial 라이브러리사용
SoftwareSerial NodeMCU_S(D6,D5);  //(Rx, Tx)
int data;

void setup(){
  Serial.begin(9600);
  NodeMCU_S.begin(9600);
}

void loop(){
  NodeMCU_S.write(＇s＇);
  if(NodeMCU_S.available()>0){
    data = NodeMCU_S.read();
    Serial.println(data);
  }
}
