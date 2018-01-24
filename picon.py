import serial#imports commands for using serial ports
import re
print("initilizing connection")
arduinoSerialData = serial.Serial('/dev/ttyACM0',9600)
log = False
def ToArd(toard):#writes out the varibles value to the adrino
	arduinoSerialData.write(toard)
	logfile(toard)

def screen():
	while(arduinoSerialData.inWaiting() > 0):#reads data to console from adrino
		pnd = (arduinoSerialData.readline())
		logfile(pnd)#we also create a log of the console as well as print to screen
		print(pnd)

def control(x):
	FromArd()
	if log == True:
		log(test)#note test is untill return fromArd is improved to tell use what log we are
           #writing
	ToArd()
	control()

def log(name):
	log = open(name,'a')#before calling check in waiting also use regexp to pick between print and log
	log.write('\n' + arduinoSerialData.readline())

def FromArd():
	if bool(re.search(r"?:--Log--",str(arduinoSerialData.readline()))):# search for the string --log-- to indicate the start of a log
		#perhaps turn into a while loop
		log = True
	elif bool(re.search(r"?:--endLog--",str(arduinoSerialData.readline()))):
		log = False

def logfile(lg):
	open("console_log",'a').write("\n" + lg)

def tFromArd():#currently not used needs improvements
	if re.search(r"?:--Log--",str(arduinoSerialData.readline())):
		while not re.search(r"?:--endLog--",str(arduinoSerialData.readline())):
			log(test)# add detection of what log is beng given
control()
