#include "cpuInfoParser.h"

cpuInfoParser::cpuInfoParser(string titleLine)
{
	istringstream title(titleLine);

	string date;

	title >> date >> date >> date >> date;

	today = timeParser.calNTPUnix(date);
}

//unsigned long cpuInfoParser::calNTP(string date)
//{
//	const int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//	int day = stoi(date.substr(0, 2));
//	int month = stoi(date.substr(3, 2));
//	int year = stoi(date.substr(6, 4));
//
//	unsigned long time = (year - 1900) * 365;
//	for (int i = 1900; i < year; ++i)
//	{
//		if (i % 4 == 0 && i != 1900)++time;
//	}
//
//	for (int i = 0; i < month; ++i)time += daysInMonth[i];
//
//	time += day - 1;
//
//	time *= 86400;
//
//	return time;
//}

//unsigned long cpuInfoParser::calNTPUnix(string date)
//{
//	unsigned long time = calNTP(date);
//
//	const unsigned long seventyYear = 2208988800;
//
//	time -= seventyYear;
//
//	if (time < 0)time = 0;
//
//	return time;
//}

void cpuInfoParser::zeroInfo(cpuInfo *info)
{
	info->idle = 0;
	info->iowait = 0;
	info->nice = 0;
	info->steal = 0;
	info->system = 0;
	info->user = 0;
}

//unsigned long cpuInfoParser::getTodayTime(string clock, string AMorPM)
//{
//	int hour = stoi(clock.substr(0, 2));
//	int min = stoi(clock.substr(3, 2));
//	int sec = stoi(clock.substr(6, 2));
//
//	unsigned long time = sec + min * 60 + (hour % 12) * 3600;
//
//	if (AMorPM == "PM")
//	{
//		time += 43200;
//	}
//
//	return time;
//}

int cpuInfoParser::insertCpuInfo(string info)
{
	if (info.empty())
	{
		return -1;
	}

	// Remove title line and "LINUX RESTART" line
	if (info.find("Linux") != string::npos || info.find("%user") != string::npos || info.find("RESTART") != string::npos || info.find("Average") != string::npos)
	{
		return -1;
	}

	istringstream input(info);

	cpuInfo cpu;
	zeroInfo(&cpu);

	string substring[9];
	for (int i = 0; i < 9; ++i)
	{
		input >> substring[i];
	}

	unsigned long timeStamp = timeParser.getTodayTime(substring[0], substring[1]) + today;

	cpu.idle = stod(substring[8]);
	cpu.iowait = stod(substring[6]);
	cpu.nice = stod(substring[4]);
	cpu.steal = stod(substring[7]);
	cpu.system = stod(substring[5]);
	cpu.user = stod(substring[3]);

	cpuResSum.insert(make_pair(timeStamp, cpu));

	return 0;
}