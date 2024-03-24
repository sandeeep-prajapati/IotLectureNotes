int water_pin = A0;      //수분수위센서 A0에 연결
int LED1 = 2;            // LED를 각각 디지털핀 2,3,4에 연결
int LED2 = 3;
int LED3 = 4;
 
void setup() {
  Serial.begin(9600);   // Serial monitor 구동 전원입력
  pinMode( A0,   INPUT); // A0핀을 입력으로 설정
  pinMode( 2,   OUTPUT); // 디지털핀 2,3,4를 출력으로 설정
  pinMode( 3,   OUTPUT);
  pinMode( 4,   OUTPUT);
}

void loop(){
  Serial.println(analogRead(A0));  // Serial monitor로 A0값을 보여줌
  delay(100);                       // 입력값을 보여주는데 0.1초 설정

  if(analogRead(A0) < 400){         // A0가 400이하면 모든 LED OFF
    digitalWrite( 2, LOW);
    digitalWrite( 3, LOW);
    digitalWrite( 4, LOW);
    delay(100);
  }
  
   else if( 400 < analogRead(A0) && analogRead(A0) < 500 ){
    digitalWrite( 2, HIGH);
    digitalWrite( 3, LOW);
    digitalWrite( 4, LOW);           // 400<A0<500이면 LED1 ON
    delay(100);
  }
  
   else if( 500 < analogRead(A0) && analogRead(A0) < 600){
    digitalWrite( 2, HIGH);          
    digitalWrite( 3, HIGH);
    digitalWrite( 4, LOW);            // 500<A0<600이면 LED1,LED2 ON
    delay(100);
  }
  
   else {
    digitalWrite( 2, HIGH);
    digitalWrite( 3, HIGH);
    digitalWrite( 4, HIGH);
    delay(100);                        // 이외 모든 경우 LED1,LED2,LED3 ON
  }
  
}
