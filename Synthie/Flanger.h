#pragma once
#include "Effect.h"
class CFlanger :
    public CEffect
{
public:
    double Process(double frameIn, double time, double* delay, int queuesize, int queueLoc) override;
};

