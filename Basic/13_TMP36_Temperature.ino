//TMP36을 A0에 연결

void setup() {
  Serial.begin(115200);
}

void loop() {
  int rawValue = analogRead(A0);
  float voltage = rawValue *3.3 / 1024.0;

  Serial.print("raw value : ");
  Serial.print(rawValue);
  Serial.print("  voltage: ");
  Serial.println(voltage);

  delay(1000);
   
}
