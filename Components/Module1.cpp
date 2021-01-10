#include "Module1.h"
#include "..\Actions\Action.h"
#include <stdlib.h>
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
Module1::Module1(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 2;
	sourceVoltage = 0;
}

void Module1::Draw(UI* pUI)
{
	int xlabel = m_pGfxInfo->PointsList[0].x;
	int ylabel = m_pGfxInfo->PointsList[0].y + 50;

	pUI->labelMsg(getlabel(), xlabel, ylabel);
	pUI->DrawModule1(*m_pGfxInfo, selected);
}
void Module1::SaveCircuit(ofstream& CircuitFile)
{
	string s = getlabel();
	if (getlabel() == "")
		setlabel("Module1");
	CircuitFile << "MOD1" << "\t" << ID << "\t" << getLabel() << "\t" << resistance << "\t" << m_pGfxInfo->PointsList[0].x
		<< "\t" << m_pGfxInfo->PointsList[0].y << endl;
	ID++;
	setlabel(s);
}
void Module1::Operate()
{

}
void Module1::Load(int Value, string Label)
{
	resistance = Value;
	setlabel(Label);
}
ALLCOMPS Module1::whichComponent()
{
	return 	MODULE_1;
}