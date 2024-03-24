void setup(){
  Serial.begin(9600);
  pinMode(D0,OUTPUT);
}

void loop(){
  char c;
  if(Serial.available()>0){   // 수신 버퍼에 저장된 바이트 수 반환
    c = Serial.read();	      // 수신 버퍼에서 한 바이트 읽어옴
    if(c=='a'){
      digitalWrite(D0, HIGH);
    }else{
      digitalWrite(D0, LOW);
    }
  }
}
