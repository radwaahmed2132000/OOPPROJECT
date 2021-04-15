#pragma once
#include "Card.h"
class CardThree:public Card
{

	// CardEight has no Parameters.

public:
	CardThree(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters();

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardEight on the passed Player
													  // by Preventing the player from rolling the next turn.


	virtual void Save(ofstream& OutFile , int Type);
	virtual void Load (ifstream &InFile);

	virtual ~CardThree(); // A Virtual Destructor
};

