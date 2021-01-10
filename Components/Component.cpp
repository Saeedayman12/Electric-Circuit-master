#include "Component.h"
int Component::ID = 1;
Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;	
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;
	selected = false;
	CompStatus = CLOSED;
}

Component::Component()
{
	m_pGfxInfo = nullptr;
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;
	selected = false;
	CompStatus = CLOSED;
}
void Component::resetID(){
	ID = 1;
}
void Component::addTerm1Conn(Connection* c) {
	term1_conns[term1_conn_count++] = c;
}
void Component::addTerm2Conn(Connection* c) {
	term2_conns[term2_conn_count++] = c;
}
int Component::getTermcount(TerminalNum Term) {
	switch (Term) {
	case TERM1:
		return term1_conn_count;
		break;
	case TERM2:
		return term2_conn_count;
		break;
	default: return 0;
	}
}

Connection** Component::getTermConnections(TerminalNum Term) {
	switch (Term) {
	case TERM1:
		return term1_conns;
		break;
	case TERM2:
		return term2_conns;
		break;
	default:
		return nullptr;
	}
		
}
void Component::setlabel(string s)  {
	m_Label = s;
}
string Component::getlabel()const {
	return m_Label;
}
void Component::setresistance(double R) {
	resistance = R;
}
bool Component::validate() {
	//makes sure that this components has only one connection at each terminal
	if (term1_conn_count == 1 && term2_conn_count == 1)
		return true;
	else
		return false;
}
void Component::setSourceVoltage(int V) {
	sourceVoltage = V;
}
int Component::getSourceVoltage() {
	return sourceVoltage;
}

int Component::getCompCenterX(UI* pUI) {
	return m_pGfxInfo->PointsList[0].x+pUI->getCompWidth()/2;
}
int Component::getCompCenterY(UI* pUI) {
	return m_pGfxInfo->PointsList[0].y+pUI->getCompHeight()/2;
}
GraphicsInfo* Component::getGraphics() {
	return m_pGfxInfo;
}
int Component::getGraphicsInfoY() {
	return m_pGfxInfo->PointsList[0].x;
}
int Component::getGraphicsInfoX() {
	return m_pGfxInfo->PointsList[0].y;
}
void Component::deleteGraphics() {
	delete m_pGfxInfo;
}

void Component::deletecon(Connection* pCon) {
	for (int i = 0; i < term1_conn_count; i++) {
		if (term1_conns[i] == pCon)
			term1_conns[i] = nullptr;
	}
	for (int i = 0; i < term2_conn_count; i++) {
		if (term2_conns[i] == pCon)
			term2_conns[i] = nullptr;
	}
	
}
void Component::reArrange() {
	Connection* tempConnList[MAX_CONNS];
	int counter = 0;
	for (int i = 0; i < term1_conn_count; i++)
		if (term1_conns[i] != nullptr) {
			tempConnList[counter] = term1_conns[i];
			counter++;
		}
	for (int i = 0; i < term1_conn_count; i++) {
		term1_conns[i] = tempConnList[i];
		tempConnList[i] = nullptr;
	}
	term1_conn_count = counter;
	counter = 0;
	for (int i = 0; i < term2_conn_count; i++)
		if (term2_conns[i] != nullptr) {
			tempConnList[counter] = term2_conns[i];
			counter++;
		}
	for (int i = 0; i < term2_conn_count; i++) {
		term2_conns[i] = tempConnList[i];
		tempConnList[i] = nullptr;
	}
	term2_conn_count = counter;
}


bool Component::isSelected() {
	
	return selected;
}
void Component::Selection() {
	if (selected == false)
		selected = true;
	else
		selected = false;
}
void Component::unSelect() {
	selected = false;
}
string Component::getLabel() {
	return m_Label;
}
int Component::getResistance() {
	return resistance;
}
void Component::setState(int S) {
	switch (S) {
	case 1:
		CompStatus = CLOSED;
		break;
	case 0:
		CompStatus = OPEN;
		break;
	default:
		CompStatus = CLOSED;
	}
}
int Component::getCompState() {
	return CompStatus;
}
void Component::setTerm1Volt(double v) {
	term1_volt = v;
}//sets the voltage at terminal1
void Component::setTerm2Volt(double v) {
	term2_volt = v;
}	//sets the voltage at terminal2
TerminalNum Component::whichTerminal(Connection* Conn) {
	for (int i = 0; i < term1_conn_count; i++) {
		if (term1_conns[i] == Conn)
			return TERM1;
	}
	
	for (int i = 0; i < term2_conn_count; i++)
		if (term2_conns[i]==Conn) {
			return TERM2;
		}
}
Component::~Component()
{
	/*for (int i = 0; i < term1_conn_count; i++) {
		delete term1_conns[i];
		term1_conns[i] = nullptr;
	}
	for (int i = 0; i < term1_conn_count; i++) {
		delete	term2_conns[i];	
		term1_conns[i] = nullptr;
	}*/

}

