#include "ActionAddLabel.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionAddLabel::ActionAddLabel(ApplicationManager* pApp) :Action(pApp)
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Select the component you wish to label");
	int x;
	int y;
	pUI->GetPointClicked(x, y);
	Component* comp1 = pManager->GetComponentByCordinates(x, y);
	Connection* conn1 = pManager->GetConnByCordinates(x, y);
	pUI->ClearStatusBar();
	if (comp1 != nullptr) {
		
		string value = pUI->GetSrting("Enter label for the selected component","");
		comp1->setlabel(value);
	}
	else if (conn1 != nullptr) {
		
		string value = pUI->GetSrting("Enter label for the selected connection","");
		conn1->setLabel(value);
	}
}

ActionAddLabel::~ActionAddLabel(void)
{
}
void ActionAddLabel::Execute()
{
	
}
void ActionAddLabel::Undo()
{
}
void ActionAddLabel::Redo()
{
}