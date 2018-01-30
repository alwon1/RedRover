import serial#imports commands for using serial ports
import re
import time
print("initilizing connection")
arduinoSerialData = serial.Serial('COM6',9600)#'/dev/ttyUSB0',9600)
log = False
x=1
txt=""
def ToArd(toard):#writes out the varibles value to the adrino
	arduinoSerialData.write((toard+"\n").encode())
	logfile(toard)

def screen():
	#while(arduinoSerialData.inWaiting() > 0):
	#print(arduinoSerialData.inWaiting())#reads data to console from adrino
	#pnd = (arduinoSerialData.readline())
	logfile(txt)#pnd.decode('ASCII'))#we also create a log of the console as well as print to screen
	print(txt)#.decode())
	#print(arduinoSerialData.inWaiting())

def control():#switch for future use to modify script operation
	while x==1:
	#if (arduinoSerialData.inWaiting()>0):
		while arduinoSerialData.inWaiting()>0:
			FromArd()#need to test both Fromard and tfromard if both work change to tfromard
			if log == True:
				print("you")
				log(test)#note test is untill return fromArd is improved to tell use what log we are#writing
			else:
				screen()
		#ToArd()
		y=True
		while arduinoSerialData.inWaiting()==0 and y ==True:#and not input():
			da=input()
			if da:
				y=False
				#print("you made it to d")
				ToArd(da)
				time.sleep(0.1)
			#pass
	#control()

def log(name):
	file = "C:\\Users\\Allyn\\Desktop\\"+name
	log = open(file,'a')#before calling check in waiting also use regexp to pick between print and log
	log.write('\n' + txt)

def FromArd():
	txt = str(arduinoSerialData.readline().decode('UTF-8'))
	if bool(re.search(r"--Log--", txt)):# search for the string --log-- to indicate the start of a log
		#perhaps turn into a while loop
		log = True
	elif bool(re.search(r"--endLog--",txt)):
		log = False

def logfile(lg):
	with open("C:\\Users\\Allyn\\Desktop\\New Text Document",'a') as file:
		file.write("\n" + lg)

def tFromArd():#currently not used needs improvements
	if re.search(r"?:--Log--",str(arduinoSerialData.readline())):
		while not re.search(r"?:--endLog--",str(arduinoSerialData.readline())):
			log(test)# add detection of what log is beng given

control()

