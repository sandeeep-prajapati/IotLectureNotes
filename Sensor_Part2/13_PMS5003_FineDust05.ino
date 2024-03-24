#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <Wire.h> 
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <gfxfont.h>
#include <BlynkSimpleEsp8266.h>

#define LENG 31   //0x42 + 31 bytes equal to 32 bytes
#define OLED_RESET 0
#define WIDTH 120
unsigned char buf[LENG];

int PM01Value=0;          //초초미세먼지  //define PM1.0 value of the air detector module
int PM2_5Value=0;         //초미세먼지    //define PM2.5 value of the air detector module
int PM10Value=0;          //미세먼지      //define PM10 value of the air detector module
//tmp36 outpu is A0 pin

 //Adafruit_SSD1306 display(OLED_RESET);
 Adafruit_SSD1306 display(128,64,&Wire,OLED_RESET);
char auth[] = "";
char ssid[] = "";
char pass[] = "";

WiFiServer server(80);
void setup()
{
   Serial.begin(9600);
   Serial.swap();
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);   
   display.display();
   WiFi.begin(ssid, pass);  
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    if(Serial.find(0x42)){    //0x42를 찾는다
      Serial.readBytes(buf,LENG);
      if(buf[0] == 0x4d){
        if(checkValue(buf,LENG)){
          PM01Value=transmitPM01(buf); //count PM1.0 value of the air detector module
          PM2_5Value=transmitPM2_5(buf);//count PM2.5 value of the air detector module
          PM10Value=transmitPM10(buf); //count PM10 value of the air detector module 
          PM2_5Value=PM2_5Value;
        }//if(checkValue(buf,LENG)) end
      }//if(buf[0] == 0x4d) end
    }//if(Serial.find(0x42)) end
    
    static unsigned long OledTimer=millis();  
    if (millis() - OledTimer >=1000){  //1초가 지나면
      OledTimer=millis();
      if(PM2_5Value < 31){
        display.clearDisplay(); 
        display.setTextSize(1); 
        display.setCursor( 0, 1 );
        display.print("Dust");
        display.setCursor(0, 9 );
        display.print("Pm2.5    ");  
        display.setCursor(0, 18 );
        display.print("Condition    ");     
        display.setTextSize(2); 
        display.setCursor( display.width()/2 , 1 );
        display.print("Good");

        display.drawRect(0, 27, 120,5 , WHITE);  // bar graph의 외형을 그린다. (Y,X,넓이,높이,색)
        display.setTextSize(1); 
        display.setTextColor(WHITE);
        display.display();        
        display.fillRect(1, 28, PM2_5Value, 5, WHITE);           // 사각채우기 (Y,X,,넓이,높이,색)
        display.setCursor(display.width()/2, 18 );
        display.setTextSize(0.5); 
        //  display.print("Pm 2.5 : ");
        display.print(PM2_5Value);
        display.print(" ug/m3 ");
        display.display();
        delay(10);
      }else if(PM2_5Value < 81 && PM2_5Value > 30){
        display.clearDisplay(); 
        display.setTextSize(1); 
        display.setCursor( 0, 1 );
        display.print("Dust");
        display.setCursor(0, 9 );
        display.print("Pm2.5");  
        display.setCursor(0, 18 );
        display.print("Condition    ");  
        display.setTextSize(2); 
        display.setCursor( display.width()/2 , 1 );
        display.print("Nomal");

        display.drawRect(0, 27, 120,5 , WHITE);  // bar graph의 외형을 그린다. (Y,X,넓이,높이,색)
        display.setTextSize(1); 
        display.setTextColor(WHITE);
        display.display();
        display.fillRect(1, 28, PM2_5Value, 5, WHITE);           // 사각채우기 (Y,X,,넓이,높이,색)
        display.setCursor(display.width()/2, 18 );
        display.setTextSize(0.5); 
        // display.print("Pm 2.5 : ");
        display.print(PM2_5Value);
        display.print(" ug/m3 ");
        display.display();
        delay(10);
      }else if( PM2_5Value <101 && PM2_5Value > 80 ){
        display.clearDisplay(); 
        display.setTextSize(1); 
        display.setCursor( 0, 1 );
        display.print("Dust");
        display.setCursor(0, 9 );
        display.print("Pm2.5");  
        display.setCursor(0, 18 );
        display.print("Condition    ");  
        display.setTextSize(2); 
        display.setCursor( display.width()/2 , 1 );
        display.print("Bad");
        display.drawRect(0, 27, 120,5 , WHITE);  // bar graph의 외형을 그린다. (Y,X,넓이,높이,색)
        display.setTextSize(1); 
        display.setTextColor(WHITE);
        display.display();
        display.fillRect(1, 28, PM2_5Value, 5, WHITE);           // 사각채우기 (Y,X,,넓이,높이,색)
        display.setCursor(display.width()/2, 18 );
        display.setTextSize(0.5); 
        // display.print("Pm 2.5 : ");
        display.print(PM2_5Value);
        display.print(" ug/m3 ");
        display.display();
        delay(10);
      }else {
        display.clearDisplay(); 
        display.setTextSize(1); 
        display.setCursor( 0, 1 );
        display.print("Dust");
        display.setCursor(0, 9 );
        display.print("Pm2.5");  
        display.setCursor(0, 18 );
        display.print("Condition    ");  
        display.setTextSize(2); 
        display.setCursor( display.width()/2-10 , 1 );
        display.print("Danger");

        display.drawRect(0, 27, 120,5 , WHITE);  // bar graph의 외형을 그린다. (Y,X,넓이,높이,색)
        display.setTextSize(1); 
        display.setTextColor(WHITE);
        display.display();

        display.fillRect(1, 28, PM2_5Value, 5, WHITE);           // 사각채우기 (Y,X,,넓이,높이,색)
        display.setCursor(display.width()/2, 18 );
        display.setTextSize(0.5); 
        // display.print("Pm 2.5 : ");
        display.print(PM2_5Value);
        display.print(" ug/m3 ");
        display.display();
        delay(10);
      }
    }//if (millis() - OledTimer >=1000) end
   }//while (WiFi.status() != WL_CONNECTED) end
   Serial.println("");
   Serial.print("Connected to ");
   Serial.println(ssid);
   Serial.print("IP address: ");
   Serial.println(WiFi.localIP());
   server.begin();
   Serial.println("HTTP Server started!");

//   Blynk.config(auth); 
   Blynk.begin(auth,ssid,pass);
   delay(1000);
}//setup end

BLYNK_READ(V0) {
    Blynk.virtualWrite(V0, PM2_5Value);
}
  
void loop()
{
  WiFiClient client = server.available();
  Blynk.run();
  if(Serial.find(0x42)){    //0x42를 찾는다
    Serial.readBytes(buf,LENG);
    if(buf[0] == 0x4d){
      if(checkValue(buf,LENG)){
        // PM01Value=transmitPM01(buf); //count PM1.0 value of the air detector module
        PM2_5Value=transmitPM2_5(buf);//count PM2.5 value of the air detector module
        PM10Value=transmitPM10(buf); //count PM10 value of the air detector module 
        PM2_5Value=PM2_5Value;
      }
    }
  }
  static unsigned long OledTimer=millis();  
  if (millis() - OledTimer >=1000){  //1초가 지나면
    OledTimer=millis(); 
    if(PM2_5Value < 31){
      display.clearDisplay(); 
      display.setTextSize(1); 
      display.setCursor( 0, 1 );
      display.print("Dust");
      display.setCursor(0, 9 );
      display.print("Pm2.5    ");  
      display.setCursor(0, 18 );
      display.print("Condition    ");      
      display.setTextSize(2); 
      display.setCursor( display.width()/2 , 1 );
      display.print("Good");

      display.drawRect(0, 27, 120,5 , WHITE);  // bar graph의 외형을 그린다. (Y,X,넓이,높이,색)
      display.setTextSize(1); 
      display.setTextColor(WHITE);
      display.display();
     
      display.fillRect(1, 28, PM2_5Value, 5, WHITE);           // 사각채우기 (Y,X,,넓이,높이,색)
      display.setCursor(display.width()/2, 18 );
      display.setTextSize(0.5); 
      //  display.print("Pm 2.5 : ");
      display.print(PM2_5Value);
      display.print(" ug/m3 ");
      display.display();
      delay(10);
    }else if(PM2_5Value < 81 && PM2_5Value > 30){
      display.clearDisplay(); 
      display.setTextSize(1); 
      display.setCursor( 0, 1 );
      display.print("Dust");
      display.setCursor(0, 9 );
      display.print("Pm2.5");  
      display.setCursor(0, 18 );
      display.print("Condition    ");  
      display.setTextSize(2); 
      display.setCursor( display.width()/2 , 1 );
      display.print("Nomal");
      display.drawRect(0, 27, 120,5 , WHITE);  // bar graph의 외형을 그린다. (Y,X,넓이,높이,색)
      display.setTextSize(1); 
      display.setTextColor(WHITE);
      display.display();

      display.fillRect(1, 28, PM2_5Value, 5, WHITE);           // 사각채우기 (Y,X,,넓이,높이,색)
      display.setCursor(display.width()/2, 18 );
      display.setTextSize(0.5); 
      // display.print("Pm 2.5 : ");
      display.print(PM2_5Value);
      display.print(" ug/m3 ");
      display.display();
      delay(10);
    }else if( PM2_5Value <101 && PM2_5Value > 80 ){
      display.clearDisplay(); 
      display.setTextSize(1); 
      display.setCursor( 0, 1 );
      display.print("Dust");
      display.setCursor(0, 9 );
      display.print("Pm2.5");  
      display.setCursor(0, 18 );
      display.print("Condition    ");  
      display.setTextSize(2); 
      display.setCursor( display.width()/2 , 1 );
      display.print("Bad");
      display.drawRect(0, 27, 120,5 , WHITE);  // bar graph의 외형을 그린다. (Y,X,넓이,높이,색)
      display.setTextSize(1); 
      display.setTextColor(WHITE);
      display.display();
      display.fillRect(1, 28, PM2_5Value, 5, WHITE);           // 사각채우기 (Y,X,,넓이,높이,색)
      display.setCursor(display.width()/2, 18 );
      display.setTextSize(0.5); 
     // display.print("Pm 2.5 : ");
      display.print(PM2_5Value);
      display.print(" ug/m3 ");
      display.display();
      delay(10);
    }else {
      display.clearDisplay(); 
      display.setTextSize(1); 
      display.setCursor( 0, 1 );
      display.print("Dust");
      display.setCursor(0, 9 );
      display.print("Pm2.5");  
      display.setCursor(0, 18 );
      display.print("Condition    ");  
      display.setTextSize(2); 
      display.setCursor( display.width()/2-10 , 1 );
      display.print("Danger");
      display.drawRect(0, 27, 120,5 , WHITE);  // bar graph의 외형을 그린다. (Y,X,넓이,높이,색)
      display.setTextSize(1); 
      display.setTextColor(WHITE);
      display.display();
      display.fillRect(1, 28, PM2_5Value, 5, WHITE);           // 사각채우기 (Y,X,,넓이,높이,색)
      display.setCursor(display.width()/2, 18 );
      display.setTextSize(0.5); 
      // display.print("Pm 2.5 : ");
      display.print(PM2_5Value);
      display.print(" ug/m3 ");
      display.display();
      delay(10);
    }
    if ( client ) { 
      String dustString = String(PM2_5Value);
      Serial.println("new client");
      while( client.connected() ) {
        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println("Connection: close");
        client.println();                
        client.println("<!DOCTYPE html>");
        client.println("<html>");
        client.println("<head>");
        client.println("<title>MY FIRST WEB SERVER</title>");
        client.println("<script>");
        client.print("var webDustString=dustString");   
        client.println("function input(){");
        client.println("var input = document.getElementById('input').value;");
        client.println("temp = input;");
        client.println(" }");
        client.println("function output(){");
        client.println(" document.getElementById('output').value = temp;");
        client.println(" }");

  
        //client.println(dustString);
        //client.println("document.getElementById('dust').value = webDustString;");

        client.println("</script>");
        client.println("</head>");
        client.println("<body><center>");
        client.println("<h1>Hello from NodeMCU!</h1>");
       // client.println(dustString);
        client.println("<input type='text' id ='dust'><br>");
        client.println("<textarea='output'></textarea>");
        client.println("<button onclick ='input()'>input</button>");
        client.println("<button onclick ='input()'>output</button>") ;       
        client.println("<p>A web page from the NodeMCU Web Server. Wellcome^^</p>");
        client.println("</center></body>");
        client.println("</html>");
        break;
      }
    delay(1);       // give the web browser time to receive the data
    client.stop();  // close the connection
    Serial.println("client disconnected");
    }// if (client) end
  }
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
