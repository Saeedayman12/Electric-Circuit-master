#ifndef RESISTOR_H
#define RESISTOR_H

#include "Component.h"

class Resistor:public Component
{
public:
	Resistor(GraphicsInfo *r_GfxInfo);
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Operate();
	virtual void Load(int Value, string);
	virtual void SaveCircuit(ofstream& CircuitFile);
	virtual ALLCOMPS whichComponent();
};
#endif