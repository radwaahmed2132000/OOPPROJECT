#pragma once
#include "Action.h"


class NewGameAction : public Action
{
	CellPosition* Cell[4];
	Player* pPlayer[4];
public:
	NewGameAction(ApplicationManager* pApp);// A Constructor
	
	virtual void ReadActionParameters(); // Reads DeleteGameObjectAction action parameters (deletePos)

	virtual void Execute(); // deletes Object 


	~NewGameAction(void); // Virtual Destructor
};
