#include "ActionEdit.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
#include<string>  
ActionEdit::ActionEdit(ApplicationManager* pApp) :Action(pApp)
{
}

ActionEdit::~ActionEdit(void)
{
}
void ActionEdit::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Select the component/connection you wish to Edit");
	int x, y;


	/// ///////////
	pUI->GetPointClicked(x, y);
	Component* comp1 = pManager->GetComponentByCordinates(x,y);
	Connection* conn1 = pManager->GetConnByCordinates(x, y);
	/*while (comp1 == nullptr && conn1 == nullptr) {
		pUI-> GetPointClicked(x, y);
		pUI->PrintMsg("Select the compnent/Connection you want to edit");
	}*/
	// // // // // // / //
		pUI->ClearStatusBar();
		comp1 = pManager->GetComponentByCordinates(x, y);
		conn1 = pManager->GetConnByCordinates(x, y);
		if (comp1 != nullptr) {
			ALLCOMPS CompNumber = comp1->whichComponent();
			switch (CompNumber) {
			case RESISTOR:
			case BULB:
			case FUZE:
			case BUZZER:
			{
				//pUI->PrintMsg("enter 1 to edit the label, 2 to the edit resistace value or 3 to cancel ");
				string value;
				int intValue;
					do {
						value = pUI->GetSrting("enter 1 to edit the label, 2 to the edit resistace value or 3 to cancel ", "");
					} while (value != "1" && value != "2" && value != "3");
					intValue = stod(value);
					switch (intValue) {
					case 1:
					{
						
						value = pUI->GetSrting(comp1->getLabel(), comp1->getLabel());
						comp1->setlabel(value);
						break;
					}
					case 2:
					{
						value = pUI->GetSrting(to_string(comp1->getResistance()), to_string(comp1->getResistance()));
						comp1->setresistance(stod(value));
						break;
					}
					case 3:
						break;
					}
					break;
					
			}
			//case FUZE:
			//{	//pUI->PrintMsg("enter 1 to edit the label, 2 to the edit Maximum Fuze current value or 3 to cancel ","");
			//	string value;
			//	int intValue;
			//	do {
			//		value = pUI->GetSrting("enter 1 to edit the label, 2 to the edit Maximum Fuze current value or 3 to cancel ", "");
			//	} while (value != "1" && value != "2" && value != "3");
			//	intValue = stod(value);
			//	switch (intValue) {
			//	case 1:
			//	{

			//		value = pUI->GetSrting(comp1->getLabel(), comp1->getLabel());
			//		comp1->setlabel(value);
			//		break;
			//	}
			//	case 2:
			//	{
			//		value = pUI->GetSrting(to_string(comp1->getMaxFuze()), to_string(comp1->getMaxFuze()));
			//		comp1->setMaxFuze(stod(value));
			//		break;
			//	}
			//	case 3:
			//		break;
			//	}
			//	break;
			//}
			case SWITCH:
			{	//pUI->PrintMsg("enter 1 to edit the label, 2 to the edit Maximum Fuze current value or 3 to cancel ","");
				string value;
				int intValue;
				do {
					value = pUI->GetSrting("enter 1 to edit the label, 2 to the edit Switch status or 3 to cancel ", "");
				} while (value != "1" && value != "2" && value != "3");
				intValue = stod(value);
				switch (intValue) {
				case 1:
				{

					value = pUI->GetSrting(comp1->getLabel(), comp1->getLabel());
					comp1->setlabel(value);
					break;
				}
				case 2:
				{
					value = pUI->GetSrting(to_string(comp1->getCompState()), to_string(comp1->getCompState()));
					comp1->setState(stod(value));
					break;
				}
				case 3:
					break;
				}
				break;
			}
			case BATTERY:
			{	//pUI->PrintMsg("enter 1 to edit the label, 2 to the edit Maximum Fuze current value or 3 to cancel ","");
				string value;
				int intValue;
				do {
					value = pUI->GetSrting("enter 1 to edit the label, 2 to the edit Battery voltage or 3 to cancel ", "");
				} while (value != "1" && value != "2" && value != "3");
				intValue = stod(value);
				switch (intValue) {
				case 1:
				{

					value = pUI->GetSrting(comp1->getLabel(), comp1->getLabel());
					comp1->setlabel(value);
					break;
				}
				case 2:
				{
					value = pUI->GetSrting(to_string(comp1->getSourceVoltage()), to_string(comp1->getSourceVoltage()));
					comp1->setSourceVoltage(stod(value));
					break;
				}
				case 3:
					break;
				}
				break;
			}
			case GROUND:
			{	//pUI->PrintMsg("enter 1 to edit the label, 2 to the edit Maximum Fuze current value or 3 to cancel ","");
				string value;
				int intValue;
				do {
					value = pUI->GetSrting("enter 1 to edit the label or 2 to cancel ", "");
				} while (value != "1" && value != "2");
				intValue = stod(value);
				switch (intValue) {
				case 1:
				{

					value = pUI->GetSrting(comp1->getLabel(), comp1->getLabel());
					comp1->setlabel(value);
					break;
				}
				
				case 2:
					break;
				}
				break;
			}
			}
		}
		else if (conn1 != nullptr) {
		string value;
		int intValue;
		do {
			value = pUI->GetSrting("enter 1 to edit the label,2 to change terminals or 3 to cancel ", "");
		} while (value != "1" && value != "2" && value != "3");
		intValue = stod(value);
		switch (intValue) {
		case 1:
		{

			value = pUI->GetSrting(conn1->getLabel(), conn1->getLabel());
			conn1->setLabel(value);
			break;
		}
		case 2: {
			int x, y;
			GraphicsInfo* G = new GraphicsInfo(2);
			G = conn1->getgraphics();
			pUI->PrintMsg("Select the Terminal which you want to change");
			pUI->GetPointClicked(x, y);
			pUI->ClearStatusBar();
			Component* tempComp1 = pManager->GetComponentByCordinates(x, y);
			Component* tempComp2;
			if (tempComp1 != nullptr) {
				int compnum = conn1->WhichComp(tempComp1);
				if (compnum != 0) {
					pUI->PrintMsg("Select the new Component you want to connect to: ");
					pUI->GetPointClicked(x, y);
					pUI->ClearStatusBar();
					tempComp2 = pManager->GetComponentByCordinates(x, y);
					if (tempComp2 != nullptr) {
						tempComp1->deletecon(conn1);
						if (x > tempComp2->getCompCenterX(pUI)) {
							tempComp2->addTerm2Conn(conn1);
							G->PointsList[compnum - 1].x = tempComp2->getCompCenterX(pUI) + (pUI->getCompWidth() / 2);
							G->PointsList[compnum - 1].y = tempComp2->getCompCenterY(pUI);
						}
						else {
							tempComp2->addTerm1Conn(conn1);
							G->PointsList[compnum - 1].x = tempComp2->getCompCenterX(pUI) - (pUI->getCompWidth() / 2);
							G->PointsList[compnum - 1].y = tempComp2->getCompCenterY(pUI);

						}
						conn1->setNewComp(compnum, tempComp2);
					}
				}
			}
			break;
		}
		case 3:
			break;
		}
		}
	pUI->ClearStatusBar();
}
void ActionEdit::Undo()
{}

void ActionEdit::Redo()
{}