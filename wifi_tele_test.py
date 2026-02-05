import socket
import time

HOST = '192.168.4.1'   # 텔메에서는 이 주소 쓴다는뎅
PORT = 5760

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(('', PORT)) # 일단 ALL 인페로 바인딩

print("UDP send/recv ready")

while True:
    # SEND
    msg = b'ping'
    sock.sendto(msg, (HOST, PORT))
    print("보냄:", msg)

    # RCV
    sock.settimeout(1.0)
    try:
        data, addr = sock.recvfrom(1024)
        print("받음:", data, "from", addr)
    except socket.timeout:
        print("수신 없음")

    time.sleep(1)

# 결론. 안됨 ㅋ ;
# +α
#  와이파이 텔메는 마브링크 메시지만 보내니까
#  송수신 시 상태 확인 LED에 반응 있었고, 마찬가지로 QGC(gcs)에도 바로 연동이 됨!!!
#  일반 패킷으로 받으면 GCS에서 해석 안되는 것은 당연..-> 마브링크로 보내야함. ㅇㅅㅇ

# - 끝 - 20251216