#pragma once

#include "Action.h"
class AddSnakeAction :public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	CellPosition startPos; // 1- The start position of the Snake
	CellPosition endPos;   // 2- The end position of the Snake
	bool exit1, exit2, exit3;
	// Note: These parameters should be read in ReadActionParameters()
public:
	AddSnakeAction(ApplicationManager* pApp);

	virtual void ReadActionParameters(); // Reads AddSnakeAction action parameters (startPos, endPos)

	virtual void Execute(); // Creates a new Snake Object 
							// then Sets this Snake object to the GameObject Pointer of its Cell


	virtual ~AddSnakeAction(); // Virtual Destructor
};


