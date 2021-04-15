#include "CardNine.h"

CardNine::CardNine(const CellPosition & pos):Card(pos)

{ 
	cardNumber=9; // set the inherited cardNumber data member with the card number (9 here)
}

void  CardNine::SetDataNine(Card* pCard)
{
	Celltomoveto=pCard->GetDataNine();


}
CellPosition  CardNine::GetDataNine()
{
	return Celltomoveto;
}

void CardNine::ReadCardParameters(Grid * pGrid)
{
	Output*output=pGrid->GetOutput();
	Input*input=pGrid->GetInput();
	output->PrintMessage("Click Where You Want To Move ^_^ !");
	Celltomoveto=input->GetCellClicked();
	while(!Celltomoveto.IsValidCell()||Celltomoveto.GetCellNum()==1||Celltomoveto.GetCellNum()==99)
	{
		output->PrintMessage("Invalid Cell ,Click Another Cell !");
		Celltomoveto=input->GetCellClicked();

	
	}	
	while(Celltomoveto.GetCellNum()== position.GetCellNum())
	{
		output->PrintMessage("The Cell Can't Be The Same Cell Of The Card....");
	    Celltomoveto=input->GetCellClicked();
	}
		

    output->PrintMessage("When You Get To This Card,You Will Move To Cell '"+to_string(Celltomoveto.GetCellNum())+"' Click Any Where To Continue...");
	input->GetCellClicked(); 
	output->ClearStatusBar();
	
}
void CardNine::changeparameters(Grid * pGrid)
{
    
	Input*input=pGrid->GetInput();
	Output*output=pGrid->GetOutput();
	output->PrintMessage("When You Step On This Cell ,	You Move To "+to_string(Celltomoveto.GetCellNum())+"Do You Want To Change The New Position ?  y/n");
    string answer=input->GetSrting(output);
	if(answer=="y"||answer=="Y")
	{    
		output->PrintMessage("Click Where You Want To Move ^_^ !");
		Celltomoveto=input->GetCellClicked();
	while(!Celltomoveto.IsValidCell()||Celltomoveto.GetCellNum()==1||Celltomoveto.GetCellNum()==99)
	{
		output->PrintMessage("Invalid Cell ,Click Another Cell !");
		Celltomoveto=input->GetCellClicked();

	
	}	
	while(Celltomoveto.GetCellNum()== position.GetCellNum())
	{
		output->PrintMessage("The Cell Can't Be The Same Cell Of The Card....");
	    Celltomoveto=input->GetCellClicked();
	}
	}
    output->PrintMessage("When You Get To This Card,You Will Move To Cell '"+to_string(Celltomoveto.GetCellNum())+"' Click Any Where To Continue...");
	input->GetCellClicked(); 
	output->ClearStatusBar();
	
}
void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{	Input*input=pGrid->GetInput();

	Output*output=pGrid->GetOutput();
	output->PrintMessage(" By Stepping On Card 9 ,You Moved to Card Number : "+to_string(Celltomoveto.GetCellNum()));
	input->GetCellClicked();
	pGrid->UpdatePlayerCell(pPlayer,Celltomoveto);
	if (pPlayer->GetCell()->GetGameObject() != NULL)
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);
	output->ClearStatusBar();
}

void CardNine:: setCardParameter(int par)
{
	CellPosition temp (par);
	Celltomoveto = temp;
}

int CardNine:: getCardParameter()
{
	return Celltomoveto.GetCellNum();
}


void CardNine:: Save(ofstream &OutFile , int Type)
{
	if(Type == 3)
	{
	Card:: Save(OutFile , Type);
	OutFile << Celltomoveto.GetCellNum() <<endl;//" "<< numberofcards <<endl;
	}
}

void CardNine:: Load (ifstream &InFile)
{
	//Card:: Load(InFile);
	int cellnum;
	InFile>>cellnum;
	CellPosition loadcell(cellnum);
	Celltomoveto = loadcell;
	//InFile >> numberofcards;
}

CardNine::~CardNine(void)
{
}
