/*
Name:    ArdCOMM.ino
Created: 1/23/2018 8:52:45 PM
Author:  Allyn
*/
#include <RedBotSoftwareSerial.h>
#include <RedBot.h>
#include <Time.h>
#include <TimeLib.h>
RedBotMotors motors;
String n, j;
RedBotEncoder encode(A5,A6 );//put in actual pin number
// the setup function runs once when you press reset or power the board
void setup()
{
	Serial.begin(9600);
	setTime(12, 0, 0, 1, 1, 18);
}
void move(int speed, float ratio, bool direction)//ratio is left vs right
{
	if ((encode.getTicks(LEFT) <= 10) && (encode.getTicks(RIGHT) <= 10))
	{
		drive(speed, speed);
	}
	else
	{
		float cRatio = (encode.getTicks(LEFT) / encode.getTicks(RIGHT));
		if (cRatio > 1)//will need to add it as a background task
		{

		}
	}
	float cRatio=NULL;
	if (cRatio == NULL)
	{
	
	}
	;
	

}
void drive(int left, int right)
{
	motors.leftDrive(left);
	motors.rightDrive(right);
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