#include "ActionDelete.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{
}

ActionDelete::~ActionDelete(void)
{
}
void ActionDelete::Execute()
{

	pManager->DelSelected();
	
	
}
void ActionDelete::Undo()
{}

void ActionDelete::Redo()
{}