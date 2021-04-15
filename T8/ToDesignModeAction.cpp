#include "ToDesignModeAction.h"

#include "Input.h"
#include "Output.h"
#include "GameObject.h"
#include "Player.h"
 
ToDesignModeAction::ToDesignModeAction(ApplicationManager *pApp) : Action(pApp)
{
}

void ToDesignModeAction::ReadActionParameters() 
{
	/*Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();*/
}

void ToDesignModeAction::Execute() 
{
	ReadActionParameters();
	Grid * pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreateDesignModeToolBar();

	CellPosition* Cell[4];
	Cell[0] = new CellPosition;
	Cell[1] = new CellPosition;
	Cell[2] = new CellPosition;
	Cell[3] = new CellPosition;

	Player* pPlayer[4];
	for (int i = 0; i < 4; i++) {
		pPlayer[i] = pGrid->GetCurrentPlayer();
	
		Cell[i]->SetHCell(0);
		Cell[i]->SetVCell(8);
		pGrid->UpdatePlayerCell(pPlayer[i], *Cell[i]);
		pGrid->AdvanceCurrentPlayer();
		pPlayer[i]->SetWallet(100);
		pPlayer[i]->SetTurnCount(0);

	}
	pGrid->SetCurrPlayerNum(0);
}

ToDesignModeAction::~ToDesignModeAction(void)
{
}
