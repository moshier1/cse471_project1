#include "pch.h"
#include "AudioNode.h"

CAudioNode::CAudioNode()
{
    m_frame[0] = 0;
    m_frame[1] = 0;
    m_sampleRate = 44100;
    m_samplePeriod = 1.0 / m_sampleRate;
    m_bpm = 120.;
}

CAudioNode::~CAudioNode()
{
    //delete m_frame;
}