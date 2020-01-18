void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);

}

void loop() 
{
  Serial.println(analogRead(A1));
  analogWrite(9,random(256));
  analogWrite(10,0);
  analogWrite(11,0);
  delay(analogRead(A1));
  analogWrite(11,random(256));
  analogWrite(10,0);
  analogWrite(9,0);
  delay(analogRead(A1));
  analogWrite(10,random(256));
  analogWrite(9,0);
  analogWrite(11,0);
  delay(analogRead(A1));
}
