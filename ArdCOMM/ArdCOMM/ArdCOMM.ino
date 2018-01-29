/*
Name:    ArdCOMM.ino
Created: 1/23/2018 8:52:45 PM
Author:  Allyn
*/
#include <Time.h>
#include <TimeLib.h>
String n, j;
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
		n = Serial.readString();
		j = String(minute() + ":" + second());
		if (minute() < 10)
		{
			if (second() < 10) {
				Serial.println(n + " 0" + minute() + ":" + "0" + second());
			}
			else
			{
				Serial.println(n + " 0" + minute() + ":" + second());
			}
		}
		else if (minute() == 0)
		{
			if (second() < 10)
			{
				Serial.println(n + " 00" + ":" + second());
			}
			else
			{
				Serial.println(n + " 00" + ":" + second());
			}
		}
		//Serial.println(n + minute() + ":" + second());
		log("testlog time:" + String(minute()) + ':' + String(second()));
	}

}
void log(String logo)
{
	Serial.println("--log--");
	Serial.println(logo);
	Serial.println("--endlog--");
}
