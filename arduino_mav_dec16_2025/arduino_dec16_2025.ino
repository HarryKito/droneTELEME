// Arduino Dec16 2025
// 실험 Device: Arduino Mega 2560

// Mavlink 하트비트 송신 테스트.
/*
  실험결과.
  실험 디바이스:
    - CUAV Wi-Fi 텔레메트리 모듈
    - CUAV P9 Telemetry Radio (UART 57600bps)
    - 그 외... 랩살에서 굴러다니는 텔레메트리 모듈들 전부 (성공)

  - 일반 시중에서 판매하는 대다수의
  - 텔레메트리에서 사용 가능할 것으로 판단.
  - 단, 특수 목적용이 아닌 드론용 텔레메트리에 한함.

*/

// 아래의 코드 사용 시 하트비트 코드로, 미션 플래너 및 QGC에서 수신 확인 가능.
#include <MAVLink.h>

void setup() {
  Serial1.begin(57600);
}

void loop() {
  // Send HEARTBEAT message to Serial once a second
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MAX_PACKET_LEN];

  mavlink_msg_heartbeat_pack(1, MAV_COMP_ID_AUTOPILOT1, &msg, MAV_TYPE_QUADROTOR, MAV_AUTOPILOT_GENERIC, MAV_MODE_FLAG_MANUAL_INPUT_ENABLED, 0, MAV_STATE_STANDBY);
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

  Serial1.write(buf, len);
  delay(1000);
}