#include "CardSeven.h"

#include "ApplicationManager.h"
#include <fstream>
#include <time.h> 
#include "Player.h"

CardSeven::CardSeven(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number (7 here)
}

CardSeven::~CardSeven(void)
{
}

//void CardSeven::ReadCardParameters()
//{
//		// no parameters to read from user
//
//}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
		

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card:: Apply(pGrid, pPlayer);

	//Get a Pointer to the Input / Output Interfaces from the Grid

	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	//Gives the player another dice roll.
	pOut->PrintMessage("You will have another roll click to continue...");
	pIn->GetCellClicked();

	srand((int)time(NULL)); // time is for different seed each run
	int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed


	pOut->PrintMessage("You rolled : " + to_string (diceNumber));
	// 3- Get the "current" player from pGrid
	 pPlayer=pGrid->GetCurrentPlayer();
	
	// 4- Move the currentPlayer using function Move of class player
	pPlayer->SetTurnCount(pPlayer->GetTurnCount()-1);
	int turn=pPlayer->GetTurnCount()+1;
	pPlayer->Move(pGrid, diceNumber);
	 
	pPlayer->SetTurnCount(turn);
	// 5- Advance the current player number of pGrid
	//pGrid->AdvanceCurrentPlayer();
	//ActionType ActType;
	//ApplicationManager AppManager;
	//ActType = ;
	/*ApplicationManager* App;
	App->ExecuteAction(ROLL_DICE);*/

	/*while(ActType != ROLL_DICE)
	{
		pOut-> PrintMessage("please roll the dice");
		ActType = AppManager.GetUserAction();
		pOut->ClearStatusBar();
	}

	
	AppManager.ExecuteAction(ActType);
	AppManager.UpdateInterface();*/
	
	/*delete [] pIn;
	delete [] pOut;*/
}

void CardSeven:: Save(ofstream &OutFile , int Type)
{
	if(Type == 3)
	{
	Card:: Save(OutFile , Type);
	OutFile <<endl;
	}
}

void CardSeven:: Load (ifstream &InFile)
{
	//Card:: Load(InFile);
}