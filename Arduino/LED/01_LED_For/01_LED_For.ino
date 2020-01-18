void setup() {
  // put your setup code here, to run once:
pinMode(3, OUTPUT);
}

void loop() {
  for (int i=0;i<255;i++)
  {
    analogWrite (3,i);
    Serial.println(i);
    delay(20);
  }
    for (int i=255;i>=0;i--)
  {
    analogWrite (3,i);
    Serial.println(i);
    delay(20);
  }
  delay(100);
}
