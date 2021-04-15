#include "CardEight.h"

#include "ApplicationManager.h"
#include <fstream>

CardEight::CardEight(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number (8 here)
}

CardEight::~CardEight(void)
{

}

//void CardEight::ReadCardParameters()
//{
//		// no parameters to read from user
//
//}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
		
	pPlayer->setIsExecuted(false);

	//// 1- Call Apply() of the base class Card to print the message that you reached this card number
	//Card:: Apply(pGrid, pPlayer);

	////Get a Pointer to the Input / Output Interfaces from the Grid

	//Input* pIn = pGrid->GetInput();
	//Output* pOut = pGrid->GetOutput();

	//pPlayer->Move(pGrid,0);

	//
	//
	//delete [] pIn;
	//delete [] pOut;
}

void CardEight:: Save(ofstream &OutFile , int Type)
{
	if(Type == 3)
	{
	Card::Save(OutFile , Type);
	OutFile << endl;
	}
}

void CardEight:: Load (ifstream &InFile)
{
	//Card:: Load(InFile);
}