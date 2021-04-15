#pragma once

#include "Card.h"

// [ CardSeven ] Summary:
// Its Apply() Function: Gives the player another dice roll.
// Its Parameters: none.

class CardSeven :	public Card
{
	// CardSeven has no Parameters.

public:
	CardSeven(const CellPosition & pos); // A Constructor takes card position

	/*virtual void ReadCardParameters();*/

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSeven on the passed Player
	                                                  // by Giving the player another dice roll.
	
	virtual void Save (ofstream &OutFile , int Type);
	virtual void Load (ifstream &InFile);

	virtual ~CardSeven(); // A Virtual Destructor
};

