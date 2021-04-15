#include "CardFourteen.h"


int CardFourteen::numberofcards=0;
int CardFourteen::price=0;
int CardFourteen::fees=0;
Player* CardFourteen::owner=NULL;
bool CardFourteen:: SaveC14 = true;

CardFourteen::CardFourteen(const CellPosition & pos) : Card(pos)
{
	cardNumber=14; // set the inherited cardNumber data member with the card number (14 here)
	numberofcards++;
}
	
bool CardFourteen::isrepeated()
{
	
	return (numberofcards>1);
}
void CardFourteen::changeparameters(Grid * pGrid)
{
    
	Input*input=pGrid->GetInput();
	Output*output=pGrid->GetOutput();
	output->PrintMessage("Price is : "+to_string(price)+" ,Do You Want To Change it? y/n");
    string answer=input->GetSrting(output);
	if(answer=="y"||answer=="Y")
	{
		output->PrintMessage("Enter New Price :");
		price=input->GetInteger(output);}

	output->PrintMessage("Fees is : "+to_string(fees)+" ,Do You Want To Change it? y/n");
	 answer=input->GetSrting(output);
	if(answer=="y"||answer=="Y")
  {  	output->PrintMessage("Enter New Fees :");
	  fees=input->GetInteger(output);
}
				output->ClearStatusBar();

}
void CardFourteen::ReadCardParameters(Grid * pGrid)
{
	//	Grid *pGrid=pManager->GetGrid();
	if(!isrepeated())
	{
		Input*input=pGrid->GetInput();
	Output*output=pGrid->GetOutput();
	output->PrintMessage("Enter The Price Of The Card  ^_^ !");
	
	price=input->GetInteger(output);
	while (price<0)
	{output->PrintMessage("Price Can't Be Negative !");

	price=input->GetInteger(output);}
		output->PrintMessage("Enter The Fees Of The Card  ^_^ !");

	    fees=input->GetInteger(output);

	while (fees<0)
	{output->PrintMessage("Fees Can't Be Negative !");
	fees=input->GetInteger(output);}
	output->ClearStatusBar();

	}
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	

	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar

}
void CardFourteen::Apply(Grid* pGrid, Player* pPlayer)
{
		Card::Apply(pGrid,pPlayer);
		Output*output=pGrid->GetOutput();
		Input*input=pGrid->GetInput();
		if(owner==NULL)
	{	
		output->PrintMessage("Do You Want TO Buy This Cell And All Cells Carring The Same Card By "+to_string(price)+" Coins ? y/n ");
		 string answer=input->GetSrting(output);
		if(answer=="y"||answer=="Y")
		 		if(pPlayer->GetWallet()>=price)

			{
				owner=pPlayer;
		        pPlayer->SetWallet(pPlayer->GetWallet()-price);
		        output->PrintMessage("You Bought This Cell ^_^ ,Click Any Where To Continue..." );
	            input->GetCellClicked();
		   }
			
				else output->PrintMessage("You Don't Have Enough Coins ,You Can't Buy This Cell..." );

	}
		
		else if(pPlayer!=owner)
		{
			output->PrintMessage("This Cell Is Owned By Player Number "+to_string(owner->GetPlayerNum())+" ,You Must Pay "+to_string(fees)+" Coins As Fees ,Click Any Where To Continue...");			
			input->GetCellClicked();
	
				pPlayer->SetWallet(pPlayer->GetWallet()-fees);

			    owner->SetWallet(owner->GetWallet()+fees);
		
		
	    }
		
				///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
			output->ClearStatusBar();


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
		
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne

}

void CardFourteen:: setC14(bool ex)
{
	SaveC14=ex;
}

void CardFourteen:: Save(ofstream &OutFile , int Type)
{
	if(Type == 3)
	{
	Card:: Save(OutFile , Type);
	if(SaveC14 == true)
	{
	OutFile << price <<" " << fees<<endl;
	SaveC14 = false;
	}
	else
		OutFile<<endl;
	}
}

void CardFourteen:: Load (ifstream &InFile)
{
	//Card:: Load(InFile);
	InFile>>price >> fees;
}

CardFourteen::~CardFourteen(void)
{
}
