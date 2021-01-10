#include "ActionSwitchReal.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionSwitchReal::ActionSwitchReal(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSwitchReal::~ActionSwitchReal(void)
{
}
void ActionSwitchReal::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->SwitchImageType();


}
void ActionSwitchReal::Undo()
{}

void ActionSwitchReal::Redo()
{}