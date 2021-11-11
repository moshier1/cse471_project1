#pragma once
#include "pch.h"
#include "Note.h"
#include "Instrument.h"
class CEffect:public CInstrument
{
public:
	virtual void SetNote(CNote* note);
	virtual void Start() {};
	virtual bool Generate() 
	{
		m_time += GetSamplePeriod();
		return m_time < m_duration;
	};
	bool Check() override { return false; }
	virtual void SetDuration(double d) { m_duration = d; }
	double GetWet() { return m_wet; }
	double GetDry() { return m_dry; }
	double SetWet(double in) { m_wet = in; }
	double SetDry(double in) { m_dry = in; }
	double GetDelay() { return m_delay; }
	double SetDelay(double in) { m_delay = in; }
	void SetTime(double t) override{ m_time = t; }
	virtual double Process(double frameIn, double time, double* delay, int queuesize, int queueLoc)=0;
	void Reset() override;
private:
	double m_wet = 0;
	double m_duration = 0;
	double m_dry = 1;
	double m_delay = 0;
	double m_time = 0;
};

