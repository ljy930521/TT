const int RLED=9; //9번 핀을 사용하는 빨간색 RLED 상수 정의 
const int LIGHT=0; //아날로그 입력 0번 핀을 사용하는 포토레지스터 LIGHT 상수 정의 
const int MIN_LIGHT=200; //최저 조도값 200을 저장한 MIN_LIGHT 상수 정의 
const int MAX_LIGHT=900; //최대 조도값 900을 저장한 MAX_LIGHT 상수 정의
int val=0; //포토레지스터가 읽은 현재 조도값을 저장하는 val 변수 선언
void setup() 
{ 
  pinMode(RLED, OUTPUT); //RLED 핀을 출력으로 지정 }
}
void loop() 
{ 
  val=analogRead(LIGHT); //포토레지스터에서 현재 조도값 읽음 
  val=map(val, MIN_LIGHT, MAX_LIGHT, 255, 0); //현재 조도값을 8비트의 값으로 매핑 
  val=constrain(val, 0, 255); //매핑된 조도값을 0-255 사이의 값으로 제한 
  analogWrite(RLED, val); //조도값에 따라 LED 밝기를 조정 
}
