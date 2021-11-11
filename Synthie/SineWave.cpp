#include "pch.h"
#include "SineWave.h"

CSineWave::CSineWave()
{
	m_phase = 0;
	m_amp = 0.1;
	m_freq = 440;
}

void CSineWave::Start()
{
    m_phase = 0;
}

bool CSineWave::Generate()
{
    // phase in cycles for this, not radians
    m_frame[0] = m_amp * sin(m_phase * 2 * PI);
    m_frame[1] = m_frame[0];

    m_phase += m_freq * GetSamplePeriod();

    return true;
}
