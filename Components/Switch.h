#ifndef SWITCH_H
#define SWITCH_H

#include "Component.h"

class Switch :public Component
{
public:
	Switch(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Operate();
	virtual void Load(int Value, string);
	virtual void SaveCircuit(ofstream& CircuitFile);
	virtual ALLCOMPS whichComponent();
};
#endif