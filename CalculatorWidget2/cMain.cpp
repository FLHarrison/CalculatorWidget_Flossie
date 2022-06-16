#include "wx/wx.h"
#include "cMain.h"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Buttons", wxPoint(200, 200), wxSize(325, 325))
{

	btn1 = new wxButton(this, 100, "1", wxPoint(10, 40),   wxSize(50, 50));
	btn4 = new wxButton(this, 100, "4", wxPoint(10, 100),   wxSize(50, 50));
	btn7 = new wxButton(this, 100, "7", wxPoint(10, 160),  wxSize(50, 50));
	btn2 = new wxButton(this, 100, "2", wxPoint(70, 40),   wxSize(50, 50));
	btn5 = new wxButton(this, 100, "5", wxPoint(70, 100),   wxSize(50, 50));
	btn8 = new wxButton(this, 100, "8", wxPoint(70, 160),  wxSize(50, 50));
	btn3 = new wxButton(this, 100, "3", wxPoint(130, 40),  wxSize(50, 50));
	btn6 = new wxButton(this, 100, "6", wxPoint(130, 100),  wxSize(50, 50));
	btn9 = new wxButton(this, 100, "9", wxPoint(130, 160), wxSize(50, 50));
	btn0 = new wxButton(this, 100, "0", wxPoint(10, 220),  wxSize(50, 50));

	btnEql = new wxButton(this, 100, "=", wxPoint(70, 220), wxSize(50, 50));
	btnSub = new wxButton(this, 100, "-", wxPoint(250, 100),   wxSize(50, 50));
	btnAdd = new wxButton(this, 100, "+", wxPoint(190, 100), wxSize(50, 50));
	btnDiv = new wxButton(this, 100, "/", wxPoint(250, 40),  wxSize(50, 50));
	btnMpy = new wxButton(this, 100, "*", wxPoint(190, 40), wxSize(50, 50));
	btnMod = new wxButton(this, 100, "%", wxPoint(250, 160),   wxSize(50, 50));
	btnClr = new wxButton(this, 100, "C", wxPoint(190, 160),   wxSize(50, 50));

	btnDec = new wxButton(this, 100, "DEC", wxPoint(130, 220), wxSize(50, 50));
	btnHex = new wxButton(this, 100, "HEX", wxPoint(190, 220), wxSize(50, 50));
	btnBin = new wxButton(this, 100, "BIN", wxPoint(250, 220), wxSize(50, 50));

	tbDisplay = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 10), wxSize(290, 20));

}
cMain::~cMain()
{
}

