//***************************************************************************
// File name:  GiveBonusVisitor.cpp
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Visitor Pattern Example
// Purpose:    Demonstrate how the Visitor Pattern is implemented
//***************************************************************************

#include "WeirdEmployeeOutputVisitor.h"

//***************************************************************************
// Function:    visit
//
// Description: Visit the Worker.  Output to cout if it has an odd salary
//
// Parameters:  rcWorker - the worker to visit
//
// Returned:    None
//***************************************************************************
void WeirdEmployeeOutputVisitor::visit (Worker& rcWorker)
{
	if (rcWorker.getSalary () % 2 != 0)
	{
		std::cout << rcWorker << std::endl;
	}
}

//***************************************************************************
// Function:    visit
//
// Description: Visit the Manager.  Output to cout if it has an even salary
//
// Parameters:  rcTheMan - the manager to visit
//
// Returned:    None
//***************************************************************************
void WeirdEmployeeOutputVisitor::visit (Manager& rcTheMan)
{
	if (rcTheMan.getSalary() % 2 != 1)
	{
		std::cout << rcTheMan << std::endl;
	}
}
