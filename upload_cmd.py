import os
import serial
import time

APP_BUAD_RATE = 115200

ser = serial.Serial('COM10', APP_BUAD_RATE)
ser.write(b'\xF2')      # send update command
time.sleep(0.001)       # delay 1 ms to wait the command send finish
ser.close()             # close the uart, the following upload command will use it!

# upload by uart
os.system(r'/Path/To/avrdude -C/Path/To/avrdude.conf -vvvvv -V -patmega328p -carduino "-PCOM10" -b57600 -D "-Uflash:w:/Path/To/arduino_update.ino.hex:i')

# for examples
# os.system(r'C:\Users\UserName\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/bin/avrdude -CC:\Users\UserName\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/etc/avrdude.conf -vvvvv -V -patmega328p -carduino "-PCOM10" -b57600 -D "-Uflash:w:C:\Users\UserName\AppData\Local\Temp\arduino\sketches\32EE22C1C368D2B7491014A3DC21CE7B/arduino_update.ino.hex:i')
