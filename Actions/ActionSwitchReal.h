#ifndef ActionSwitchReal_H
#define ActionSwitchReal_H
#include "Action.h"



//Class responsible for adding a new resistor action
class ActionSwitchReal : public Action
{
private:
public:
	ActionSwitchReal(ApplicationManager* pApp);
	virtual ~ActionSwitchReal(void);

	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void ActionSwitchReal::Undo();

	virtual void ActionSwitchReal::Redo();
};
#endif

