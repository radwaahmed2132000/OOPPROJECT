#include "Snake.h"
#include "Ladder.h"
#include"Player.h"
#include <fstream>

Snake::Snake( CellPosition& startCellPos,  CellPosition& endCellPos) : GameObject(startCellPos)
{
	if (startCellPos.HCell() == endCellPos.HCell() && startCellPos.VCell() < endCellPos.VCell() && startCellPos.GetCellNum() != 99 && endCellPos.GetCellNum() != 1)
	{
		this->endCellPos = endCellPos;


	}

	else
	{

		this->startCellPos = NULL;
		this->endCellPos = NULL;

	}


	///TODO: Do the needed validation
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

int Snake::getcheck1()
{
	return check1;
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	pGrid->PrintErrorMessage("You have reached a Snake. Click to continue ...");
	//??????
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click

	// 2- Apply the Snake's effect by moving the player to the endCellPos?????
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	if(pPlayer->GetCell()->GetGameObject()!=NULL)
	pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);
}

bool Snake::IsOverlapping(GameObject* newobj)
{
	bool exit = true;
	if (dynamic_cast<Snake*>(newobj))
	{
		Snake* snake = dynamic_cast<Snake*>(newobj);
		//prevent overlapping snake of snake
		if (position.HCell() == newobj->GetPosition().HCell())

			for (int i = position.VCell(); i <= endCellPos.VCell(); i++)
			{
				if (i >= newobj->GetPosition().VCell() && i <= snake->endCellPos.VCell())
				{
					check1 = 1;
					return false;
				}
			}

	}
	else if (dynamic_cast<Ladder*>(newobj))
	{
		//prevent overlapping snake of ladder
		Ladder* ladder = dynamic_cast<Ladder*>(newobj);
		if (position.HCell() == newobj->GetPosition().HCell())
		{

			{
				if (endCellPos.VCell() == newobj->GetPosition().VCell() || position.VCell() == ladder->GetEndPosition().VCell())
				{
					check1 = 2;
					exit = false;
				}
			}
			
		}
	}
	return exit;
}



void Snake:: Save(ofstream &OutFile , int Type)
{
	if(Type ==2)
	OutFile << position.GetCellNum() <<"  "<<endCellPos.GetCellNum()<<endl;

}

void Snake:: Load (ifstream &InFile )
{
	int i , j ;
	InFile >> i >> j;
	CellPosition C1(i) , C2(j);
	position = C1;
	endCellPos = C2;
}


CellPosition Snake::GetStartPosition() const
{
	return position;
}

Snake::~Snake()
{
}


