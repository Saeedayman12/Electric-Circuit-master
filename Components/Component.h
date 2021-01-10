#ifndef COMPONENT_H
#define COMPONENT_H

#include "..\Defs.h"
#include "..\UI\UI.h"
#include "..\Connections\Connection.h"
#include"..\ApplicationManager.h"
//Base class for all components (resistor, capacitor,....etc) .
class Component
{
private:
	string m_Label;
	
protected:
	static int ID;
	//int MaxFuzeCurrent = 0;
	Status CompStatus;
	//Each component has two ending terminals (term1, term2)
	//double term1_volt, term2_volt;	//voltage at terminals 1&2
	double resistance, sourceVoltage; // internal resistance and voltage jump introduced by source
	//Each terminal is connected to set of connections
	Connection *term1_conns[MAX_CONNS]; //list of pointers to connections
	Connection *term2_conns[MAX_CONNS];

	int term1_conn_count;	//actual no. of connections to each terminal
	int term2_conn_count;
	bool selected;
	GraphicsInfo *m_pGfxInfo;	//The parameters required to draw a component
public:
	double term1_volt, term2_volt;
	static void resetID();
	void addTerm1Conn(Connection*);
	void addTerm2Conn(Connection*);
	void setlabel(string s) ;
	string getlabel()const;
	Component(GraphicsInfo *r_GfxInfo);
	Component();
	void setresistance(double R);
	bool validate();
	//Connection** getTerm1_conns();
	//Connection** getTerm2_conns();
	void deleteGraphics();
	void deletecon(Connection* pCon);
	bool isSelected();
	void Selection();
	void unSelect();
	/*void setMaxFuze(int max) {
		MaxFuzeCurrent = max;
	}
	int getMaxFuze() {
		return MaxFuzeCurrent;
	}*/
	void reArrange();
	int getTermcount(TerminalNum Term);
	Connection** getTermConnections(TerminalNum Term);
	string getLabel();
	GraphicsInfo* getGraphics();
	int getResistance();
	void setSourceVoltage(int V);
	int getSourceVoltage();
	void setState(int S);
	int getCompState();
	void setTerm1Volt(double v);		//sets the voltage at terminal1
	void setTerm2Volt(double v);		//sets the voltage at terminal2
	//double getTerm1Volt();				//returns the voltage at terminal1
	//double getTerm2Volt();				//returns the voltage at terminal2
	//double getResistance();
	//double getSourceVoltage(TerminalNum Term); // entering from terminal Term. Returns voltage jump/drop for battery, 0 otherwise


	//double CalculateTermVoltage(TerminalNum term, double voltAtTerm, double currIntoTerm);	//Calculates the output voltage according to the inputs, sets terminal voltages
	virtual void Operate() = 0; // activates components such as bulb and buzzer
	virtual ALLCOMPS whichComponent() = 0;
	virtual void Draw(UI*) = 0;	//for each component to Draw itself
	virtual void Load(int Value, string )=0;
	virtual void SaveCircuit(ofstream& CircuitFile) = 0;
	int getCompCenterX(UI*); // get horizontal/vertical centers of the component
	int getCompCenterY(UI*);
	int getGraphicsInfoY();
	int getGraphicsInfoX();
	//virtual int GetOutStatus()=0;	//returns status of output if BULB/BUZZER, return -1
	//virtual int GetInputStatus()=0;	//returns status of SWITCH, return -1
	
//virtual void setInputStatus(STATUS s)=0;	//set status of SWITCH

	//bool isInRegion(int x, int y, UI* pUI); // whether this point lies inside the component
	TerminalNum whichTerminal(Connection* Conn); // returns the terminal to which a connection is connected

	//Destructor must be virtual
	virtual ~Component();
};

#endif
