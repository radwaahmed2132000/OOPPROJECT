#pragma once
#include "card.h"
class CardEleven :
	public Card
{
	static bool SaveC11;
    static int price,fees;
    static int numberofcards;
    static Player*owner;

public:

	CardEleven(const CellPosition & pos);
	 	virtual bool isrepeated();
		virtual void changeparameters(Grid * pGrid);

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	                                                  // by decrementing the player's wallet by the walletAmount data member
	
	static void setC11(bool ex);

	virtual void Save (ofstream &OutFile , int Type);
	virtual void Load (ifstream &InFile);

	virtual ~CardEleven(void);
};

