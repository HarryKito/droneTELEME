import socket
"""
    실험 결론. {CUAV社 Wifi 모듈형 드론 텔레메트리 기준}
        Wifi 모듈형 드론 텔레메트리의 경우 
        MAVLink 패킷만 송수신이 가능하며, 
        이외의 정형화 되지 않은 (일반 string)
        데이터는 송수신 하지 않는다.
"""

print("Start rcv data from telemetry!")

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(('', 14550))

while True:
    data, addr = sock.recvfrom(1024)
    print("RX:", data)