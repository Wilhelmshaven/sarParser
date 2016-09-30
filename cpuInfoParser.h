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

class cpuInfoParser
{
public:

	// <timeStamp, info>
	map<unsigned long, cpuInfo> cpuResSum;

	int insertCpuInfo(string info);

	cpuInfoParser(string titleLine);

private:

	timeHandler timeParser;

	void zeroInfo(cpuInfo *info);

	//unsigned long getTodayTime(string clock, string AMorPM);

	//unsigned long calNTPUnix(string date);
	//unsigned long calNTP(string date);

	unsigned long today;
};