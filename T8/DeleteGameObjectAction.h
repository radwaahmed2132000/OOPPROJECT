#pragma once
#include "Action.h"


class DeleteGameObjectAction: public Action 
{
	CellPosition deletePos;

public:
	DeleteGameObjectAction(ApplicationManager *pApp);// A Constructor

	virtual void ReadActionParameters(); // Reads DeleteGameObjectAction action parameters (deletePos)
	
	virtual void Execute(); // deletes Object 
	                        
	
	virtual ~DeleteGameObjectAction(void); // Virtual Destructor
};

