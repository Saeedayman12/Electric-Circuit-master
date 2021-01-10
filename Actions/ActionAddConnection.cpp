#include "ActionAddConnection.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionAddConnection::ActionAddConnection(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddConnection::~ActionAddConnection(void)
{
}

void ActionAddConnection::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new connection: select the first component");

	pUI->GetPointClicked(Cx1, Cy1);
	Component* comp1 = pManager->GetComponentByCordinates(Cx1, Cy1);
	if (!(comp1 == nullptr)) {
		pUI->ClearStatusBar();

		pUI->PrintMsg("Adding a new connection: select the second component");
		pUI->GetPointClicked(Cx2, Cy2);
		Component* comp2 = pManager->GetComponentByCordinates(Cx2, Cy2);

		pUI->ClearStatusBar();
		if (!(comp2 == nullptr)) {
			GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

			//Calculate the rectangle Corners
			int compWidth = pUI->getCompWidth();
			int compHeight = pUI->getCompHeight();
			x1 = comp1->getCompCenterX(pUI);
			x2 = comp2->getCompCenterX(pUI);		
			y1 = comp1->getCompCenterY(pUI);
			y2 = comp2->getCompCenterY(pUI);

			if (Cx1 > x1) {
				pGInfo->PointsList[0].x = x1 + (compWidth / 2);
				pGInfo->PointsList[0].y = y1;
			}
			else {
				pGInfo->PointsList[0].x = x1 - (compWidth / 2);
				pGInfo->PointsList[0].y = y1;

			}
			if (Cx2 > x2) {
				pGInfo->PointsList[1].x = x2 + (compWidth / 2);
				pGInfo->PointsList[1].y = y2;
			}
			else {
				pGInfo->PointsList[1].x = x2 - (compWidth / 2);
				pGInfo->PointsList[1].y = y2;

			}





			Connection* pC = new Connection(pGInfo, comp1, comp2);
			if (Cx1 > x1)
				comp1->addTerm2Conn(pC);
			else
				comp1->addTerm1Conn(pC);

			if (Cx2 > x2)
				comp2->addTerm2Conn(pC);
			else
				comp2->addTerm1Conn(pC);


			pManager->AddConnection(pC);
		}
	}
}

 void ActionAddConnection::Undo()
{}

void ActionAddConnection::Redo()
{}