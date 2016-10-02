#pragma once

#include "commonHeaders.h"
#include "timeHandler.h"

typedef struct memInfo
{
	unsigned long kbmemfree;
	unsigned long kbmemused;
	double memused;
	unsigned long kbbuffers;
	unsigned long kbcached;
	unsigned long kbcommit;
	double commit;
	unsigned long kbactive;
	unsigned long kbinact;
	unsigned long kbdirty;
};

class memInfoParser
{
public:
	// <timeStamp, info>
	map<unsigned long, memInfo> memResSum;

	int insertMemInfo(string info);

	memInfoParser(string titleLine);

private:

	timeHandler timeParser;

	void zeroMem(memInfo *info);

	unsigned long today;
};