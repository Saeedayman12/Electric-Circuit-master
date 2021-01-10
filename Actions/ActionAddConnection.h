#ifndef ActionAddConnection_H
#define ActionAddConnection_H
#include "Action.h"
#include"..\Connections\Connection.h"
//Class responsible for adding a new resistor action
class ActionAddConnection : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx1, Cy1, Cx2, Cy2;//points clicked
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ActionAddConnection(ApplicationManager* pApp);
	virtual ~ActionAddConnection(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif