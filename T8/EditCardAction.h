#pragma once
#include"Action.h"
class EditCardAction:public Action
{
	
	CellPosition cardposition;
public:
	EditCardAction(ApplicationManager *pApp);
	virtual void ReadActionParameters(); // Reads AddCardAction action parameters (cardNumber, cardPosition)
	
	virtual void Execute();
	~EditCardAction(void);
};

