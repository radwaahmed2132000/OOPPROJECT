#include "DeleteGameObjectAction.h"

#include "Input.h"
#include "Output.h"
#include "GameObject.h"

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager *pApp) : Action(pApp)
	
{
	// Initializes the pManager pointer of Action with the passed pointer
}


DeleteGameObjectAction::~DeleteGameObjectAction(void)
{
}

void DeleteGameObjectAction::ReadActionParameters() 
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the deletePos parameter
	pOut->PrintMessage("Delete Object: Click on the object's Cell ...");
	deletePos = pIn->GetCellClicked();


	// Clear messages
	pOut->ClearStatusBar();
	}
    

// Execute the action
void DeleteGameObjectAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Delete an object with the parameters read from the user
	pGrid->RemoveObjectFromCell(deletePos);
	pGrid->UpdateInterface();
	
	// Here, the object is deleted of its Cell, so we finished executing the DeleteGameObjectAction

}