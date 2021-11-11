#include "pch.h"
#include "Flanger.h"

double RangeBoundD(double d)
{
    if (d < -32768)
        return -32768;
    else if (d > 32767)
        return 32767;

    return d;
}

double CFlanger::Process(double frameIn, double time, double* delay, int queuesize, int queueLoc)
{
    double dry = frameIn;
    double out = 0;

    //m_delay = .1;

    if (GetDry() == 1) { return frameIn; }
    double offset = GetSampleRate() * GetDelay();
    double lfo_freq = .25;
    int delayLoc = ((int(queuesize*2. + queueLoc+sin(time)*(GetSampleRate()*GetDelay())) - int(GetDelay() * GetSampleRate()))) % queuesize;
    //int delayLoc = int(queuesize + queueLoc-(offset*sin(2*PI*lfo_freq*(queueLoc%(int)GetSampleRate())/GetSampleRate())/2.+offset/2.))%queuesize;
    double wet = delay[delayLoc]; //* sin(time*100);
    out = wet * GetWet() + dry * GetDry();
    //out=wet;
    //out = delay[delayLoc];
    return out;
}
