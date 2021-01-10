#include"Bulb.h"
Bulb::Bulb(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 2; // TODO: Take resistance from user
	sourceVoltage = 0;
}

void Bulb::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	int xlabel = m_pGfxInfo->PointsList[0].x;
	int ylabel = m_pGfxInfo->PointsList[0].y + 50;
	pUI->labelMsg(getLabel(), xlabel, ylabel);
	pUI->DrawBulb(*m_pGfxInfo,selected); //update to draw Bulb

}
void Bulb::SaveCircuit(ofstream& CircuitFile)
{
	string s = getlabel();
	if (getlabel() == "")
		setlabel("Bulb");
	CircuitFile << "BLB" << "\t" << ID << "\t" << getLabel() << "\t" << resistance<< "\t" << m_pGfxInfo->PointsList[0].x
		<< "\t" << m_pGfxInfo->PointsList[0].y << endl;
	ID++;
	setlabel(s);
}
void Bulb::Operate()
{

}
void Bulb::Load(int Value, string Label) {
	resistance=Value;
	setlabel(Label);
}
ALLCOMPS Bulb::whichComponent() {
	return BULB;
}