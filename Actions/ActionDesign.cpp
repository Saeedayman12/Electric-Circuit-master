#include "ActionDesign.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"


ActionDesign::ActionDesign(ApplicationManager* pApp) :Action(pApp)
{

}

ActionDesign::~ActionDesign()
{

}

void ActionDesign::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->CreateDesignToolBar();
	
}

void ActionDesign::Undo()
{}

void ActionDesign::Redo()
{}