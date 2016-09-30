#include "commonHeaders.h"
//
//typedef struct memInfo
//{
//	unsigned long kbmemfree;
//	unsigned long kbmemused;
//	double memused;
//	unsigned long kbbuffers;
//	unsigned long kbcached;
//	unsigned long kbcommit;
//	double commit;
//	unsigned long kbactive;
//	unsigned long kbinact;
//	unsigned long kbdirty;
//};
//
//class memInfoParser
//{
//public:
//
//	map<unsigned long, memInfo> memResSum;
//
//	int insertCpuInfo(string info);
//
//	memInfoParser(string titleLine);
//
//private:
//
//	void zeroInfo(memInfo *info);
//
//	unsigned long getTodayTime(string clock, string AMorPM);
//
//	unsigned long calNTPUnix(string date);
//	unsigned long calNTP(string date);
//
//	unsigned long today;
//};