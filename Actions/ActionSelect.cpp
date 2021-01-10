#include "ActionSelect.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSelect::~ActionSelect(void)
{
}
void ActionSelect::Execute() {
	UI* pUI = pManager->GetUI();//Gets a pointer to the user interface
	x = pUI->getXtemp();//Gets the coordinates which the user clicked on
	y = pUI->getYtemp();
	Component* comp1 = pManager->GetComponentByCordinates(x, y);
	Connection* conn1 = pManager->GetConnByCordinates(x, y);
	if (comp1 != nullptr){
		
		//pManager->UnselectAll(comp1); //this line was used to make no more than one thing to be selected
		comp1->Selection();
	}
	else if (conn1 != nullptr) {
		
		//pManager->UnselectAll(conn1); 
		conn1->Selection();
	}

}
void ActionSelect::Undo()
{}

void ActionSelect::Redo()
{}