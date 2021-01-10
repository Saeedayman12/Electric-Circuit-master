#pragma once

#include "Action.h"
#include "..\Components\Component.h"


class ActionSelect : public Action
{
private:
	
	int x, y;
	
public:
	ActionSelect(ApplicationManager* pApp);
	virtual ~ActionSelect(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};