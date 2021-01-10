#pragma once
#include "Component.h"

class Module1 :public Component
{
public:
	Module1(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	
	virtual void Operate();
	virtual void Load(int Value, string);
	virtual void SaveCircuit(ofstream& CircuitFile);
	virtual ALLCOMPS whichComponent();
};