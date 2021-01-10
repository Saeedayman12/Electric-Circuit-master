#ifndef ActionAddFuze_H
#define ActionAddFuze_H
#include "Action.h"
#include "..\Components\Fuze.h"


//Class responsible for adding a new resistor action
class ActionAddFuze : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ActionAddFuze(ApplicationManager* pApp);
	virtual ~ActionAddFuze(void);

	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void ActionAddFuze::Undo();

	virtual void ActionAddFuze::Redo();
};
#endif
