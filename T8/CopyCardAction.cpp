#include "CopyCardAction.h"
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


CopyCardAction::CopyCardAction(ApplicationManager *pApp) : Action(pApp)

{
	
}
void CopyCardAction::ReadActionParameters() // Reads AddCardAction action parameters (cardNumber, cardPosition)
	{ 
		Grid *pGrid=pManager->GetGrid();
        Input* input=pGrid->GetInput();
		Output*output=pGrid->GetOutput();
		output->PrintMessage("Click Card You Want To Copy  ");
		cardposition=input->GetCellClicked();
		while(!cardposition.IsValidCell()||cardposition.GetCellNum()==1||cardposition.GetCellNum()==99)
		{
				output->PrintMessage("Invalid Cell ,Click Another Cell !");
				cardposition=input->GetCellClicked();
		}

		output->ClearStatusBar();


	}

 void CopyCardAction::Execute()	
{	
	ReadActionParameters();
    Grid *pGrid=pManager->GetGrid();
	Output*output=pGrid->GetOutput();
	if(pGrid->CheckCell(cardposition))
		{
			Card*pCard=pGrid->GetCard(cardposition);
	        //	output->PrintMessage("Copy1  ");
            pGrid->SetClipboard(pCard);
	    }
}
 
CopyCardAction::~CopyCardAction()
{
}
