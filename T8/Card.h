#pragma once
#include "GameObject.h"
#include "Player.h"

// Base Class of All Types of Cards (CardOne, CardTwo, CardThree, ...etc.)
// Note: We will make each type of Card in a separate class because:
// it may have additional data members and functions like: Apply(), ...etc. which have different implementation depending on Card Number
class Card : public GameObject
{
protected:
	int cardNumber; // an integer representing the card number
	bool isExecuted;

public:
	Card(const CellPosition & pos); // A Constructor for card that takes the cell position of it
	
	 void SetData(Card*);      //setter to copy data from one card to another using pointer to the base class
	 virtual void SetDataNine(Card*);       //setter data of card nine
		                                   // It is a virtual function (implementation depends on Card Type)

	virtual CellPosition GetDataNine();    //getter data of card nine
		                                   // It is a virtual function (implementation depends on Card Type)

	virtual void SetDataOne(Card*);        //setter data of card one
		                                   // It is a virtual function (implementation depends on Card Type)

	virtual int GetDataOne();              //getter data of card one
		                                   // It is a virtual function (implementation depends on Card Type)

	virtual void SetDataTwo(Card*);        //setter data of card two
		                                   // It is a virtual function (implementation depends on Card Type)

	virtual int GetDataTwo();              //getter data of card two
		                                   // It is a virtual function (implementation depends on Card Type)


	void SetCardNumber(int cnum);   // The setter of card number
	int GetCardNumber();            // The getter of card number

	virtual void setCardParameter(int par);
	virtual int getCardParameter();

	virtual void changeparameters(Grid * pGrid);
	
	void Draw(Output* pOut) const;  // Draws the card number in the cell position of the card
	                                // It has the same implementation for all Card Types (Non-Virtual)

	
	virtual void ReadCardParameters(Grid * pGrid); // It reads the parameters specific for each Card Type
	                                               // It is a virtual function (implementation depends on Card Type)

	 virtual bool isrepeated();

	virtual void Apply(Grid* pGrid, Player* pPlayer);  // It applies the effect of the Card Type on the passed player
	                                                   // It is a virtual function (implementation depends on Card Type)

	
	/*bool getIsExecuted (); 
	void setIsExecuted (bool in);*/

	virtual void Save (ofstream &OutFile , int Type); 
	virtual void Load (ifstream &InFile);

	virtual ~Card(); // A Virtual Destructor
};

