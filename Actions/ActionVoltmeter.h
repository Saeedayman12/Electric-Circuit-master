#pragma once
#include "Action.h"

class ActionVoltmeter : public Action
{
public:
	ActionVoltmeter(ApplicationManager* pApp);
	~ActionVoltmeter();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
private:
	int x, y;
};
