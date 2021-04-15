#include "NewGameAction.h"
#include "Input.h"
#include "Output.h"
#include "GameObject.h"
#include "Player.h"
#include "Cell.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void NewGameAction::ReadActionParameters()

{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// print message if is clicked on new game 
	pOut->PrintMessage(" You have Clicked on NewGame Object ");



	// Clear messages
	pOut->ClearStatusBar();

}


// Execute the action
void NewGameAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members

	ReadActionParameters();
	// We get a pointer to the Grid from the ApplicationManager

	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	CellPosition c1(8, 0);


	////set hcell 0

	//set vcell 8
//cell for every player to update thier positions 


	for (int i = 0; i < 4; i++) {
		pPlayer[i] = pGrid->GetCurrentPlayer();

		//get Current player 
			//Cell[i]->SetHCell(0);
			////set hcell 0
			//Cell[i]->SetVCell(8);
			//set vcell 8
		pGrid->UpdatePlayerCell(pPlayer[i], c1);
		//update player position 

		// adance player
		pGrid->GetCurrentPlayer()->SetWallet(100);
		// upadete current player wallet to 100
		pGrid->GetCurrentPlayer()->SetTurnCount(0);
		pGrid->AdvanceCurrentPlayer();
		// upadete current player turncount to 0 

	}
	pGrid->SetCurrPlayerNum(0);
	//end of loop set current player num =0 
	pGrid->SetEndGame(false);






	pGrid->UpdateInterface();

}

NewGameAction::~NewGameAction(void)
{


}
