#pragma once
#include "AudioNode.h"
#include "Note.h"
class CInstrument :
    public CAudioNode
{
public:
    virtual void SetNote(CNote* note) = 0;
    virtual bool Check() { return true; }
    virtual void Reset() {}
    virtual void SetTime(double t) {}
    //virtual void SetBPM(double bpm) { CAudioNode::SetBPM(bpm); }
};

