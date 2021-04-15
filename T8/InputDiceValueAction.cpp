#include "InputDiceValueAction.h"



#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed


InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceValueAction::ReadActionParameters()
{///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	Grid* pGrid = pManager->GetGrid();
	//get grid pointer
	Input* pIn = pGrid->GetInput();
	//get input pointer
	Output* pOut = pGrid->GetOutput();
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	CellPosition c1 = pIn->GetCellClicked();

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."


}

void InputDiceValueAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	//get grid pointer
	Input* pIn = pGrid->GetInput();
	//get input pointer
	Output* pOut = pGrid->GetOutput();
	//get output  pointer
	pOut->PrintMessage("please enter a dice value between 1-6”");
	//print message to enter dice number 
	int dicenumber = pIn->GetInteger(pOut);

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below



	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (pGrid->GetEndGame())
	{
		
	}
	else
	{
		bool exit1 = true;
		// -- If not ended, do the following --:
		while (exit1)
		{
			if (!(dicenumber > 0 && dicenumber <= 6))
			{

				//check dice number validation				
				pOut->PrintMessage("You entered Invalid Number: " + to_string(dicenumber) + " please enter a dice value between 1-6”");
				//print error message if dice numbe is invalid 
				dicenumber = pIn->GetInteger(pOut);

			}
			if ((dicenumber > 0 && dicenumber <= 6))
			{
				exit1 = false;
			}

		}
// 3- Get the "current" player from pGrid
		Player* pPlayer=pGrid->GetCurrentPlayer();
		Cell* pCell = pPlayer->GetCell();
		//Card* pCard = pCell->HasCard();
		if(pPlayer->GetCell()->HasCardEight() && pPlayer->getIsExecuted()==false)// && pPlayer->GetTurnCount()!=2)
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

			pOut->PrintMessage("You rolled : " + to_string(dicenumber));
			// 3- Get the "current" player from pGrid
			//Player* pPlayer = pGrid->GetCurrentPlayer();

			// 4- Move the currentPlayer using function Move of class player
			pPlayer->Move(pGrid, dicenumber);

			// 5- Advance the current player number of pGrid
			pGrid->AdvanceCurrentPlayer();
		}
		// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	}
}


InputDiceValueAction::~InputDiceValueAction()
{
}

