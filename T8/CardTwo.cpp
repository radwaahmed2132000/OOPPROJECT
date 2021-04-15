#include "CardTwo.h"
#include <fstream>

CardTwo::CardTwo(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (2 here)
}

CardTwo::~CardTwo(void)
{
}

void  CardTwo::SetDataTwo(Card* pCard)
{
	 walletPlus=pCard->GetDataTwo();


}
int CardTwo::GetDataTwo()
{
	return  walletPlus;
}

void CardTwo::changeparameters(Grid * pGrid)
{
    
	Input*input=pGrid->GetInput();
	Output*output=pGrid->GetOutput();
	output->PrintMessage("walletPlus : "+to_string(walletPlus)+" ,Do You Want To Change it? y/n");
    string answer=input->GetSrting(output);
	if(answer=="y")
	{
		output->PrintMessage("Enter New walletPlus :");
		walletPlus=input->GetInteger(output);}

		output->ClearStatusBar();

}


void CardTwo::ReadCardParameters(Grid * pGrid)
{


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	// 2- Read an Integer from the user using the Input class and set the walletPlus parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardTwo: Enter its wallet amount ..."
	pOut->PrintMessage("New CardTwo: Enter the wallet amount to increase...");
	walletPlus = pIn->GetInteger (pOut);

	// [ Note ]:
	// In CardTwo, the only parameter of CardTwo is the "walletPlus" value to increase to player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
		
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card:: Apply(pGrid, pPlayer);

	// 2- increase the wallet of pPlayer by the walletPlus data member of CardTwo
	pPlayer->SetWallet(pPlayer->GetWallet() + walletPlus); 
}

void CardTwo:: setCardParameter(int par)
{
	walletPlus=par;
}

int CardTwo:: getCardParameter()
{
	return walletPlus;
}


void CardTwo:: Save(ofstream &OutFile , int Type)
{
	if (Type ==3 )
	{
	Card:: Save(OutFile , Type);
	OutFile <<walletPlus<<endl;
	}
}

void CardTwo:: Load (ifstream &InFile)
{
	//Card:: Load(InFile);
	InFile >> walletPlus;
}