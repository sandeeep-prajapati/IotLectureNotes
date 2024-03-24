int inputPin = 4;  //GPIO4, 센서 시그널 D2에 연결
int ledPin = 16;    //LED D0에 연결
     
  
void setup() {  
   pinMode(inputPin, INPUT);
   pinMode(ledPin, OUTPUT);   
   Serial.begin(9600);    
}  
  
void loop(){ 
  delay(500);
  int valueRead = 0; 
  valueRead = digitalRead(inputPin);
  
  Serial.println(valueRead);  
  
  if (valueRead == HIGH) {  // 인체 감지시
      digitalWrite(ledPin, HIGH); // LED ON    
      Serial.println("Motion detected!");
   }else{
      digitalWrite(ledPin, LOW); // LED OFF  
      Serial.println("Normal state!");
   } 
} 
