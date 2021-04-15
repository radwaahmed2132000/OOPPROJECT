
#pragma once
#include"Action.h"


class CopyCardAction: public Action
{

	
	CellPosition cardposition;
	  
	
public:
	
	CopyCardAction(ApplicationManager *pApp);

	
	virtual void ReadActionParameters(); // Reads AddCardAction action parameters (cardNumber, cardPosition)
	
	virtual void Execute();
	 virtual~CopyCardAction(void);
};

