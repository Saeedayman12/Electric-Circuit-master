#ifndef ActionAddGround_H
#define ActionAddGround_H
#include "Action.h"
#include "..\Components\Ground.h"


//Class responsible for adding a new resistor action
class ActionAddGround : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ActionAddGround(ApplicationManager* pApp);
	virtual ~ActionAddGround(void);

	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void ActionAddGround::Undo();

	virtual void ActionAddGround::Redo();
};
#endif