#include "Ground.h"
#include "..\Actions\Action.h"
#include <stdlib.h>
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
Ground::Ground(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 0;
	sourceVoltage = 0;
}

void Ground::Draw(UI* pUI)
{
	int xlabel = m_pGfxInfo->PointsList[0].x;
	int ylabel = m_pGfxInfo->PointsList[0].y + 50;

	pUI->labelMsg(getlabel(), xlabel, ylabel);
	pUI->DrawGround(*m_pGfxInfo, selected);




}
void Ground::SaveCircuit(ofstream& CircuitFile)
{
	string s = getlabel();
	if (getlabel() == "")
		setlabel("Ground");
	CircuitFile << "GND" << "\t" << ID << "\t" << getLabel() << "\t" << -1 << "\t" << m_pGfxInfo->PointsList[0].x
		<< "\t" << m_pGfxInfo->PointsList[0].y << endl;
	ID++;
	setlabel(s);
}
void Ground::Operate()
{

}
void Ground::Load(int Value, string Label) {
	setlabel(Label);
}
ALLCOMPS Ground::whichComponent() {
	return 	GROUND;
}