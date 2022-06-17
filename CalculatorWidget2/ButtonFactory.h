#pragma once
#include "wx/wx.h"
#include "cMain.h"

class ButtonFactory
{
private:
	cMain* Parent = nullptr;
	int Rows = 4, Columns = 5; 
	wxSize Size = wxSize(50, 50); 
	wxPoint StartPosition = wxPoint(10, 40); 
	wxPoint CurrentPosition = wxPoint(0, 0);

	void NextPosition();
	wxPoint ToUIPosition();

public:
	void SetParent(cMain* parent); 
	void SetSize(wxSize size); 
	void SetGrid(int rows, int columns);
	void SetStartPosition(wxPoint pos);
	wxButton* CreateButton(wxString str);
};

