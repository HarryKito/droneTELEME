// Arduino Dec16 2025
// 실험 Device: Arduino Mega 2560

// Normal string 데이터 송수신 Test.
/*
  실험결과.
  - Wifi 텔레메트리가 아닌 UART 형태의 텔레메트리의 경우
  - Normal string으로도 문제없이 송수신 가능.

  -> 새로운 protocol 개발 가능.
*/


const char* msg =
  "Hello world 1234567890. "
  "Sungjae babo dayo chanwoo babo dayo Kim Kim Hellllllll wtf"
  "abcdefghijklmnopqrstuvwxyz !!!\r\n";

void setup()
{
  Serial.begin(115200);     // 디버그
  Serial1.begin(57600);     // CUAV Wi-Fi UART
}

void loop()
{
  Serial1.write(msg);
  delay(10);   // 10ms 간격 (초당 약 100회)
}
