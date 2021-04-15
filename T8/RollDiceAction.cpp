#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed


RollDiceAction::RollDiceAction(ApplicationManager* pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	Grid* pGrid = pManager->GetGrid();
	//get grid pointer
	// == Here are some guideline steps (numbered below) to implement this function ==
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	//get  output pointer
	//get input pointer

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (pGrid->GetEndGame())
	{
		
	}
	else
	{

		// -- If not ended, do the following --:
		Player* pPlayer=pGrid->GetCurrentPlayer();
		Cell* pCell = pPlayer->GetCell();
		Card* pCard = pCell->HasCard();

		
		if(pPlayer->GetCell()->HasCardEight() && pPlayer->getIsExecuted()==false )//&& pPlayer->GetTurnCount()!=2)
		{

			pOut->PrintMessage( "you are denied from playing this turn. Click to continue");
			pIn->GetCellClicked();
			//pPlayer->Move(pGrid, 0);
			if(pPlayer->GetTurnCount()==2)
				pPlayer->SetTurnCount(0);
			else
			pPlayer->SetTurnCount(pPlayer->GetTurnCount()+1); 
			pOut->ClearStatusBar();
			pPlayer->setIsExecuted(true);
			pGrid->AdvanceCurrentPlayer();
			
		}
		else if(pPlayer->GetWallet()<=0 && pPlayer->GetTurnCount()!=2)
		{
			pOut->PrintMessage("Your wallet is less than allowable you can't move");
			pIn->GetCellClicked();
			pPlayer->SetTurnCount(pPlayer->GetTurnCount()+1);
			pOut->ClearStatusBar();
			pGrid->AdvanceCurrentPlayer();
		}
		else
		{
			if(pPlayer->GetCell()->HasCardEight() && pPlayer->getIsExecuted()==true &&pPlayer->GetTurnCount()!=2)
				pPlayer->setIsExecuted(false);
		// 2- Generate a random number from 1 to 6 --> This step is done for you
		srand((int)time(NULL)); // time is for different seed each run
		int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed



		pOut->PrintMessage("You rolled : " + to_string(diceNumber));
		// 3- Get the "current" player from pGrid
		Player* pPlayer = pGrid->GetCurrentPlayer();

		// 4- Move the currentPlayer using function Move of class player
		pPlayer->Move(pGrid, diceNumber);

		// 5- Advance the current player number of pGrid
		pGrid->AdvanceCurrentPlayer();
		
		// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	}
	}
}

RollDiceAction::~RollDiceAction()
{
}
