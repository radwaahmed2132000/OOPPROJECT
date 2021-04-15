#include "Ladder.h"
#include "Cell.h"
#include "Snake.h"
#include "Player.h"
#include <fstream>


Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	if (startCellPos.HCell() == endCellPos.HCell() && startCellPos.VCell() > endCellPos.VCell() && (endCellPos.GetCellNum() != 99) && startCellPos.GetCellNum() != 1)
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

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

int Ladder::getcheck1()
{
	return check1;
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a ladder. Click to continue ...");

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	if (pPlayer->GetCell()->GetGameObject() != NULL)
	pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

CellPosition Ladder::GetStartPosition() const
{
	return position;
}

bool Ladder::IsOverlapping(GameObject* newobj)
{
	bool exit = true;
	if (dynamic_cast<Ladder*>(newobj))
	{
		//prevent overlapping ladder of ladder
		Ladder* ladder = dynamic_cast<Ladder*>(newobj);

		if (position.HCell() == newobj->GetPosition().HCell())
		{
			for (int i = position.VCell(); i >= endCellPos.VCell(); i--)
			{

				if (i <= newobj->GetPosition().VCell() && i >= ladder->endCellPos.VCell())
				{
					check1 = 1;
					return false;

				}
			}

		}
	}
	else if (dynamic_cast<Snake*>(newobj))
	{
		//prevent overlapping ladder of snake 
		if (position.HCell() == newobj->GetPosition().HCell())
		{
			Snake* snake = dynamic_cast<Snake*>(newobj);

			if (endCellPos.VCell() == newobj->GetPosition().VCell() || position.VCell() == snake->GetEndPosition().VCell())
			{
				exit = false;
				check1 = 2;
			}



		}
	}
	return exit;

}

void Ladder:: Save(ofstream &OutFile , int Type)
{
	if (Type == 1)
	OutFile << position.GetCellNum() <<"  "<<endCellPos.GetCellNum()<<endl;

}

void Ladder:: Load (ifstream &InFile )
{
	int i , j ;
	InFile >> i >> j;
	CellPosition C1(i) , C2(j);
	position = C1;
	endCellPos = C2;
}


Ladder::~Ladder()
{
}
