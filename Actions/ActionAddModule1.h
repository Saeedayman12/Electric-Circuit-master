#pragma once
#include "Action.h"
#include "..\Components\Module1.h"


//Class responsible for adding a new resistor action
class ActionAddModule1 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ActionAddModule1(ApplicationManager* pApp);
	virtual ~ActionAddModule1(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};