#pragma once
#include <thread>
#include <list>

class ThreatHelper
{
private: 
	int threadAmount = 0;
	int height = 0;
	int width = 0;
	int offset = 0;

public:
	ThreatHelper(int height, int width, int offset);
	ThreatHelper();
	~ThreatHelper();
};

