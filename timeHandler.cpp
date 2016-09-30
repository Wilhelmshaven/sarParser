#include "timeHandler.h"

// NTPʱ����㣺����1900��1��1�գ���Windows��ʹ��
unsigned long timeHandler::calNTP(string date)
{
	const int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int day = stoi(date.substr(0, 2));
	int month = stoi(date.substr(3, 2));
	int year = stoi(date.substr(6, 4));

	unsigned long time = (year - 1900) * 365;
	for (int i = 1900; i < year; ++i)
	{
		if (i % 4 == 0 && i != 1900)++time;
	}

	for (int i = 0; i < month; ++i)time += daysInMonth[i];

	time += day - 1;

	time *= 86400;

	return time;
}

// NTPʱ����㣺����1970��1��1�գ���Unix��ʹ��
unsigned long timeHandler::calNTPUnix(string date)
{
	unsigned long time = calNTP(date);

	const unsigned long seventyYear = 2208988800;

	time -= seventyYear;

	if (time < 0)time = 0;

	return time;
}

//���㵱���ʱ��
unsigned long timeHandler::getTodayTime(string clock, string AMorPM)
{
	int hour = stoi(clock.substr(0, 2));
	int min = stoi(clock.substr(3, 2));
	int sec = stoi(clock.substr(6, 2));

	unsigned long time = sec + min * 60 + (hour % 12) * 3600;

	if (AMorPM == "PM")
	{
		time += 43200;
	}

	return time;
}