#include "ToPlayModeAction.h"

#include "Input.h"
#include "Output.h"
#include "GameObject.h"

 
ToPlayModeAction::ToPlayModeAction(ApplicationManager *pApp) : Action(pApp)
{
}

void ToPlayModeAction::ReadActionParameters() 
{
	/*Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();*/
}

void ToPlayModeAction::Execute() 
{
	ReadActionParameters();
	Grid * pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreatePlayModeToolBar();
}

ToPlayModeAction::~ToPlayModeAction(void)
{
}
