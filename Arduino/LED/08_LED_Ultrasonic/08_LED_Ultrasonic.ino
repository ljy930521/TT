#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(7, 8);  // Initialize sensor that uses digital pins 13 and 12.
int dis;
const int RLED=9; //9번 핀을 사용하는 파란색 BLED 상수 정의
const int YLED=10; //10번 핀을 사용하는 초록색 GLED 상수 정의
const int BLED=11; //11번 핀을 사용하는 빨간색 RLED 상수 정의
const int SPIKER=3;
void setup () {
    Serial.begin(9600);  
    pinMode(RLED, OUTPUT); //BLED를 출력으로 지정
    pinMode(YLED, OUTPUT); //GLED를 출력으로 지정
    pinMode(BLED, OUTPUT); //RLED를 출력으로 지정
    pinMode(SPIKER, OUTPUT);
}

void loop () 
{
    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    dis=distanceSensor.measureDistanceCm();
    Serial.println(dis);
    
    delay(500);
    if(dis<30)
  {
    if(dis>0 && dis<=10)
    {
      digitalWrite (RLED,1);
      digitalWrite (YLED,0);
      digitalWrite (BLED,0);
      digitalWrite (SPIKER,1);
      delay(100);
      digitalWrite (SPIKER,0);
    }
    else if(dis>10 && dis<=20) 
    {
      digitalWrite (RLED,0);
      digitalWrite (YLED,1);
      digitalWrite (BLED,0);
      digitalWrite (SPIKER,1);
      delay(200);
      digitalWrite (SPIKER,0);
    }

    else if(dis>20 && dis<=30)
    {
      digitalWrite (BLED,1);
      digitalWrite (RLED,0);
      digitalWrite (YLED,0);
      digitalWrite (SPIKER,1);
      delay(300);
      digitalWrite (SPIKER,0);
    }
    
    
  }

}
