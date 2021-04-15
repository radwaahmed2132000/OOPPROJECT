#include "PasteCardAction.h"
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

PasteCardAction::PasteCardAction(ApplicationManager *pApp) : Action(pApp)
{
}
void PasteCardAction::ReadActionParameters()
{
	Grid*pGrid=pManager->GetGrid();
	Output*output=pGrid->GetOutput();
	Input*input=pGrid->GetInput();
	output->PrintMessage("ReadActionParameters");
    output->PrintMessage("Click On The Destination Cell...");
	newcardposition=input->GetCellClicked();
	while(!newcardposition.IsValidCell()||newcardposition.GetCellNum()==1||newcardposition.GetCellNum()==99)
		{
				output->PrintMessage("Invalid Cell ,Click Another Cell !");
				newcardposition=input->GetCellClicked();
        }
	output->ClearStatusBar();

}

void PasteCardAction::Execute()
{
		ReadActionParameters();
		Grid*pGrid=pManager->GetGrid();
		Output*output=pGrid->GetOutput();
		output->PrintMessage("paste 1!");
		pCard=pGrid->GetClipboard();
	   		output->PrintMessage("paste 2!");

	
int cardNumber=pCard->GetCardNumber();
		   		output->PrintMessage("paste 3!");

	Card* NewCard=NULL;	
		
	switch (cardNumber)
	{
	case 1:
		NewCard = new CardOne(newcardposition);
		break;

		
	case 2:
		NewCard = new CardTwo(newcardposition);
		break;

    case 3:
		NewCard = new CardThree(newcardposition);
		break;

	case 4:
		NewCard = new CardFour(newcardposition);
		break;

	case 5:
		NewCard = new CardFive(newcardposition);
		break;

	case 6:
		NewCard = new CardSix(newcardposition);
		break;

	case 7:
		NewCard = new CardSeven(newcardposition);
		break;

	case 8:
		NewCard = new CardEight(newcardposition);
		break;

	case 9:
		NewCard = new CardNine(newcardposition);
		break;

	case 10:
		NewCard = new CardTen(newcardposition);
		break;

	case 11:
		NewCard = new CardEleven(newcardposition);
		break;

	case 12:
		NewCard = new CardTwelve(newcardposition);
		break;

	case 13:
		NewCard = new CardThirteen(newcardposition);
		break;

	case 14:
		NewCard = new CardFourteen(newcardposition);
		break;

	}

	
	if (NewCard)
	{
			   	

		NewCard->SetData(pCard);
				   		

		pGrid->SetNewCard(NewCard); 

		bool added = pGrid->AddObjectToCell(NewCard);

		
		if(!added)
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}

								

		
}


//void PasteCardAction::Execute()
//{
//		ReadActionParameters();
//		Grid*pGrid=pManager->GetGrid();
//		Output*output=pGrid->GetOutput();
////						output->PrintMessage("paste 1!");
//		pCard=pGrid->GetClipboard();
//		
//		int parameter= pCard->getCardParameter();
//
//		int n=pCard->GetCardNumber();
//		 // will point to the card object type
//		pCard=NULL;
//	switch (n)
//	{
//case 1:
//		pCard = new CardOne(newcardposition);
//		break;
//		
//case 2:
//	pCard = new CardTwo(newcardposition);
//		break;
//
//case 3 :
//		pCard = new CardThree(newcardposition);
//		break;
//
//case 4:
//		pCard = new CardFour(newcardposition);
//		break;
//
//case 5:
//		pCard = new CardFive(newcardposition);
//		break;
//case 6:
//		pCard = new CardSix(newcardposition);
//		break;
//case 7:
//		pCard = new CardSeven(newcardposition);
//		break;
//case 8:
//		pCard = new CardEight(newcardposition);
//		break;
//case 9:
//		pCard = new CardNine(newcardposition);
//		break;
//case 10:
//		pCard = new CardTen(newcardposition);
//		break;
//case 11:
//		pCard = new CardEleven(newcardposition);
//		break;
//case 12:
//		pCard = new CardTwelve(newcardposition);
//		break;
//case 13:
//		pCard = new CardThirteen(newcardposition);
//		break;
//case 14:
//		pCard = new CardFourteen(newcardposition);
//		break;
//		// A- Add the remaining cases
//
//	}
//	//	CellPosition pos=pCard->GetPosition();
//		 pCard->SetCardNumber(n);
//		 pCard->setCardParameter(parameter);
//		
//	
//								//output->PrintMessage("paste 12!");
//
//		
//		///////////////pCard->SetPosition(newcardposition);
//							
//
//        bool added = pGrid->AddObjectToCell(pCard);
//	    if(!added)
//	    pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
//		
//}


PasteCardAction::~PasteCardAction(void)
{
}
