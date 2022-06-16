#include "wx/wx.h"
#include "cMain.h"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Buttons", wxPoint(200, 200), wxSize(325, 325))
{

	btn1 = new wxButton(this, 100, "1", wxPoint(10, 40),   wxSize(50, 50));
	btn1->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btn1, evt); });

	btn4 = new wxButton(this, 100, "4", wxPoint(10, 100),   wxSize(50, 50));
	btn4->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btn4, evt); });

	btn7 = new wxButton(this, 100, "7", wxPoint(10, 160),  wxSize(50, 50));
	btn7->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btn7, evt); });

	btn2 = new wxButton(this, 100, "2", wxPoint(70, 40),   wxSize(50, 50));
	btn2->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btn2, evt); });

	btn5 = new wxButton(this, 100, "5", wxPoint(70, 100),   wxSize(50, 50));
	btn5->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btn5, evt); });

	btn8 = new wxButton(this, 100, "8", wxPoint(70, 160),  wxSize(50, 50));
	btn8->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btn8, evt); });

	btn3 = new wxButton(this, 100, "3", wxPoint(130, 40),  wxSize(50, 50));
	btn3->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btn3, evt); });

	btn6 = new wxButton(this, 100, "6", wxPoint(130, 100),  wxSize(50, 50));
	btn6->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btn6, evt); });

	btn9 = new wxButton(this, 100, "9", wxPoint(130, 160), wxSize(50, 50));
	btn9->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btn9, evt); });

	btn0 = new wxButton(this, 100, "0", wxPoint(10, 220),  wxSize(50, 50));
	btn0->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btn0, evt); });

	btnEql = new wxButton(this, 100, "=", wxPoint(70, 220), wxSize(50, 50));
	btnEql->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btnEql, evt); });

	btnSub = new wxButton(this, 100, "-", wxPoint(250, 100),   wxSize(50, 50));
	btnSub->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btnSub, evt); });

	btnAdd = new wxButton(this, 100, "+", wxPoint(190, 100), wxSize(50, 50));
	btnAdd->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btnAdd, evt); });

	btnDiv = new wxButton(this, 100, "/", wxPoint(250, 40),  wxSize(50, 50));
	btnDiv->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btnDiv, evt); });

	btnMpy = new wxButton(this, 100, "*", wxPoint(190, 40), wxSize(50, 50));
	btnMpy->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btnMpy, evt); });

	btnMod = new wxButton(this, 100, "%", wxPoint(250, 160),   wxSize(50, 50));
	btnMod->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btnMod, evt); });

	btnClr = new wxButton(this, 100, "C", wxPoint(190, 160),   wxSize(50, 50));
	btnClr->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btnClr, evt); });

	btnDec = new wxButton(this, 100, "DEC", wxPoint(130, 220), wxSize(50, 50));
	btnDec->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btnDec, evt); });

	btnHex = new wxButton(this, 100, "HEX", wxPoint(190, 220), wxSize(50, 50));
	btnHex->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btnHex, evt); });

	btnBin = new wxButton(this, 100, "BIN", wxPoint(250, 220), wxSize(50, 50));
	btnBin->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btnBin, evt); });

	tbDisplay = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 10), wxSize(290, 20));


}
cMain::~cMain()
{
}

void cMain::ButtonClicked(wxButton* btn, wxCommandEvent evt)
{
	wxString str = tbDisplay->GetLabel();
	str += btn->GetLabel();
	tbDisplay->SetLabel(str);
}



