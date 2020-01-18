const int RedPin = 11;
const int GreenPin = 10;
const int BluePin = 9;

void setup() {
  //random으로 출력되는 숫자의 변경을 위해 seed 설정
  randomSeed(analogRead(A0));
  Serial.begin(9600);
}

void loop() {
  
  int Red = random(256);
  int Green = random(256);
  int Blue = random(256);
  analogWrite(RedPin, Red);
  analogWrite(GreenPin, Green);
  analogWrite(BluePin, Blue);
  delay(1000);
  
  Serial.print("Red : ");
  Serial.print(Red);
  Serial.print(", Green : ");
  Serial.print(Green);
  Serial.print(", Blue : "); 
  Serial.println(Blue); 
  
}
