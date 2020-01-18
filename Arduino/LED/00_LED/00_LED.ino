const int pinLED = 3;

void setup() {
  // put your setup code here, to run once:
pinMode(pinLED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(pinLED,HIGH);
delay(500);
digitalWrite(pinLED,LOW);
delay(500);
}
