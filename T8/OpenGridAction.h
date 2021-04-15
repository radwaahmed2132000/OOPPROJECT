#pragma once

#include "Action.h"
#include <fstream>

class OpenGridAction: public Action
{
	ifstream inputFile;
public:
	OpenGridAction(ApplicationManager *pApp); // A Constructor

	virtual void ReadActionParameters(); 
	
	virtual void Execute(); // opens grid
	                        
	

	virtual ~OpenGridAction();//  Virtual Destructor
};

