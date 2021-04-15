#pragma once

#include "GameObject.h"

class Ladder :	public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"
	
	int check1;
	CellPosition endCellPos, startCellPos; // here is the ladder's End Cell Position

public:

	Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization

	virtual bool IsOverlapping(GameObject* newobj) ; //prevent overlapping

	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	int getcheck1(); //getcheck to use it to print message if is overlapping 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	CellPosition GetStartPosition() const;  // A getter for the startCellPos data member

	virtual void Save(ofstream &OutFile , int Type);

	virtual void Load (ifstream &InFile);

	virtual ~Ladder(); // Virtual destructor
};

