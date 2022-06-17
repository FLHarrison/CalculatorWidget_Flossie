#include "ButtonFactory.h"

void ButtonFactory::NextPosition()
{
	int x = (CurrentPosition.x + 1) % Columns;
	int y = CurrentPosition.y;
	if (x == 0)
	{
		y += 1;
	}
	CurrentPosition = wxPoint(x, y);
}

wxPoint ButtonFactory::ToUIPosition()
{
	int x = CurrentPosition.x * (Size.GetWidth() + 10) + StartPosition.x; 
	int y = CurrentPosition.y * (Size.GetHeight() + 10) + StartPosition.y; 
	return wxPoint(x, y); 
}

void ButtonFactory::SetParent(cMain* parent)
{
	Parent = parent;
}

void ButtonFactory::SetSize(wxSize size)
{
	Size = size;
}

void ButtonFactory::SetGrid(int rows, int columns)
{
	Rows = rows;
	Columns = columns;
	CurrentPosition = wxPoint(0, 0);
}

void ButtonFactory::SetStartPosition(wxPoint pos)
{
	StartPosition = pos;
	CurrentPosition = wxPoint(0, 0);
}

wxButton* ButtonFactory::CreateButton(wxString str)
{
	wxButton* btn = new wxButton(Parent, wxID_ANY, str);
	btn->SetSize(Size);
	btn->SetPosition(ToUIPosition());
	NextPosition();
	return btn;
}
