
const int RLED=9; //9번 핀을 사용하는 파란색 BLED 상수 정의
const int YLED=10; //10번 핀을 사용하는 초록색 GLED 상수 정의
const int GLED=11; //11번 핀을 사용하는 빨간색 RLED 상수 정의
const int i=0;
void setup()
{
pinMode(RLED, OUTPUT); //BLED를 출력으로 지정
pinMode(YLED, OUTPUT); //GLED를 출력으로 지정
pinMode(GLED, OUTPUT); //RLED를 출력으로 지정
}
void loop()
{


delay(500);
digitalWrite(GLED, HIGH);
delay(5000);
for(int i=0;i<=6;i++)
{
  if(i<6&&i>=0)
  {
    digitalWrite(GLED, HIGH);
    delay(500);
    digitalWrite(GLED, LOW);
    delay(500);
  }
  else if(i=6)
  {
    digitalWrite(YLED, HIGH);
    delay(2000);
  }
}
digitalWrite(YLED, LOW);
digitalWrite(RLED, HIGH);
delay(5000);
digitalWrite(RLED, LOW);
}
