#include "ActionDropDown.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionDropDown::ActionDropDown(ApplicationManager* pApp) :Action(pApp)
{
}

ActionDropDown::~ActionDropDown(void)
{
}
void ActionDropDown::Execute()
{
	UI* pUI = pManager->GetUI();
	if (pUI->dropdown)
		pUI->dropdown = false;
	else
		pUI->dropdown = true;


}
void ActionDropDown::Undo()
{}

void ActionDropDown::Redo()
{}