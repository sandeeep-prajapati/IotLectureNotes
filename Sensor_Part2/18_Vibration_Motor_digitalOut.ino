setup() 
{
  pinMode(13, OUTPUT);
}

loop()
{
  digitalWrite(13, HIGH);
  delay(3000);
  digitalWrite(13, LOW);
  delay(3000);
}
