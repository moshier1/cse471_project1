#include "pch.h"
#include "Chorus.h"
#include <cmath>

double CChorus::Process(double frameIn, double time, double* delay, int queuesize, int queueLoc)
{
    double sample = 0;
    double dry = frameIn;
    double out = 0;

    //m_delay = .1;

   // if(GetWet()>0)
   // {
    //    double a=0;
    //    sample = a;
    //}
    if (GetDry() == 1) { return frameIn; }

    int delayLoc = (((queuesize + queueLoc) - int(GetDelay() * GetSampleRate()))) % queuesize;
    double wet = delay[delayLoc] * sin(asin(GetDry()*.1) +time);
    out = wet * GetWet()+dry*GetDry();
    //out=wet;
    //out = delay[delayLoc];
    return out;
}