//Arduino <-> NodeMCU UART 통신, ARDUINO 코드

#include <SoftwareSerial.h>
SoftwareSerial Arduino_S(5,6);  //(Rx, Tx)

void setup(){
  Arduino_S.begin(9600);
}

void loop(){
  int read_data;
  int write_data;
  
  if( Arduino_S.available() > 0){

    read_data = Arduino_S.read();
    
    if(read_data == 0){
      write_data = 100;
      Arduino_S.write(write_data);
    }
    if(read_data == 1){
      write_data = 50; 
      Arduino_S.write(write_data);
       
    }
  }
}
