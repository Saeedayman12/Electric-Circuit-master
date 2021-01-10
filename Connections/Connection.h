#ifndef CONNECTION_H
#define CONNECTION_H
#include "..\UI\UI.h"
class Component;	//forward class declaration

class Connection
{
	//connection connects between two compoenets
	Component* Comp1, * Comp2;
	GraphicsInfo* pGfxInfo;	//The parameters required to draw a connection
	string c_label;
	bool selected;
public:
	
	Connection(GraphicsInfo* r_GfxInfo, Component* cmp1 = nullptr, Component* cmp2 = nullptr);
	void Load(Component* cmp1, Component* cmp2);
	void save(ofstream& CircuitFile,int comp1, int comp2);
	void setLabel(string s);
	string getLabel();
	double lineslope();
	GraphicsInfo* getgraphics() const;
	virtual void Draw(UI*);	//for connection to Draw itself
	Component* getComp(int n);
	void setNewComp(int n, Component*);
	void deleteGraphics();
	int WhichComp(Component*);
	bool validate(Connection*);
	bool isSelected();
	void Selection();
	void unSelect();
	//Component* getOtherComponent(Component* Cmpnt); // Get component connected to the other end of the connection

};
#endif