#pragma once

#include "Action.h"
#include <fstream>

class SaveGridAction: public Action
{
	ofstream outputFile;
public:
	SaveGridAction(ApplicationManager *pApp); // A Constructor

	virtual void ReadActionParameters(); 
	
	virtual void Execute(); // saves grid
	                        
	

	virtual ~SaveGridAction(void);//  Virtual Destructor
};

