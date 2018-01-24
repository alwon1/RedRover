/*
 Name:		ArdCOMM.ino
 Created:	1/23/2018 8:52:45 PM
 Author:	Allyn
*/
#include <TimeLib.h>
String n;
// the setup function runs once when you press reset or power the board
void setup() 
{
	Serial.begin(9600);
	setTime(12, 0, 0, 1, 1, 18);
}

// the loop function runs over and over again until power down or reset
void loop() 
{
	echo();
}

void echo()
{
	if (Serial.available())
	{
		n = Serial.read();
		String t = String(minute()+":" + second());
		Serial.println(n + minute() + ":" + second());
		log("testlog time:" + t);
	}

}
void log(String log)
{
	Serial.println("--log--");
	Serial.println(log);
	Serial.println("--endlog--");
}