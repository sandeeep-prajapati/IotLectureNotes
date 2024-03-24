int sound_sensor = A0;
int led = D0;

void setup() {
  Serial.begin(9600);
  pinMode(sound_sensor, INPUT);
  pinMode(led, OUTPUT);
}
 
void loop() {
  int sound_signalLevel = analogRead(sound_sensor);
  Serial.println(sound_signalLevel);
 
  if(sound_signalLevel > 800){
    digitalWrite(led, HIGH);
  }
  else
    digitalWrite(led,LOW);
}
 
