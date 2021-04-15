#include "AddCardAction.h"
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

AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters() 
{	

	Grid* pGrid = pManager->GetGrid();
	Input* input = pGrid->GetInput();
	Output* output = pGrid->GetOutput();

	
	    output->PrintMessage("Click On Card Cell...");
    cardPosition=input->GetCellClicked();

		while(!cardPosition.IsValidCell()||cardPosition.GetCellNum()==1||cardPosition.GetCellNum()==99)
	{
			output->PrintMessage("Invalid Cell , Click Another Cell !");
		    cardPosition=input->GetCellClicked();

	}
	output->PrintMessage("Type Card Number( 1 - 14 )...");
	cardNumber=input->GetInteger(output);
	while(cardNumber<1||cardNumber>14)
	{
			output->PrintMessage("Invalid Number, Enter a Number Between 1 & 14 ");
	        cardNumber=input->GetInteger(output);

	}
	


	
	output->ClearStatusBar();
}

void AddCardAction::Execute() 
{


	
	ReadActionParameters();

	
	Card * pCard = NULL; 
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;

		
	case 2:
		pCard = new CardTwo(cardPosition);
		break;

    case 3:
		pCard = new CardThree(cardPosition);
		break;

	case 4:
		pCard = new CardFour(cardPosition);
		break;

	case 5:
		pCard = new CardFive(cardPosition);
		break;

	case 6:
		pCard = new CardSix(cardPosition);
		break;

	case 7:
		pCard = new CardSeven(cardPosition);
		break;

	case 8:
		pCard = new CardEight(cardPosition);
		break;

	case 9:
		pCard = new CardNine(cardPosition);
		break;

	case 10:
		pCard = new CardTen(cardPosition);
		break;

	case 11:
		pCard = new CardEleven(cardPosition);
		break;

	case 12:
		pCard = new CardTwelve(cardPosition);
		break;

	case 13:
		pCard = new CardThirteen(cardPosition);
		break;

	case 14:
		pCard = new CardFourteen(cardPosition);
		break;

	}

	
	if (pCard)
	{
	
		Grid *pGrid=pManager->GetGrid();

		
		
			pCard->ReadCardParameters(pGrid);
			pGrid->SetNewCard(pCard); 

	
		bool added = pGrid->AddObjectToCell(pCard);

		
		if(!added)
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}

}
