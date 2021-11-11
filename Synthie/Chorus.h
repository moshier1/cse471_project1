#pragma once
#include "Instrument.h"
#include "SineWave.h"
#include "ADSR.h"
#include "Effect.h"
class CChorus:public CEffect
{
public:
	double Process(double frameIn, double time, double* delay, int queuesize, int queueLoc) override;
private:

};

