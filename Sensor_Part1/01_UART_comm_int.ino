void setup(){
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}
int i;
  
void loop(){
  
  if(Serial.available()>0){   // 수신 버퍼에 저장된 바이트 수 반환
    i = Serial.parseInt();    // 시리얼로부터 정수값 읽어옴
    Serial.println(i);

    if(i>100){
      Serial.println("Wow!");
      digitalWrite(13, HIGH);
      delay(1000);
    }
  }
}
