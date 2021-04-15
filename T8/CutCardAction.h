#pragma once
#include"Action.h"
class CutCardAction:public Action
{
	
	CellPosition cardposition;
public:
	CutCardAction(ApplicationManager *pApp);
	virtual void ReadActionParameters(); // Reads AddCardAction action parameters (cardNumber, cardPosition)
	
	virtual void Execute();
	virtual~CutCardAction(void);
};

