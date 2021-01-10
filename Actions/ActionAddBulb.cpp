#include "ActionAddBulb.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionAddBulb::ActionAddBulb(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddBulb::~ActionAddBulb(void)
{
}

void ActionAddBulb::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new Bulb: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);
	while (!(Cy > UI::getToolBarHeight() + UI::getCompHeight() / 2
			&& Cy < UI::Height() - UI::getStatusBarHeight() - UI::getCompHeight() / 2
			&& Cx > UI::getCompWidth() / 2
			&& Cx < UI::getWidth() - UI::getCompWidth() / 2)) {
		pUI->GetPointClicked(Cx, Cy);
	}

	//Clear Status Bar
	pUI->ClearStatusBar();


	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();
	
	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Bulb* pB = new Bulb(pGInfo);
	string value = pUI->GetSrting("Enter value Bulb Resistance Value, Default value is 2","2");
	while (value == "")
		value = pUI->GetSrting();
	pB->setresistance(stod(value));
	pUI->ClearStatusBar();

	pManager->AddComponent(pB);
}

void ActionAddBulb::Undo()
{}

void ActionAddBulb::Redo()
{}