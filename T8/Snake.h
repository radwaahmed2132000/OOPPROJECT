#pragma once
#include "GameObject.h"
#include "Ladder.h"

class Snake :public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the Snake's "Start Cell Position"
	int check1;
	CellPosition endCellPos, startCellPos; // here is the Snake's End Cell Position
	
public:

	Snake(CellPosition& startCellPos,CellPosition& endCellPos); // A constructor for initialization

	virtual bool IsOverlapping(GameObject* newobj);

	virtual void Draw(Output* pOut) const; // Draws a Snake from its start cell to its end cell

	int getcheck1();//getcheck to use it to print message if is overlapping 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to Snake's end cell

	CellPosition GetStartPosition() const; // A getter for the endCellPos data member

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	virtual void Save(ofstream &OutFile , int Type);

	virtual void Load (ifstream &InFile);
	
	virtual ~Snake(); // Virtual destructor
};


