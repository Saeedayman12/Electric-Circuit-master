#include "ExitAction.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ExitAction::ExitAction(ApplicationManager* pApp) :Action(pApp)
{
}

ExitAction::~ExitAction(void)
{
}
void ExitAction::Execute()
{
	pManager->DelAll();

}
void ExitAction::Undo()
{}

void ExitAction::Redo()
{}