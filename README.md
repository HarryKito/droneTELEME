# droneTELEME
Drone에 사용되는 텔레메트리 데이터 송수신 관련하여 신규 프로토콜 개발 건으로 실험중에 사용하였던 코드들.

# Structure of the test files
```bash
droneTELEME
    ├── README.md
    ├── arduino_mav_dec16_2025      # WIFI  Telem
    │   └── arduino_dec16_2025.ino
    │
    ├── arduino_string_dec16_2025   # UART Telem
    │   └── arduino_dec16_2025.ino
    │
    ├── data_rcv_py                 # PC data rcv Test
    │   ├── serial_rx.py
    │   └── wifi_rx.py
    │
    └── wifi_tele_test.py           # IO Test
```
