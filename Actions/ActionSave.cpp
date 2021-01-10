#include "ActionSave.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionSave::ActionSave(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSave::~ActionSave(void)
{
}
void ActionSave::Execute()
{
	UI* pUI = pManager->GetUI();
string fileName = pUI->GetSrting("Enter File name please ", ""); //Gets the name of the file from the user
fileName = fileName + ".txt";
if (fileName == "") //Conditon in case the user does not enter any name
	fileName = "test.txt";
	CircuitFile.open(fileName);
	CircuitFile.clear();
	pManager->SaveCircuit(CircuitFile);
	CircuitFile << "END_OF_FILE" << endl;
	pManager->GetUI()->PrintMsg("Circuit has been saved successfully");
	CircuitFile.close();
	//fstream saveFile;
	//UI* pUI = pManager->GetUI();
	//string fileName = pUI->GetSrting("Enter File name please ", ""); //Gets the name of the file from the user
	//if (fileName == "") //Conditon in case the user does not enter any name
	//	fileName = "test";
	//	+ ".txt";
	//pManager->Save(saveFile, fileName);//Invokes the save function in the application manager file

}
void ActionSave::Undo()
{}

void ActionSave::Redo()
{}