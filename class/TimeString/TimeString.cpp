/*
 Name:		TimeString.cpp
 Created:	3/2/2018 11:19:55 PM
 Author:	Allyn
 Editor:	http://www.visualmicro.com
*/

#include "TimeString.h"
#include "./arduino/Arduino.h"
#include "../TimeString/arduino/Stream.h"
#include <./Time/Time.h>
#include<./Time/TimeLib.h>

TimeString::TimeString(HardwareSerial *Serialobj)
{
	serial = Serialobj;
	//serial->begin();
}
String TimeString::GetDateTime(time_t t = now())
{
	return GetDate(t) + " " + GetTime();

}
String TimeString::GetTime(time_t t = now())
{
	String temp;
	switch (hour(t))
	{
	case 0:
		temp += "00";
		break;
	case 1:
		temp += ("0" + hour(t));
		break;
	default:
		temp += hour(t);
		break;
	}
	temp += ":";
	switch (minute(t))
	{
	case 0:
		temp += "00";
		break;
	case 1:
		temp += ("0" + minute(t));
		break;
	default:
		temp += minute(t);
		break;
	}
	temp += ":";
	switch (second(t))
	{
	case 0:
		temp += "00";
		break;
	case 1:
		temp += ("0" + second(t));
		break;
	default:
		temp += second(t);
		break;
	}

	return temp;
}
String TimeString::GetDate(time_t t = now())
{
	String temp;
	temp += year();
	temp += "/";
	switch (month(t))
	{
	case 0:
		temp += "00";
		break;
	case 1:
		temp += ("0" + month(t));
		break;
	default:
		temp += month(t);
		break;
	}
	temp += "/";
	switch (day(t))
	{
	case 0:
		temp += "00";
		break;
	case 1:
		temp += ("0" + day(t));
		break;
	default:
		temp += day(t);
		break;
	}

	return temp;
}


void TimeString::SetTime(bool fast = false)
{
	int y, m, d, h, mi, s;
	if (fast)
	{

	}
	else
	{
		serial->println("Enter The Year (YY)");
		SerialWait();
		y = serial->readStringUntil('\n').toInt();

		serial->println("Enter The Month (MM)");
		SerialWait();
		m = serial->readStringUntil('\n').toInt();

		serial->println("Enter The Day (DD)");
		SerialWait();
		d = serial->readStringUntil('\n').toInt();

		serial->println("Enter The Hour (hh)");
		SerialWait();
		h = serial->readStringUntil('\n').toInt();

		serial->println("Enter The Minute (mm)");
		SerialWait();
		mi = serial->readStringUntil('\n').toInt();

		serial->println("Enter The second (ss)");
		SerialWait();
		s = serial->readStringUntil('\n').toInt();

		setTime(h, mi, s, d, m, y);

	}
}


void TimeString::SerialWait()
{
	while (!serial->available())
	{

	}
}