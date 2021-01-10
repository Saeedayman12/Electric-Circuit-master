#pragma once
#include "Action.h"

class ActionAmmeter : public Action
{
public:
	ActionAmmeter(ApplicationManager* pApp);
	~ActionAmmeter();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
private:
	int x, y;
};



