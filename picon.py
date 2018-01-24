import serial#imports commands for using serial ports
arduinoSerialData =serial.Serial('/dev/ttyACM0',9600)

def ToArd(toard):#writes out the varibles value to the adrino
	arduinoSerialData.write(toard)

def FromArd():
	while(arduinoSerialData.inWaiting()>0):#reads data to console from adrino
		print(arduinoSerialData.readline())

def control():
	FromArd()
	ToArd()
	control()
