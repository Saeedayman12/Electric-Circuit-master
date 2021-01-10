#pragma once
#include "Action.h"

class ActionDesign : public Action
{
public:
	ActionDesign(ApplicationManager* pApp);
	~ActionDesign();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

