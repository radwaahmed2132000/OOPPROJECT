#include "Card.h"
#include<fstream>

Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
	
}

void Card::SetCardNumber(int cnum)
{
	cardNumber = cnum; // needs validation
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::SetData(Card* pCard) 
{
	
	switch (cardNumber)           //check the cardNumber
{	    case 1:
			this->SetDataOne(pCard);     //copy data to cardone
			break;
		case 2:
			this->SetDataTwo(pCard);    ////copy data to cardtwo
			break;
		case 9:
			this->SetDataNine(pCard);    //copy data to cardnine
			break;
}
}
void  Card::SetDataNine(Card* pCard)
{
}
CellPosition  Card::GetDataNine()
{
return CellPosition(1,1);
}
void  Card::SetDataOne(Card* pCard)
{
}
int Card::GetDataOne()
{
	return  0;
}
void  Card::SetDataTwo(Card* pCard)
{
}
int Card::GetDataTwo()
{
	return 0;
}
//bool Card:: getIsExecuted ()
//{
//	return isExecuted;
//}; 
//
//void Card:: setIsExecuted(bool in)
//{
//	isExecuted = in;
//}

bool Card::isrepeated()
{
	return false;

}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position,cardNumber);

}

void Card::changeparameters(Grid * pGrid)
{

}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

void Card:: setCardParameter(int par)
{

}
int Card:: getCardParameter()
{
	return 0;
}

void Card:: Save (ofstream &OutFile , int Type)
{
	if(Type == 3)
	OutFile << cardNumber <<"  "<<position.GetCellNum()<<" ";
}

void Card:: Load (ifstream &InFile)
{
	InFile>> cardNumber;
}


Card::~Card()
{
}
