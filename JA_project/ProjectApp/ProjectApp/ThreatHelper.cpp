#include "pch.h"
#include "ThreatHelper.h"

ThreatHelper::ThreatHelper()
{
	this->threadAmount = 1;
}


ThreatHelper::ThreatHelper(int height, int width, int offset): height(height), width(width), offset(offset)
{
	this->threadAmount = 1;
}
ThreatHelper::~ThreatHelper()
{
}
