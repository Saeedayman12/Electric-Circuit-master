#ifndef ActionDropDown_H
#define ActionDropDown_H
#include "Action.h"



//Class responsible for adding a new resistor action
class ActionDropDown : public Action
{
public:
	ActionDropDown(ApplicationManager* pApp);
	virtual ~ActionDropDown(void);

	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void ActionDropDown::Undo();

	virtual void ActionDropDown::Redo();
};
#endif
