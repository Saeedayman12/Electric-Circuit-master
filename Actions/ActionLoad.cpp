#include "ActionLoad.h"
#include "..\ApplicationManager.h"
#include "ActionAddRes.h"

ActionLoad::ActionLoad(ApplicationManager* pApp) :Action(pApp)
{
}

ActionLoad::~ActionLoad(void)
{
}

void ActionLoad::Execute()
{

	UI* pUI = pManager->GetUI();

	pManager->Load(file, pUI->GetSrting("Write the name of the file: (Ex: test) ","") + ".txt");

}

void ActionLoad::Undo()
{}

void ActionLoad::Redo()
{}