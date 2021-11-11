#include "pch.h"
#include "ADSR.h"

// constructor
CADSR::CADSR()
{
	// default: .05 second AD envelope
	m_attack = 0.05;
	m_decay = 0;
	m_sustain = 0;
	m_release = 0.05;
	m_duration = 0;

	m_source = this;
}

// keep in range
double RangeBound(double d)
{
	if (d > 32767.)
	{
		return 32767.;
	}
	if (d < -32767.)
	{
		return -32767.;
	}
	return double(d);
}

// set audio node that this points at
void CADSR::SetSource(CAudioNode* source)
{
	m_source = source;
}

// generate sound with envelope applied
bool CADSR::Generate()
{
	bool valid = m_source->Generate();

	if (valid)
	{
		double amp = 1;
		
		// set attack amplitude
		if (m_time < m_attack)
		{
			amp = m_time / m_attack;
		}

		// too do: 
		//		add in decay
		//		sustain
		//		make this class less redundent with others... ie passing in time and duration
		//		add in options for exponential mode
		//		move each envelope section to a new function


		// set release amplitude 
		double release_start = (m_duration - m_release);
		if (m_time > release_start)
		{
			amp = (m_release-(m_time-release_start))/m_release;
		}

		m_frame[0] = RangeBound((m_source->Frame(0))*amp);
		m_frame[1] = RangeBound((m_source->Frame(1))*amp);
	}
	return valid;
}