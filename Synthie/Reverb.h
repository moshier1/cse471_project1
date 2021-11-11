#pragma once
#include "Instrument.h"
#include "SineWave.h"
#include "ADSR.h"
class CReverb:public CInstrument
{
public:
	void SetNote(CNote* note);
	void Start() {};
	bool Generate() { return 0; };
	void SetDuration(double d) { m_duration = d; }
private:
	double m_wet = 0;
	double m_duration=0;
	double m_dry = 0;
	double m_delay = 0;
};

