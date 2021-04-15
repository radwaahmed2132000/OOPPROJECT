#pragma once

#include "Action.h"

class InputDiceValueAction : public Action
{
	
	// No parameters for this action

public:
	InputDiceValueAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~InputDiceValueAction();
};
