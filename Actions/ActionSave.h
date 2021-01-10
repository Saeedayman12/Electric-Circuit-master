#pragma once

#include "Action.h"
#include "..\Components\Component.h"


class ActionSave : public Action
{
private:
	ofstream CircuitFile;
	int x, y;

public:
	ActionSave(ApplicationManager* pApp);
	virtual ~ActionSave(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};