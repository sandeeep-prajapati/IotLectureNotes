const int ADC_PIN = A0; //TMP36을 A0에 연결

int rawValue;
float voltage;
float tempC = 0.0f;
//float tempF;

void setup() {
  Serial.begin(115200);
}

void loop() {
  rawValue = analogRead(ADC_PIN);
  voltage = rawValue * (3.3 / 1024.0);
  tempC = voltage*100 - 50;
//tempF = (tempC *1.8)+32;

  Serial.print("raw value : ");
  Serial.print(rawValue);
  Serial.print("  voltage: ");
  Serial.print(voltage);
  Serial.print("  deg C: ");
  Serial.println(tempC);

  delay(1000);
   
}
