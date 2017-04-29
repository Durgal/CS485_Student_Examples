//***************************************************************************
// File name:  WeirdEmployeeOutputVisitor.h
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Visitor Pattern Example
// Purpose:    Demonstrate how the Visitor Pattern is implemented
//***************************************************************************

#pragma once
#include "IEmployeeVisitor.h"
class WeirdEmployeeOutputVisitor :
	public IEmployeeVisitor
{
public:
	WeirdEmployeeOutputVisitor() = default;
	virtual ~WeirdEmployeeOutputVisitor() = default;

	void visit(Worker &rcWorker) override;
	void visit(Manager &rcTheMan) override;
};

