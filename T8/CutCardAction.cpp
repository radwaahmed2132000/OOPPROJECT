#include "CutCardAction.h"
#include "Input.h"
#include "Output.h"
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


CutCardAction::CutCardAction(ApplicationManager *pApp) : Action(pApp)
{
}
	 void CutCardAction::ReadActionParameters() 
	{ 
		Grid *pGrid=pManager->GetGrid();
        Input* input=pGrid->GetInput();
		Output*output=pGrid->GetOutput();
		output->PrintMessage("Click Card You Want To Cut  ");
		cardposition=input->GetCellClicked();
		while(!cardposition.IsValidCell()||cardposition.GetCellNum()==1||cardposition.GetCellNum()==99)
		{
				output->PrintMessage("Invalid Cell ,Click Another Cell !");
				cardposition=input->GetCellClicked();

		}

		output->ClearStatusBar();
	}

 void CutCardAction::Execute()	
{	
	 	ReadActionParameters();
        Grid *pGrid=pManager->GetGrid();
		Output*output=pGrid->GetOutput();

        Card*pCard=pGrid->GetCard(cardposition);
		if(pGrid->CheckCell(cardposition))
		{
		Card* Temp=pCard;
		CellPosition pos;
		Temp->SetPosition(pos);
        pGrid->DeleteCard(cardposition);
		pGrid->RemoveObjectFromCell(cardposition);
		pGrid->UpdateInterface();
		
		Temp->SetPosition(cardposition);
        //pGrid->SetNewCard(Temp); 
		pGrid->SetClipboard(Temp);
		output->ClearStatusBar();	
		}
		}


 
CutCardAction::~CutCardAction(void)
{
}
