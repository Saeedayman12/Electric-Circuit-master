#include "ActionAddRes.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionAddRes::ActionAddRes(ApplicationManager *pApp):Action(pApp)
{
}

ActionAddRes::~ActionAddRes(void)
{
}

void ActionAddRes::Execute()
{
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new resistor: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	
		pUI->GetPointClicked(Cx, Cy);
		while (!(  Cy > UI::getToolBarHeight() + UI::getCompHeight()/2
				&& Cy < UI::Height() - UI::getStatusBarHeight() - UI::getCompHeight()/2
				&& Cx > UI::getCompWidth()/2
				&& Cx < UI::getWidth()-UI::getCompWidth()/2)) {
			pUI->GetPointClicked(Cx, Cy);
			
	 }

	//Clear Status Bar
		pUI->ClearStatusBar();
	
	
	GraphicsInfo * pGInfo= new GraphicsInfo(2); //Gfx info to be used to construct the Comp
	
	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();
	
		pGInfo->PointsList[0].x = Cx - compWidth / 2;
		pGInfo->PointsList[0].y = Cy - compHeight / 2;
		pGInfo->PointsList[1].x = Cx + compWidth / 2;
		pGInfo->PointsList[1].y = Cy + compHeight / 2;

			Resistor* pR = new Resistor(pGInfo);
			string value = pUI->GetSrting("Enter Resistance Value: default value is 1","");
			if (value == "")
				value = "1";
			pR->setresistance(stod(value));


			pUI->ClearStatusBar();

			
			pManager->AddComponent(pR);
			
	
}

void ActionAddRes::Undo()
{}

void ActionAddRes::Redo()
{}

