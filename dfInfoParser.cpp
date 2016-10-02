#include "dfInfoParser.h"

dfInfoParser::dfInfoParser()
{
}

void dfInfoParser::zeroMem(dfInfo *info)
{
	memset(info, 0, sizeof(*info));
}

int dfInfoParser::insertDfInfo(string info, unsigned long timeStamp)
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

	if (info.find("Filesystem") != string::npos)
	{
		return -1;
	}

	istringstream input(info);

	dfInfo df;
	zeroMem(&df);

	const int itemCnt = 6;

	string substring[itemCnt];
	for (int i = 0; i < itemCnt; ++i)
	{
		input >> substring[i];
	}

	df.fileSystem = substring[0];
	df.oneThousBlocks = stoll(substring[1]);
	df.used = stoll(substring[2]);
	df.available = stoll(substring[3]);
	df.usePercent = stod(substring[4]);
	df.mountedOn = substring[5];

	dfResSum.insert(make_pair(timeStamp, df));

	return 0;
}