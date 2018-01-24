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
	setTime(12, 0, 0, 1, 1, 11);
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
		Serial.println(n + minute() + ":" + second());
	}

}