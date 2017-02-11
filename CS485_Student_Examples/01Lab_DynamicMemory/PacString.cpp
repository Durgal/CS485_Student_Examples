#include "PacString.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

PacString::PacString()
{

}

PacString::PacString(const char * pszString)
{
	mpszData = new char[strlen(pszString)];

	if (nullptr != pszString)
	{
		// TODO: change this to strcpy
		for (int i = 0; i < strlen(pszString); i++)
		{
			mpszData[i] = pszString[i];
		}

		mpszData[strlen(pszString)] = '\0';
	}
}

PacString::PacString(const PacString & rcData)
{
	if (nullptr != rcData.mpszData)
	{
		mpszData = rcData.mpszData;
	}
}

PacString::~PacString()
{
	//std::cout << "destructor\n";

	// TODO: Fix this. Thanks Obama.

	//std::cout << strlen(mpszData) << '\n';

	//for (int i = 0; i < strlen(mpszData); i++)
	//{
		//delete (&mpszData)[i];
	//}
}

PacString & PacString::operator=(PacString rcData)
{
	using std::swap;

	swap(mpszData, rcData.mpszData);

	return *this;
}

PacString & PacString::operator+=(const PacString & rcData)
{
	char * newString = strcat(mpszData, rcData.mpszData);

	PacString pcPacString(newString);

	return pcPacString;
}

PacString PacString::operator+(const PacString & rcData) const
{
	char * newString = strcat(mpszData, rcData.mpszData);

	PacString pcPacString(newString);

	return pcPacString;
}

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
