#include "Player.h"

#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	isExecuted==false;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
}

void Player::SetRolledDiceNum(int RolledDiceNum)
{
	//if (justRolledDiceNum>0 && justRolledDiceNum<7)
	//{
	//	this->justRolledDiceNum = justRolledDiceNum;
	//}
	//else
	//{
	//	this->justRolledDiceNum = 0;
	//}
	if(RolledDiceNum >= 0)
	justRolledDiceNum = RolledDiceNum;
	else
		justRolledDiceNum = -1 * RolledDiceNum;
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

void Player:: SetTurnCount(int turn)
{
	turnCount = turn;
}

int Player::GetRolledDiceNum()
{
	return justRolledDiceNum;
}

int Player::GetPlayerNum() const
{
return playerNum;
}

bool Player:: getIsExecuted ()
{
	return isExecuted;
}; 

void Player:: setIsExecuted(bool in)
{
	isExecuted = in;
}
// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell-> GetCellPosition(), playerNum, playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);

}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	Output *pOut=pGrid->GetOutput();
	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	turnCount++;

	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if (turnCount == 3 || turnCount % 3 == 0)
	{
		turnCount = 0;
		wallet += 10 * diceNumber;
		SetRolledDiceNum(0);

	}

	else {

		// 3- Set the justRolledDiceNum with the passed diceNumber
		{SetRolledDiceNum(diceNumber); }


		// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
		//    Using the appropriate function of CellPosition class to update "pos"
		CellPosition pos = pCell->GetCellPosition();
		pos.AddCellNum(diceNumber);

		if ( wallet<= 0)
		{
			SetRolledDiceNum(0);

		}
		// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
		//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

		{
			pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(), pos);


			// 6- Apply() the game object of the reached cell (if any)
			GameObject* pPrevObject = pCell->GetGameObject();
			if (pPrevObject != NULL)
			{
				pPrevObject->Apply(pGrid, pGrid->GetCurrentPlayer());
				pos = pCell->GetCellPosition();
			}
		}
		// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
		if (pos.GetCellNum() == 99)
		{
			pGrid->SetEndGame(true);
			pOut->PrintMessage("Congratulation!the winner is player" + to_string(pGrid->GetCurrPlayerNum()));
		}

	}
}


void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}