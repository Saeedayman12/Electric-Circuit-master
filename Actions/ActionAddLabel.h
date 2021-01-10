#ifndef ACTIONADDLABEL_H
#define ACTIONADDLABEL_H

#include "..\Components\Component.h"
#include "..\Components\Resistor.h"
#include "..\Components\Buzzer.h"

#include "..\Components\Bulb.h"
#include "Action.h"
//Class responsible for adding a new resistor action
class ActionAddLabel : public Action
{

public:
	ActionAddLabel(ApplicationManager* pApp);
	virtual ~ActionAddLabel(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif