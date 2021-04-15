
#pragma once

#include "Card.h"

// [ CardFive ] Summary:
// Its Apply() Function: Move forward the same number of steps that you just rolled.
// Its Parameters: no parameters.
class CardFive :	public Card
{
	// CardFive has no Parameters.

public:
	CardFive(const CellPosition & pos); // A Constructor takes card position

	/*virtual void ReadCardParameters();*/

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFive on the passed Player
	                                                  // by moving the player forward the same number of steps that he just rolled
	
	virtual void Save(ofstream &OutFile , int Type);
	virtual void Load (ifstream &InFile);

	virtual ~CardFive(); // A Virtual Destructor
};

