#ifndef ACTIONEDIT_H
#define ACTIONEDIT_H

#include "..\Components\Component.h"
#include "..\Components\Resistor.h"
#include "..\Components\Buzzer.h"

#include "..\Components\Bulb.h"
#include "Action.h"
//Class responsible for adding a new resistor action
class ActionEdit : public Action
{

public:
	ActionEdit(ApplicationManager* pApp);
	virtual ~ActionEdit(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif