#include "pch.h"
#include "RingMod.h"

double CRingMod::Process(double frameIn, double time, double* delay, int queuesize, int queueLoc)
{
	if (GetDry() == 1) { return frameIn; }
	int a = queueLoc % (int)GetSampleRate();
	int freq = 10;
	return frameIn * sin(2 * PI * freq * queueLoc / (GetSampleRate() + 1) + time);
}