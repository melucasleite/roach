from evdev import InputDevice, categorize, ecodes
import serial
import time

print("ACGAM R1 - pad mapping")

#creates object 'gamepad' to store the data
gamepad = InputDevice('/dev/input/event2')
ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1)
ser.reset_input_buffer()


#button code variables (change to suit your device)
up = 308
down = 304
left = 307
right = 305

#loop and filter by event code and print the mapped label
for event in gamepad.read_loop():
    if event.type == ecodes.EV_KEY:
        if event.value == 1:
            if event.code == up:
                ser.write(b"308\n")
            elif event.code == down:
                ser.write(b"304\n")
            elif event.code == left:
                ser.write(b"307\n")
            elif event.code == right:
                ser.write(b"305\n")