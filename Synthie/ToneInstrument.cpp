#include "pch.h"
#include "ToneInstrument.h"
#include "Notes.h"

CToneInstrument::CToneInstrument(void)
{
    m_duration = 0.1;
}


void CToneInstrument::Start()
{
    m_sinewave.SetSampleRate(GetSampleRate());
    m_sinewave.Start();
    m_time = 0;
    
    // bind wave to envelope 
    m_adsr.SetSource(&m_sinewave);
    m_adsr.SetSampleRate(GetSampleRate());
    m_adsr.Start();
}


bool CToneInstrument::Generate()
{
    // Tell the component to generate an audio sample
    m_adsr.SetTime(m_time);
    m_adsr.SetDuration(m_duration);
    m_adsr.Generate();

    // Read the component's sample and make it our resulting frame.
    m_frame[0] = m_adsr.Frame(0);
    m_frame[1] = m_adsr.Frame(1);

    // Update time
    m_time += GetSamplePeriod();

    // We return true until the time reaches the duration.
    return m_time < m_duration;
}

void CToneInstrument::SetNote(CNote* note)
{
    // Get a list of all attribute nodes and the
    // length of that list
    CComPtr<IXMLDOMNamedNodeMap> attributes;
    note->Node()->get_attributes(&attributes);
    long len;
    attributes->get_length(&len);

    // Loop over the list of attributes
    for (int i = 0; i < len; i++)
    {
        // Get attribute i
        CComPtr<IXMLDOMNode> attrib;
        attributes->get_item(i, &attrib);

        // Get the name of the attribute
        CComBSTR name;
        attrib->get_nodeName(&name);

        // Get the value of the attribute.  A CComVariant is a variable
        // that can have any type. It loads the attribute value as a
        // string (UNICODE), but we can then change it to an integer 
        // (VT_I4) or double (VT_R8) using the ChangeType function 
        // and then read its integer or double value from a member variable.
        CComVariant value;
        attrib->get_nodeValue(&value);

        if (name == "duration")
        {
            value.ChangeType(VT_R8);
            // set duration to proper length in sec 
            double dur = value.dblVal;
            dur *= (1./(m_bpm/60.));

            SetDuration(dur);
            //SetDuration(value.dblVal);
        }

        else if (name == "note")
        {
            SetFreq(NoteToFrequency(value.bstrVal));
        }

    }

}