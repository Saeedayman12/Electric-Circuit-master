#pragma once

#include "Action.h"


class ActionSwitchSimulation : public Action
{
public:
	ActionSwitchSimulation(ApplicationManager* pApp);
	virtual ~ActionSwitchSimulation(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};