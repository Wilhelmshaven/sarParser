#pragma once

#include "commonHeaders.h"

class timeHandler
{
public:

	unsigned long getTodayTime(string clock, string AMorPM);

	unsigned long calNTPUnix(string date);

	unsigned long calNTP(string date);

	timeHandler(){};

	~timeHandler(){};
};