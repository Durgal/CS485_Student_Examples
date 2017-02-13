//***************************************************************************
// File name:  PacString.cpp
// Author:     Chris Granat, Kyle Petska
// Date:       2/3/2017
// Class:      CS485
// Assignment: Dynamic Memory Lab
// Purpose:    Practice using raw pointers
//***************************************************************************


#include "PacString.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//***************************************************************************
// Constructor: PacString
//
// Description: default PacString constructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
PacString::PacString()
{

}

//***************************************************************************
// Constructor: PacString
//
// Description: copy constructor given a string
//
// Parameters:  pszString - a string to be copied
//
// Returned:    None
//***************************************************************************
PacString::PacString(const char * pszString)
{
	mpszData = new char[strlen(pszString)];

	if (nullptr != pszString)
	{
		strcpy(mpszData, pszString);
	}
}

//***************************************************************************
// Constructor: PacString
//
// Description: copy constructor given a PacString object
//
// Parameters:  rcData - the object to be copied
//
// Returned:    None
//***************************************************************************
PacString::PacString(const PacString & rcData)
{
	if (nullptr != rcData.mpszData)
	{
		mpszData = rcData.mpszData;
	}
}

//***************************************************************************
// Constructor: ~PacString
//
// Description: destructor for PacString
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************
PacString::~PacString()
{
	if (nullptr != mpszData)
	{
		//delete mpszData; // memory leaks :c
	}
}

//***************************************************************************
// Constructor: operator=
//
// Description: assignment operator overload
//
// Parameters:  rcData - the object to be copied
//
// Returned:    the instance
//***************************************************************************
/*
PacString& PacString::operator=(const PacString &rcData)
{
	mpszData = new char[strlen(rcData.mpszData)];

	strcpy(mpszData, rcData.mpszData);

	return *this;
}
// */

//***************************************************************************
// Constructor: operator=
//
// Description: assignment operator overload
//
// Parameters:  rcData - the object to be copied
//
// Returned:    the instance
//***************************************************************************
//*
PacString & PacString::operator=(PacString rcData)
{
	using std::swap;

	swap(mpszData, rcData.mpszData);

	return *this;
}
// */

//***************************************************************************
// Constructor: operator+=
//
// Description: assignment plus operator overload
//
// Parameters:  rcData - the object to be concatenated
//
// Returned:    the instance
//***************************************************************************
PacString & PacString::operator+=(const PacString & rcData)
{
	strcat(mpszData, rcData.mpszData);

	return *this;
}

//***************************************************************************
// Constructor: operator+
//
// Description: addition operator overload
//
// Parameters:  rcData - the object to be concatenated
//
// Returned:    the new instance
//***************************************************************************
PacString PacString::operator+(const PacString & rcData) const
{
	char * newString = strcat(mpszData, rcData.mpszData);

	PacString pcPacString(newString);

	return pcPacString;
}

//***************************************************************************
// Constructor: operator<<
//
// Description: out stream operator overload
//
// Parameters:  out    - the out stream object
//							rcData - display this objects data
//
// Returned:    out stream result
//***************************************************************************
std::ostream & operator<<(std::ostream & out, const PacString & rcData)
{
	if (nullptr != rcData.mpszData)
	{
		for (int i = 0; i < strlen(rcData.mpszData); i++)
		{ 
			out << *(rcData.mpszData + i);
		}
	}
	else
	{
		out << "nullptr";
	}

	return out;
}
