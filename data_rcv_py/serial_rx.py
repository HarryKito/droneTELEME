import serial

PORT = "/dev/tty.usbserial-AU052L6X"
BAUD = 57600

ser = serial.Serial(
    PORT,
    BAUD
)

print("Listening on", PORT)

while True:
    data = ser.read(1024)
    if data:
        print(data.decode(errors="replace"), end="")

