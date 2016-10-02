#include "cpuInfoParser.h"

cpuInfoParser::cpuInfoParser(string titleLine)
{
	istringstream title(titleLine);

	string date;

	title >> date >> date >> date >> date;

	today = timeParser.calNTPUnix(date);
}

void cpuInfoParser::zeroMem(cpuInfo *info)
{
	memset(info, 0, sizeof(*info));
}

int cpuInfoParser::insertCpuInfo(string info)
{
	if (info.empty())
	{
		return -1;
	}

	// Remove title line and "LINUX RESTART" line
	if (info.find("Linux") != string::npos || info.find("RESTART") != string::npos || info.find("Average") != string::npos)
	{
		return -1;
	}

	if (info.find("CPU") != string::npos)
	{
		return -1;
	}

	istringstream input(info);

	cpuInfo cpu;
	zeroMem(&cpu);

	const int itemCnt = 12;

	string substring[itemCnt];
	for (int i = 0; i < itemCnt; ++i)
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