#include "pch.h"
#include "Reverb.h"


void CReverb::SetNote(CNote* note)
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
            dur *= (1. / (m_bpm / 60.));

            SetDuration(dur);
            //SetDuration(value.dblVal);
        }

        else if (name == "wet")
        {
            // Same thing for the beats.
            value.ChangeType(VT_R8);
            m_wet = value.dblVal;
        }

        else if (name == "dry")
        {
            // Same thing for the beats.
            value.ChangeType(VT_R8);
            m_dry = value.dblVal;
        }

        else if (name == "delay")
        {
            // Same thing for the beats.
            value.ChangeType(VT_R8);
            m_delay = value.dblVal;
        }

    }

}