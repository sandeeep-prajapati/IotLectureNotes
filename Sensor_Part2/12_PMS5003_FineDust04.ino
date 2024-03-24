
//#include <SoftwareSerial.h>
//#include <Wire.h> 

#define LENG 31   //0x42 + 31 bytes equal to 32 bytes
unsigned char buf[LENG];

int PM01Value=0;          //초초미세먼지  //define PM1.0 value of the air detector module
int PM2_5Value=0;         //초미세먼지    //define PM2.5 value of the air detector module
int PM10Value=0;          //미세먼지      //define PM10 value of the air detector module


//WiFiServer server(80);
void setup()
{
   Serial.begin(9600);
   Serial.println("begin!");
   Serial.flush();
   Serial.swap();
   Serial.flush();
//   static unsigned long OledTimer=millis();  

}//setup end


void loop()
{

  if(Serial.find(0x42)){    //0x42를 찾는다
    Serial.readBytes(buf,LENG);
    if(buf[0] == 0x4d){
      if(checkValue(buf,LENG)){
        // PM01Value=transmitPM01(buf); //count PM1.0 value of the air detector module
        PM2_5Value=transmitPM2_5(buf);//count PM2.5 value of the air detector module
        PM10Value=transmitPM10(buf); //count PM10 value of the air detector module 
//        PM2_5Value=PM2_5Value;
      }
    }
  }
   Serial.swap();
   Serial.flush();
   Serial.print(PM2_5Value);
   Serial.print(" ");
   Serial.println(PM10Value);
   delay(1000);
   Serial.swap();   
} //loop end


//PMS5003 데이터를 체크하는 함수
char checkValue(unsigned char *thebuf, char leng){  
  char receiveflag=0;
  int receiveSum=0;
  for(int i=0; i<(leng-2); i++){
  receiveSum=receiveSum+thebuf[i];
  }
  receiveSum=receiveSum + 0x42;
 
  if(receiveSum == ((thebuf[leng-2]<<8)+thebuf[leng-1])){  //check the serial data   
    receiveSum = 0;
    receiveflag = 1;
  }
  return receiveflag;
} //char checkValue(unsigned char *thebuf, char leng) end

int transmitPM01(unsigned char *thebuf){
  int PM01Val;
  PM01Val=((thebuf[3]<<8) + thebuf[4]); //count PM1.0 value of the air detector module
  return PM01Val;
}//int transmitPM01(unsigned char *thebuf) end

//transmit PM Value to PC
int transmitPM2_5(unsigned char *thebuf){
  int PM2_5Val;
  PM2_5Val=((thebuf[5]<<8) + thebuf[6]);//count PM2.5 value of the air detector module
  return PM2_5Val;
}// int transmitPM2_5(unsigned char *thebuf) end

//transmit PM Value to PC
int transmitPM10(unsigned char *thebuf){
  int PM10Val;
  PM10Val=((thebuf[7]<<8) + thebuf[8]); //count PM10 value of the air detector module  
  return PM10Val;
}// int transmitPM10(unsigned char *thebuf) end
