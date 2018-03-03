
import serial#imports commands for using serial ports
import re
import time
import serial.tools.list_ports
s= serial.Serial
print("initilizing connection")
arduino_ports = [
	p.device
	for p in serial.tools.list_ports.comports()
	if 'Arduino'  in p.description
]
if not arduino_ports:
	raise IOError("No Arduino found")
elif len(arduino_ports)==1:
	arduinoSerialData = serial.Serial(arduino_ports[0],9600)

elif len(arduino_ports) > 1:
	for p in arduino_ports:
		print(p)
	print("select which device to connect to")
	arduinoSerialData = serial.Serial(arduino_ports[int(input())-1],9600)

print("Connected")
x = 1
u = False
def ToArd(toard):#writes out the varibles value to the adrino
	arduinoSerialData.write((toard + "\n").encode())
	logfile('s: ' + toard)

def screen(toScreen):
	log('console_Testlog',toScreen)
	print(toScreen)

def writeControl(rec,con):#conrols wether statment is writeen to screen or to log or filterd
	global u
	if rec == 1:
		u = True
	elif rec == 2:
		u = False
	elif rec == 3:
		if u == True:
			log('test',con)
		else:
			screen(con)

def control():#switch for future use to modify script operation
	while x == 1:
		while arduinoSerialData.inWaiting() > 0:
			recived = arduinoSerialData.readline().decode()
			writeControl(FromArd(recived),recived)

		#if arduinoSerialData.inWaiting() == 0:
			#ToArdSt = input()
			#if da:
				#y = False
				#ToArd(ToArdSt)
				#time.sleep(0.1)


def log(name,toWrite):
	with open("C:\\Users\\Allyn\\Desktop\\" + name + '.txt','a') as file:
		file.write('\n' + toWrite)

def FromArd(recived):
	if re.search(r"--log--", recived,re.IGNORECASE):
		return 1
	elif re.search(r"--endlog--",recived, re.IGNORECASE):
		return 2
	else:
		return 3


def logfile(lg):
	with open("C:\\Users\\Allyn\\Desktop\\New Text Document.txt",'a') as file:
		file.write("\n" + lg)

def tFromArd():#currently not used needs improvements
	if re.search(r"?:--Log--",str(arduinoSerialData.readline())):
		while not re.search(r"?:--endLog--",str(arduinoSerialData.readline())):
			log(test)# add detection of what log is beng given
control()
