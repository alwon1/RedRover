import serial#imports commands for using serial ports
import re
import time
print("initilizing connection")
arduinoSerialData = serial.Serial('/dev/ttyUSB0',9600)
log = False
x=1
def ToArd(toard):#writes out the varibles value to the adrino
	arduinoSerialData.write((toard+"\n").encode())
	logfile(toard)

def screen():
	while(arduinoSerialData.inWaiting() > 0):
		print(arduinoSerialData.inWaiting())#reads data to console from adrino
		pnd = (arduinoSerialData.readline())
		logfile(pnd.decode('ASCII'))#we also create a log of the console as well as print to screen
		print(pnd.decode())
	print(arduinoSerialData.inWaiting())

def control():#switch for future use to modify script operation
	while x==1:
	#if (arduinoSerialData.inWaiting()>0):
		
		#FromArd()#need to test both Fromard and tfromard if both work change to tfromard
		#if log == True:
			#log(test)#note test is untill return fromArd is improved to tell use what log we are#writing
		#else:
		screen()
		#ToArd()
		y=True
		while arduinoSerialData.inWaiting()==0 and y ==True:#and not input():
			da=input()
			if da:
				y=False
				print("you made it to d")
				ToArd(da)
				time.sleep(0.01)
			#pass
	#control()

def log(name):
	log = open(name,'a')#before calling check in waiting also use regexp to pick between print and log
	log.write(('\n' + arduinoSerialData.readline()).decode('ASCII'))

def FromArd():
	if bool(re.search(r"?:--Log--",str(arduinoSerialData.readline()))):# search for the string --log-- to indicate the start of a log
		#perhaps turn into a while loop
		log = True
	elif bool(re.search(r"?:--endLog--",str(arduinoSerialData.readline()))):
		log = False

def logfile(lg):
	open("/home/pi/Desktop/console_log",'a').write("\n" + lg)

def tFromArd():#currently not used needs improvements
	if re.search(r"?:--Log--",str(arduinoSerialData.readline())):
		while not re.search(r"?:--endLog--",str(arduinoSerialData.readline())):
			log(test)# add detection of what log is beng given

control()

