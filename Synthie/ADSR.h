#pragma once
#include "AudioNode.h"

// ADSR class, binds to audionode
class CADSR : public CAudioNode
{
public:
	CADSR();
	// set audionode
	void SetSource(CAudioNode*);
	// set current time
	void SetTime(double time) { m_time = time; }
	// set duration of note
	void SetDuration(double duration) { m_duration = duration; }
	// unused, declared because of purly virtual function in audionode
	void Start()override{}
	// generate sound with envelope 
	bool Generate()override;

private:
	double m_attack;
	double m_decay;
	double m_sustain;
	double m_release;
	double m_time;
	double m_duration;

	CAudioNode* m_source;
};

