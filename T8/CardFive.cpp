#include "CardFive.h"
#include <fstream>

CardFive::CardFive(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (5 here)
}

CardFive::~CardFive(void)
{
}

//void CardFive::ReadCardParameters()
//{
//		// no parameters to read from user
//
//}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
		

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card:: Apply(pGrid, pPlayer);
	pPlayer->SetTurnCount(pPlayer->GetTurnCount()-1);
	// 2- move forward the same number of steps that you just rolled
	pPlayer->Move(pGrid,pPlayer->GetRolledDiceNum());

}

void CardFive:: Save(ofstream &OutFile , int Type)
{
	if(Type ==3 )
	{
	Card:: Save(OutFile , Type);
	OutFile <<endl;
	}
}

void CardFive:: Load (ifstream &InFile)
{
	//Card:: Load(InFile);
}