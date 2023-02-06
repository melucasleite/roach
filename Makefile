compile:
	arduino-cli compile -b arduino:avr:uno Firmware
upload:
	arduino-cli upload Firmware --port /dev/ttyACM0 --fqbn arduino:avr:uno
flash:
	make compile & make upload