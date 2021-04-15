#include "CardSix.h"
#include <fstream>

CardSix::CardSix(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (6 here)
}

CardSix::~CardSix(void)
{
}

//void CardSix::ReadCardParameters()
//{
//		// no parameters to read from user
//
//}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
		

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card:: Apply(pGrid, pPlayer);

	// 2- move backward the same number of steps that you just rolled
	//ReadCardParameters();
	pPlayer->SetTurnCount(pPlayer->GetTurnCount()-1);
	pPlayer->Move(pGrid,pPlayer->GetRolledDiceNum()*-1);
	
}

void CardSix:: Save(ofstream &OutFile , int Type)
{
	if(Type ==3 )
	{
	Card:: Save(OutFile , Type);
	OutFile <<endl;
	}
}

void CardSix:: Load (ifstream &InFile)
{
	//Card:: Load(InFile);
}