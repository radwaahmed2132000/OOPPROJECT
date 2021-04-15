#include "CardThree.h"
#include "Ladder.h"
#include "ApplicationManager.h"
#include <fstream>

CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (3 here)
}

CardThree::~CardThree(void)
{

}

void CardThree::ReadCardParameters()
{
	// no parameters to read from user

}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{


	// 1- Call Apply() of the base class Card to print the message that you reached this card number

	Card::Apply(pGrid, pPlayer);

	Ladder* pLadder = pGrid->GetNextLadder(position);
	//2-GetNextladder To move Current player to it
	if (pLadder != NULL)
	{
		pGrid->UpdatePlayerCell(pPlayer, pLadder->GetStartPosition());
		//3-updateplayercell if it exits
		pLadder->Apply(pGrid, pPlayer);
		//4- apply ladder action 


	}
	

}



void CardThree::Save(ofstream& OutFile , int Type)
{
	Card:: Save(OutFile , Type);
	OutFile <<endl;
}

void CardThree:: Load (ifstream &InFile)
{
	//Card:: Load(InFile);
}