
#pragma once

#include "Card.h"

// [ CardSix ] Summary:
// Its Apply() Function: Move backward the same number of steps that you just rolled.
// Its Parameters: no parameters.
class CardSix :	public Card
{
	// CardSix has no Parameters.

public:
	CardSix(const CellPosition & pos); // A Constructor takes card position

	//virtual void ReadCardParameters();

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSix on the passed Player
	                                                  // by moving the player backward the same number of steps that he just rolled
	
	virtual void Save (ofstream &OutFile , int Type);
	virtual void Load (ifstream &InFile);

	virtual ~CardSix(); // A Virtual Destructor
};

