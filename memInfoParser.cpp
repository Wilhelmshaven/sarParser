#include "memInfoParser.h"

memInfoParser::memInfoParser(string titleLine)
{
	istringstream title(titleLine);

	string date;

	title >> date >> date >> date >> date;

	today = timeParser.calNTPUnix(date);
}

void memInfoParser::zeroMem(memInfo *info)
{
	memset(info, 0, sizeof(*info));
}

int memInfoParser::insertMemInfo(string info)
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

	if (info.find("kbmemfree") != string::npos)
	{
		return -1;
	}

	istringstream input(info);

	memInfo mem;
	zeroMem(&mem);

	const int itemCnt = 12;

	string substring[itemCnt];
	for (int i = 0; i < itemCnt; ++i)
	{
		input >> substring[i];
	}

	unsigned long timeStamp = timeParser.getTodayTime(substring[0], substring[1]) + today;

	mem.kbmemfree = stol(substring[2]);
	mem.kbmemused = stol(substring[3]);
	mem.memused = stod(substring[4]);
	mem.kbbuffers = stol(substring[5]);
	mem.kbcached = stol(substring[6]);
	mem.kbcommit = stol(substring[7]);
	mem.commit = stod(substring[8]);
	mem.kbactive = stol(substring[9]);
	mem.kbinact = stol(substring[10]);
	mem.kbdirty = stol(substring[11]);

	memResSum.insert(make_pair(timeStamp, mem));

	return 0;
}