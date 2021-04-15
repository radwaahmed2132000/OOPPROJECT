#include "CardFour.h"

#include "Snake.h"
#include "ApplicationManager.h"
#include <fstream>

CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (8 here)
}

CardFour::~CardFour(void)
{

}

void CardFour::ReadCardParameters()
{
	// no parameters to read from user

}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	Snake* pSnake = pGrid->GetNextSnake(position);
	//2-GetNextSnake To move Current player to it
	if (pSnake != NULL)
	{
		//3-updateplayercell if it exits
		pGrid->UpdatePlayerCell(pPlayer, pSnake->GetStartPosition());
		//4- apply ladder action 

		pSnake->Apply(pGrid, pPlayer);
	}



}

void CardFour::Save(ofstream& OutFile , int Type)
{
	Card:: Save(OutFile , Type);
	OutFile <<endl;
}

void CardFour:: Load (ifstream &InFile)
{
	//Card:: Load(InFile);
}