#include"Action.h"
#pragma once
class PasteCardAction:public Action
{
	Card* pCard;
    CellPosition newcardposition;
public:
	PasteCardAction(ApplicationManager *pApp);
		
	virtual void ReadActionParameters(); // Reads AddCardAction action parameters (cardNumber, cardPosition)
	
	virtual void Execute();
	virtual~PasteCardAction(void);
};

