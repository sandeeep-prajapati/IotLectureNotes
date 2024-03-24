setup()
{
  pinMode(11, OUTPUT);
}

loop()
{
  for(int i = 0; i<=255; i++){
    analogWrite(11, i);
    delay(20);
   }
}
