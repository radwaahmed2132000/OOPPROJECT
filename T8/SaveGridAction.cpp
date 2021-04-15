#include "SaveGridAction.h"

#include "Input.h"
#include "Output.h"
#include "GameObject.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"

SaveGridAction::SaveGridAction(ApplicationManager *pApp) : Action(pApp)
{

	
	// Initializes the pManager pointer of Action with the passed pointer
}

void SaveGridAction::ReadActionParameters() 
{	
	Grid * pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	string FileName;
	pOut->PrintMessage("Enter The File Name to save ,please");
	FileName=pIn->GetSrting(pOut)+".txt";
	outputFile.open(FileName , ios::out); 
	pOut->ClearStatusBar();
}


// Execute the action
void SaveGridAction::Execute() 
{
	ReadActionParameters();
	Grid * pGrid = pManager->GetGrid();
	 // We get a pointer to the Grid from the ApplicationManager

	CardTen::setC10(true);
	CardEleven::setC11(true);
	CardTwelve::setC12(true);
	CardThirteen::setC13(true);
	CardFourteen::setC14(true);

	outputFile<<pGrid->ObjectNum(1)<<endl;
	pGrid->SaveAll(outputFile,1);
	outputFile<<pGrid->ObjectNum(2)<<endl;
	pGrid->SaveAll(outputFile,2);
	outputFile<<pGrid->ObjectNum(3)<<endl;
	pGrid->SaveAll(outputFile,3);

	

}


SaveGridAction::~SaveGridAction(void)
{
	outputFile.close();
}
