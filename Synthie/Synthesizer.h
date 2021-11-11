#pragma once

#include <list>
#include <vector>
#include "Instrument.h"
#include "msxml2.h"
#include "Note.h"
#include "Reverb.h"
#include "Chorus.h"
#include"Flanger.h"
#include "RingMod.h"

using namespace std;

class CSynthesizer
{
public:
	// constructor
	CSynthesizer();

	~CSynthesizer();
	// clear
	void Clear();

	// open score
	void OpenScore(CString& filename);

	//! Number of audio channels
	int GetNumChannels() { return m_channels; }

	//! Sample rate in samples per second
	double GetSampleRate() { return m_sampleRate; }

	//! Sample period in seconds (1/samplerate)
	double GetSamplePeriod() { return m_samplePeriod; }

	//! Set the number of channels
	void SetNumChannels(int n) { m_channels = n; }

	//! Set the sample rate
	void SetSampleRate(double s) { m_sampleRate = s;  m_samplePeriod = 1.0 / s; }

	// start synth
	void Start(void);

	// generate one audio frame
	bool Generate(double* frame);

	//! Get the time since we started generating audio
	double GetTime() { return m_time; }

private:
	int		m_channels;
	double	m_sampleRate;
	double	m_samplePeriod;
	double m_time;

	double  m_bpm;                  //!< Beats per minute
	int     m_beatspermeasure;  //!< Beats per measure
	double  m_secperbeat;        //!< Seconds per beat

	// delay related
	int m_quesize = 220000;
	double m_delay[2][220000] = {0};
	int m_delayPos = 0;

	// list of instruments
	std::list<CInstrument*>  m_instruments;
	// notes
	std::vector<CNote> m_notes;

	int m_currentNote;          //!< The current note we are playing
	int m_measure;              //!< The current measure
	double m_beat;              //!< The current beat within the measure

	CReverb m_reverb;
	CChorus m_chorus;
	CFlanger m_flanger;
	CRingMod m_ringmod;

private:
	void XmlLoadScore(IXMLDOMNode* xml);
	void XmlLoadInstrument(IXMLDOMNode* xml);
	void XmlLoadNote(IXMLDOMNode* xml, std::wstring& instrument);
};

#pragma comment(lib, "msxml2.lib")

