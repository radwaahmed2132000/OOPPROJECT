#pragma once
#include "card.h"
class CardTen :public Card
{
	static bool SaveC10;
    static int price,fees;
    static int numberofcards;
    static Player*owner;

public:

	CardTen(const CellPosition & pos);
	bool isrepeated();
	virtual void changeparameters(Grid * pGrid);
	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	                                                  // by decrementing the player's wallet by the walletAmount data member

	static void setC10(bool ex);

	virtual void Save (ofstream &OutFile , int Type);
	virtual void Load (ifstream &InFile);

	virtual ~CardTen(void);
};

