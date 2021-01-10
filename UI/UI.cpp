#include "UI.h"


UI::UI()
{
	AppMode = DESIGN;	//Design Mode is the startup mode
	img = Schem;
	dropdown = false;
	//Initilaize interface colors
	DrawColor = BLACK;
	SelectColor = BLUE;
	ConnColor = RED;
	MsgColor = BLACK;
	BkGrndColor = WHITE;
	
	//Create the drawing window

	pWind = new window(width, height, wx, wy);	


	ChangeTitle("Circuit Simulator Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	//CreateSimulationToolBar();
	CreateStatusBar();		//Create Status bar
	xtemp = 0;
	ytemp = 0;
}

int UI::getToolBarHeight() {
	return ToolBarHeight;
}
int UI::Height()  {
	return height;
}
int UI::getWidth()  {
	return width;
}
int UI::getStatusBarHeight()  {
	return StatusBarHeight;
}
int UI::getCompWidth() 
{
	return COMP_WIDTH;
}

int UI::getCompHeight() 
{
	return COMP_HEIGHT;
}

//======================================================================================//
//								Input Functions 										//
//======================================================================================//

void UI::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}
/*Getstring function is adjusted so that it takes a prompt message and it also initializes the string which
* the user will enter, this can be useful when editing a component label such that the user can overwrite the old label
*/
string UI::GetSrting(string msg,string value)
{
	//Reads a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" is also supported
	//User should see what he is typing at the status bar

	UI::PrintMsg(msg);
	string userInput;
	char Key;
	userInput = value;
	while(1)
	{
		pWind->WaitKeyPress(Key);

		switch(Key)
		{
		case 27: //ESCAPE key is pressed
			PrintMsg("");
			return ""; //returns nothing as user has cancelled the input
		
		case 13:		//ENTER key is pressed
			return userInput;
		
		case 8:		//BackSpace is pressed
			if(userInput.size() > 0)
				userInput.resize(userInput.size() -1 );
			break;
		
		default:
			userInput+= Key;
		};
		
		PrintMsg(userInput);
	}

}

//This function reads the position where the user clicks to determine the desired action
ActionType UI::GetUserAction() 
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RES:	return ADD_RESISTOR;
			case ITM_BULB:	return ADD_BULB;
			case ITM_BUZZER:return ADD_BUZZER;
		//	case ITM_LABEL: return ADD_Label;
			case ITM_FUZE:return ADD_FUZE;
			case ITM_SWITCH:return ADD_SWITCH;
			case ITM_BATTERY:return ADD_BATTERY;
			case ITM_GROUND:return ADD_GROUND;
			case ITM_CONNECTION: return ADD_CONNECTION;
			case ITM_DROP: return DROP_DOWN;
		/*	case ITM_EDIT:return EDIT;
			case ITM_DELETE:return DEL;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;*/
			case ITM_SIMU: return SIM_MODE;
			case ITM_EXIT:	return EXIT;	
			
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
	
		//[2] User clicks on the drawing area
		if (dropdown == true) {
			if (x >= ITM_DROP * ToolItemWidth && x < ((ITM_DROP + 1) * ToolItemWidth) &&
				y >= ToolBarHeight && y <= (ITM_DRP_CNT + 1) * ToolBarHeight) {

				int ClickedItem = (y / ToolBarHeight) - 1;

				switch (ClickedItem) {
				case ITM_REAL: return SWITCH_IMG;
				case ITM_LABEL: return ADD_Label;
				case ITM_EDIT:return EDIT;
				case ITM_DELETE:return DEL;
				case ITM_SAVE: return SAVE;
				case ITM_LOAD: return LOAD;
				}
			}
		}
			if (y >= ToolBarHeight && y < height - StatusBarHeight)
			{
				xtemp = x;
				ytemp = y;

				return SELECT;	//user wants to select/unselect a component
			}
		
		
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else {

		if (y >= 0 && y < ToolBarHeight)
		{
			int ClickedItemOrder = (x / ToolItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_EXIT2: return EXIT;
			case ITM_AMMETER: return AMMETER;
			case ITM_VOLTMETER: return VOLTMETER;
			case ITM_DESIGN: return DESIGNN;
			case ITM_CIRC_SIM: return SIMU;
			}
		}
	}
}
int UI::getXtemp() {
	return xtemp;
}
int UI::getYtemp() {
	return ytemp;
}



//======================================================================================//
//								Output Functions										//
//======================================================================================//

//////////////////////////////////////////////////////////////////////////////////
void UI::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, height-StatusBarHeight, width, height-StatusBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////
void UI::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(MsgColor); 
	pWind->DrawString(MsgX, height - MsgY, msg);
}
void UI::labelMsg(string msg,int x,int y)
{
	ClearStatusBar();
	
	int MsgX = x;
	int MsgY = y;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(MsgColor);
	pWind->DrawString(MsgX,MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(MsgX, height - MsgY, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void UI::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);
	
}
void UI::ClearToolBarArea() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, width, ToolBarHeight);

}
void UI::SwitchImageType() {
	if (img == Real)
		img = Schem;
	else
		img = Real;
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void UI::CreateDropDownMenu() {
	if (dropdown == true) {
		string DropMenuImages[ITM_DRP_CNT];
		DropMenuImages[ITM_EDIT] = "images\\Menu\\Menu_Edit.jpg";
		DropMenuImages[ITM_LABEL] = "images\\Menu\\Menu_Label.jpg";
		DropMenuImages[ITM_DELETE] = "images\\Menu\\Menu_Delete.jpg";
		DropMenuImages[ITM_SAVE] = "images\\Menu\\Menu_Save.jpg";
		DropMenuImages[ITM_LOAD] = "images\\Menu\\Menu_Load.jpg";
		DropMenuImages[ITM_REAL] = "images\\Menu\\Menu_Real.jpg";

		for (int i = 0; i < ITM_DRP_CNT; i++)
		{
			pWind->DrawImage(DropMenuImages[i], ITM_DROP * ToolItemWidth, (i + 1) * ToolBarHeight, ToolItemWidth, ToolBarHeight);
		}
		pWind->SetPen(RED, 3);
		pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
	}
}
void UI::CreateDesignToolBar() 
{
	AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_RES] = "images\\Menu\\Menu_Resistor.jpg";
	MenuItemImages[ITM_BULB] = "images\\Menu\\Menu_Bulb.jpg";
	MenuItemImages[ITM_BUZZER] = "images\\Menu\\Menu_Buzzer.jpg";
	MenuItemImages[ITM_BATTERY] = "images\\Menu\\Menu_Battery.jpg";
	MenuItemImages[ITM_FUZE] = "images\\Menu\\Menu_Fuze.jpg";
	MenuItemImages[ITM_GROUND] = "images\\Menu\\Menu_Ground.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Menu\\Menu_Switch.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";
	MenuItemImages[ITM_CONNECTION] = "images\\Menu\\Menu_Wire.jpg";
	MenuItemImages[ITM_SIMU] = "images\\Menu\\Menu_Play.jpg";
	MenuItemImages[ITM_DROP] = "images\\Menu\\Menu_DropDown.jpg";
	

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*ToolItemWidth,0,ToolItemWidth, ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);	
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void UI::CreateSimulationToolBar()
{
		AppMode = SIMULATION;	//Simulation Mode

		string SimulationMenuImages[ITM_SIM_CNT];
		SimulationMenuImages[ITM_CIRC_SIM] = "images\\Simulation Menu\\SMenu_Simulate.jpg";
		SimulationMenuImages[ITM_AMMETER] = "images\\Simulation Menu\\SMenu_Ammeter.jpg";
		SimulationMenuImages[ITM_VOLTMETER] = "images\\Simulation Menu\\SMenu_Voltmeter.jpg";
		SimulationMenuImages[ITM_DESIGN] = "images\\Simulation Menu\\SMenu_Design.jpg";
		SimulationMenuImages[ITM_EXIT2] = "images\\Simulation Menu\\SMenu_Exit.jpg";

		for (int i = 0; i < ITM_SIM_CNT; i++)
		{
			pWind->DrawImage(SimulationMenuImages[i], i * ToolItemWidth, 0, ToolItemWidth, ToolBarHeight);
		}
		pWind->SetPen(RED, 3);
		pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
	
}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void UI::DrawResistor(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	
	string ResImage;
	if (img == Schem) {
		if (selected)
			ResImage = "Images\\Comp\\Resistor_HI.jpg";	//use image of highlighted resistor
		else
			ResImage = "Images\\Comp\\Resistor.jpg";	//use image of the normal resistor
	}
	else {
		if (selected)
			ResImage = "Images\\Comp\\Real_Resistor_HI.jpg";	//use image of highlighted resistor
		else
			ResImage = "Images\\Comp\\Real_Resistor.jpg";	//use image of the normal resistor
	}
	//Draw Resistor at Gfx_Info (1st corner)
	
		pWind->DrawImage(ResImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
	
}
void UI::DrawBattery(const GraphicsInfo& r_GfxInfo, bool selected) const
{

	string BatImage;
	if (img == Schem) {
		if (selected)
			BatImage = "Images\\Comp\\Battery_HI.jpg";
		else
			BatImage = "Images\\Comp\\Battery.jpg";	
	}
	else {
		if (selected)
			BatImage = "Images\\Comp\\Real_Battery_HI.jpg";	
		else
			BatImage = "Images\\Comp\\Real_Battery.jpg";	
	}

	pWind->DrawImage(BatImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);

}
void UI::DrawGround(const GraphicsInfo& r_GfxInfo, bool selected) const
{

	string GrdImage;
	if (selected)
		GrdImage = "Images\\Comp\\Ground_HI.jpg";	
	else
		GrdImage = "Images\\Comp\\Ground.jpg";	

	

	pWind->DrawImage(GrdImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);

}
void UI::DrawOpenSwitch(const GraphicsInfo& r_GfxInfo, bool selected) const
{

	string SwtImage;
	if (img == Schem) {
		if (selected)
			SwtImage = "Images\\Comp\\OpenSwitch_HI.jpg";	
		else
			SwtImage = "Images\\Comp\\OpenSwitch.jpg";
	}
	else {
		if (selected)
			SwtImage = "Images\\Comp\\Real_OpenSwitch_HI.jpg";
		else
			SwtImage = "Images\\Comp\\Real_OpenSwitch.jpg";	
	}


	pWind->DrawImage(SwtImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);

}
void UI::DrawClosedSwitch(const GraphicsInfo& r_GfxInfo, bool selected) const
{

	string SwtImage;
	if (img == Schem) {
		if (selected)
			SwtImage = "Images\\Comp\\ClosedSwitch_HI.jpg";
		else
			SwtImage = "Images\\Comp\\ClosedSwitch.jpg";
	}
	else {
		if (selected)
			SwtImage = "Images\\Comp\\Real_ClosedSwitch_HI.jpg";
		else
			SwtImage = "Images\\Comp\\Real_ClosedSwitch.jpg";
	}
	

	pWind->DrawImage(SwtImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);

}
void UI::DrawFuze(const GraphicsInfo& r_GfxInfo, bool selected) const
{

	string FuzImage;
	if (img == Schem) {
		if (selected)
			FuzImage = "Images\\Comp\\Fuze_HI.jpg";
		else
			FuzImage = "Images\\Comp\\Fuze.jpg";
	}
	else {
		if (selected)
			FuzImage = "Images\\Comp\\Real_Fuze_HI.jpg";
		else
			FuzImage = "Images\\Comp\\Real_Fuze.jpg";
	}


	pWind->DrawImage(FuzImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);

}
void UI::DrawBulb(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string BulbImage;
	if (img == Schem) {
		if (selected)
			BulbImage = "Images\\Comp\\Bulb_HI.jpg";	
		else
			BulbImage = "Images\\Comp\\Bulb.jpg";
	}
	else {
		if (selected)
			BulbImage = "Images\\Comp\\Real_Bulb_HI.jpg";
		else
			BulbImage = "Images\\Comp\\Real_Bulb.jpg";	
	}

	pWind->DrawImage(BulbImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}
void UI::DrawBuzzer(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string BuzzerImage;
	if (img == Schem) {
		
		if (selected)
			BuzzerImage = "Images\\Comp\\Buzzer_HI.jpg";
		else
			BuzzerImage = "Images\\Comp\\Buzzer.jpg";	

		
		
	}
	else {
		if (selected)
			BuzzerImage = "Images\\Comp\\Real_Buzzer_HI.jpg";	
		else
			BuzzerImage = "Images\\Comp\\Real_Buzzer.jpg";	

	}
	pWind->DrawImage(BuzzerImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}
//TODO: Add similar functions to draw all other components


void UI::DrawConnection(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	//TODO: Add code to draw connection
	string WireImage;
	if (selected)
		pWind->SetPen(RED, PEN_THICKNESS);
	else
		pWind->SetPen(BLACK, PEN_THICKNESS);

	
	//pWind->DrawImage(WireImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, length, COMP_HEIGHT);
	
	pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);
}


UI::~UI()
{
	delete pWind;

}