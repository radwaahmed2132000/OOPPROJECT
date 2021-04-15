#include "OpenGridAction.h"

#include "Input.h"
#include "Output.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Snake.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"

OpenGridAction::OpenGridAction(ApplicationManager *pApp) : Action(pApp)
{

	
	// Initializes the pManager pointer of Action with the passed pointer
}

void OpenGridAction:: ReadActionParameters() 
{	
	Grid * pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	string FileName;
	pOut->PrintMessage("Enter The File Name to load from ,please");
	FileName=pIn->GetSrting(pOut)+".txt";
	inputFile.open(FileName); 
	pOut->ClearStatusBar();

}


// Execute the action
void OpenGridAction::Execute() 
{
	ReadActionParameters();
	Grid * pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	bool C10=true, C11=true, C12=true, C13=true, C14=true;

	pGrid->RemoveObjectFromCelloatr2();
	pGrid->UpdateInterface();
	 // We get a pointer to the Grid from the ApplicationManager
	if( inputFile.is_open() )
	{
		int i;
		inputFile>>i;
		for(int j=0 ; j<i; j++)
		{
			CellPosition Cstart (1);
			CellPosition Cend (1);
			Ladder * pLadder = new Ladder ( Cstart , Cend);
			pLadder->Load(inputFile);
			Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
			pGrid->AddObjectToCell(pLadder);
		}
		inputFile>>i;
		for (int j=0 ; j<i ; j++)
		{
			CellPosition Cstart (1);
			CellPosition Cend (1);
			Snake * pSnake = new Snake (Cstart , Cend);
			pSnake->Load(inputFile);
			Grid * pGrid = pManager->GetGrid();  // We get a pointer to the Grid from the ApplicationManager
			pGrid->AddObjectToCell(pSnake);
		}
		inputFile>>i;
		for (int j=0 ; j<i ; j++)
		{
		    int cardnum ;
			inputFile>>cardnum;
			Card * pCard = NULL; // will point to the card object type
			int cellnum;
			inputFile>>cellnum;
			CellPosition CP(cellnum);
	switch (cardnum)
	{
	case 1:
		pCard = new CardOne(CP);
		pCard->Load(inputFile);
		break;

	case 2:
		pCard = new CardTwo(CP);
		pCard->Load(inputFile);
		break;

    case 3:
		pCard = new CardThree(CP);
		break;

	case 4:
		pCard = new CardFour(CP);
		break;

	case 5:
		pCard = new CardFive(CP);
		break;

	case 6:
		pCard = new CardSix(CP);
		break;

	case 7:
		pCard = new CardSeven(CP);
		break;

	case 8:
		pCard = new CardEight(CP);
		break;

	case 9:
		pCard = new CardNine(CP);
		pCard->Load(inputFile);
		break;

	case 10:
		pCard = new CardTen(CP);
		if(C10==true)
		{
			pCard->Load(inputFile);
			C10 = false;
		}
	    break;

	case 11:
		pCard = new CardEleven(CP);
		if(C11==true)
		{
			pCard->Load(inputFile);
			C11 = false;
		}
		break;

	case 12:
		pCard = new CardTwelve(CP);
		if(C12==true)
		{
			pCard->Load(inputFile);
			C12 = false;
		}
		break;

	case 13:
		pCard = new CardThirteen(CP);
		if(C13==true)
		{
			pCard->Load(inputFile);
			C13 = false;
		}
		break;

	case 14:
		pCard = new CardFourteen(CP);
		if(C14==true)
		{
			pCard->Load(inputFile);
			C14 = false;
		}
		break;
	}
		
		pGrid->AddObjectToCell(pCard);
		}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
	}
}


OpenGridAction::~OpenGridAction()
{
	inputFile.close();
}
