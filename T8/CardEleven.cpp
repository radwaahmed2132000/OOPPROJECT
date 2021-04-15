#include "CardEleven.h"


int CardEleven::numberofcards=0;
int CardEleven::price=0;
int CardEleven::fees=0;
Player* CardEleven::owner=NULL;
bool CardEleven:: SaveC11 = true;

CardEleven::CardEleven(const CellPosition & pos) : Card(pos)
{
	cardNumber=11;// set the inherited cardNumber data member with the card number (11 here)
	numberofcards++;
}
	
bool CardEleven::isrepeated()
{
	
	return (numberofcards>1);
}
void CardEleven::changeparameters(Grid * pGrid)
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
void CardEleven::ReadCardParameters(Grid * pGrid)
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
	

}
void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
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
		
			
			output->ClearStatusBar();



}

void CardEleven:: setC11(bool ex)
{
	SaveC11=ex;
}


void CardEleven:: Save(ofstream &OutFile , int Type)
{
	if(Type == 3)
	{
	Card:: Save(OutFile , Type);
	if(SaveC11 == true)
	{
	OutFile << price <<" " << fees<<endl;
	SaveC11 = false;
	}
	else
		OutFile<<endl;
	}
}

void CardEleven:: Load (ifstream &InFile)
{
	//Card:: Load(InFile);
	InFile>>price >> fees;
}

CardEleven::~CardEleven(void)
{
}
