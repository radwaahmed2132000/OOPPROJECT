
#pragma once

#include "Card.h"

// [ CardTwo ] Summary:
// Its Apply() Function: increases the value of the passing player’s wallet by a value
// Its Parameters: The Wallet Value to increase --> put it as a "data member" and read it in ReadCardParameters()

class CardTwo :	public Card
{
	// CardTwo Parameters:
	int walletPlus; // the wallet value to increase to the player

public:
	CardTwo(const CellPosition & pos); // A Constructor takes card position

	virtual void SetDataTwo(Card*);  //setter data of card two
	virtual int GetDataTwo();  //getter data of card two
	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardTwo which is: walletPlus

	virtual void changeparameters(Grid * pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwo on the passed Player
	                                                  // by increasing the player's wallet by the walletPlus data member
	
	virtual void setCardParameter(int par);
	virtual int getCardParameter();

	virtual void Save (ofstream &OutFile , int Type);
	virtual void Load (ifstream &InFile);

	virtual ~CardTwo(); // A Virtual Destructor
};



