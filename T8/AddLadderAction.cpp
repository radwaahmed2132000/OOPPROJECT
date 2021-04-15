#include "AddLadderAction.h"
#include "Input.h"
#include "Output.h"
#include "Snake.h"
AddLadderAction::AddLadderAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}
AddLadderAction::~AddLadderAction  ()
{
}

void AddLadderAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();
	if (startPos.IsValidCell() == true && startPos.GetCellNum() != 1)
	{



		{// Read the endPos parameter
			pOut->PrintMessage("New Ladder: Click on its End Cell ...");
			endPos = pIn->GetCellClicked();


			///TODO: Make the needed validations on the read parameters??????????

		}

		if (!(endPos.IsValidCell() == true && endPos.GetCellNum() !=  99 && startPos.HCell() == endPos.HCell() && startPos.VCell() > endPos.VCell()))
		{
			if (startPos.HCell() != endPos.HCell())
			{
				exit2 = false;
			}
			if (startPos.VCell() < endPos.VCell())
			{
				exit3 = false;
			}


			endPos = NULL;

			startPos = NULL;
			if (!(endPos.IsValidCell() == true && endPos.GetCellNum() != 99))

			{
				exit1 = false;
			}
		}
	}
	else
	{
		endPos = NULL;
		startPos = NULL;
		exit1 = false;
	}
	pOut->ClearStatusBar();

}


// Execute the action
void AddLadderAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Snake object with the parameters read from the user
	Ladder* pLadder= new Ladder(startPos, endPos);


	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	 // Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder) && (startPos.HCell() == endPos.HCell() && startPos.VCell()  >endPos.VCell());

	// if the GameObject cannot be added
	if (!added)
	{
		if (!exit2)
		{
			pGrid->PrintErrorMessage("end cell and start cell are not in the same column");
			//print message if hcell of start not equal hcell of end 
		}
		else if (!exit3)
		{
			pGrid->PrintErrorMessage("end cell cannot be smaller than start cell");
			//print message if endPos.VCell() <startPos.VCell()
		}
		else if (!exit1)
		{
			pGrid->PrintErrorMessage("Check Ladder specification");
			//print message if startcell is invalid 

		}



		else if (pLadder->getcheck1() == 1)
		{
			pGrid->PrintErrorMessage("Two Ladder cannot overlap");
			//print messeage if two snakes is overlapping 
		}
		else if (pLadder->getcheck1() == 2)
		{
			pGrid->PrintErrorMessage("end cell cannot be a start of another ladder or snake");
			//print  message if ladder ovelapps with snake 
		}
		else
		{
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
			//print message if you try to draw in cell has pbject 
		}

		// Here, the Snake is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

	}
}

