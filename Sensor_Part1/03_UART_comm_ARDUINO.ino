// NodeMCU  Arduino UART 통신
// Arduino 코드
#include <SoftwareSerial.h>
SoftwareSerial Arduino_S(5,6);  //(Rx, Tx)

void setup(){
  Arduino_S.begin(9600);
}

void loop(){
  int data=100;
  if(Arduino_S.available()>0){
    Arduino_S.write(data);
  }
}
