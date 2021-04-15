#pragma once
#include "card.h"
class CardNine :public Card
{
	 CellPosition Celltomoveto;
	// static int numberofcards;

public:
CardNine(const CellPosition & pos);
	virtual void changeparameters(Grid * pGrid);

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void SetDataNine(Card*);  //setter data of card nine
	virtual CellPosition GetDataNine();  //getter data of card nine

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	                                                  // by decrementing the player's wallet by the walletAmount data member

	virtual void setCardParameter(int par);
	virtual int getCardParameter();

	virtual void Save (ofstream &OutFile , int Type);
	virtual void Load (ifstream &InFile);

	virtual ~CardNine(void);
};

