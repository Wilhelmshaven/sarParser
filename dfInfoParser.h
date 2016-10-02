#pragma once
#include "commonHeaders.h"
#include "timeHandler.h"

typedef struct dfInfo
{
	string fileSystem;
	unsigned long long oneThousBlocks;
	unsigned long long used;
	unsigned long long available;
	double usePercent;
	string mountedOn;
};

class dfInfoParser
{
public:
	// <timeStamp, info>
	map<unsigned long, dfInfo> dfResSum;

	int insertDfInfo(string info, unsigned long timeStamp);

	dfInfoParser();

private:

	timeHandler timeParser;

	void zeroMem(dfInfo *info);
};