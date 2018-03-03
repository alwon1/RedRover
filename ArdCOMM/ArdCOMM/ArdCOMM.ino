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
	Serial.println("enter hour");
	SerialWait();
	int h = Serial.readString().toInt();
	
	Serial.println("enter min");
	SerialWait();
	int min = Serial.readString().toInt();

	Serial.println("enter sec");
	SerialWait();
	int sec = Serial.readString().toInt();

	Serial.println("enter day");
	SerialWait();
	int day = Serial.readString().toInt();

	Serial.println("enter month");
	SerialWait();
	int month = Serial.readString().toInt();

	Serial.println("enter year");
	SerialWait();
	int y = Serial.readString().toInt();
	setTime(h, min, sec, day, month, y);
	Serial.println(TimeStringx());
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
	test();
		
	
}
void SerialWait() {
	while (!Serial.available()) {
		delayMicroseconds(1);
	}
}
void SComOut(int comType,String message, int logNum=-1)// is ethier to screen or off
{
	
	switch (comType)
	{

	case 0:// log
		switch (logNum)//log identifyer
		{
			Serial.println("-Log-");
		case 0://test log
			Serial.println("-test-" + message);
			break;
		default://default log
			Serial.println(message);
			break;
		}
		Serial.println(message);
		break;
	case 1://screen
		Serial.println("-s-\n");
		Serial.println(message+TimeStringx());
		Serial.print("\n");
		break;
	default:
		Serial.println("-VIP-\nWarning invalid log file location");
		break;
	}
}
static String TimeStringx()
{
	String tempTime;// = dayShortStr(day());
	int x = day();
	tempTime += x;
	
	
}
static String SComIn()
{
	//if (Serial.available())
	//{

		char CurrentLetter;
		String tempString="";
		
			do
			{
				if (Serial.available())
				{
					CurrentLetter = Serial.read();
					
					tempString.concat(CurrentLetter);
					//Serial.println(tempString);
				}
			} while (CurrentLetter != '\n');
			return tempString;
			
		
	//}
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
void test()
{
	delay(100);
	Serial.print(dayStr(day()));
	Serial.print(" ");
	Serial.print(monthStr(month()));
	Serial.print(day());
	Serial.print(" ");
	Serial.print(year());
	Serial.print(" ");

	//Serial.println("xp");//TimeString());
	delay(100);
	/*while (Serial.available())
	{
		String x
		 = SComIn();
		Serial.println(x);
		SComOut(1, "testx123");
	*///}
}
void serialEvent()
{
	Serial.println(TimeStringx());
}