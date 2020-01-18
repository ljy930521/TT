

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(A0);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 720);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);// sets the servo position according to the scaled value
  Serial.println(analogRead(A0));
  delay(10);                           // waits for the servo to get there
}
