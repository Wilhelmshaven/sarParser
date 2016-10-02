#include "commonHeaders.h"
#include "timeHandler.h"

typedef struct cpuInfo
{
	double user;
	double nice;
	double system;
	double iowait;
	double steal;
	double idle;
};

#pragma once

class cpuInfoParser
{
public:

	// <timeStamp, info>
	map<unsigned long, cpuInfo> cpuResSum;

	int insertCpuInfo(string info);

	cpuInfoParser(string titleLine);

private:

	timeHandler timeParser;

	void zeroMem(cpuInfo *info);

	unsigned long today;
};