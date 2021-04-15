#include "EditCardAction.h"
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

EditCardAction::EditCardAction(ApplicationManager *pApp) : Action(pApp)
{
}


	 void EditCardAction::ReadActionParameters() // Reads AddCardAction action parameters (cardNumber, cardPosition)
	{ 
		Grid *pGrid=pManager->GetGrid();
        Input* input=pGrid->GetInput();
		Output*output=pGrid->GetOutput();
		output->PrintMessage("Click On The Source To Edit ");
		cardposition=input->GetCellClicked();
		if(!cardposition.IsValidCell()||cardposition.GetCellNum()==1||cardposition.GetCellNum()==99)
		{
				output->PrintMessage("Invalid Cell ,Click Another Cell !");
				cardposition=input->GetCellClicked();
		}
		output->ClearStatusBar();
	}

 void EditCardAction::Execute()	


	
 {	
	 
	 	ReadActionParameters();
        Grid *pGrid=pManager->GetGrid();
		Card*pcard=pGrid->GetCard(cardposition);
		pcard->changeparameters(pGrid);

 }


EditCardAction::~EditCardAction(void)
{
}
