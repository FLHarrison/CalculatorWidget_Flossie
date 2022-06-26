#include "wx/wx.h"
#include "cMain.h"
#include "ButtonFactory.h"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Buttons", wxPoint(200, 200), wxSize(325, 325))
{
	ButtonFactory bf;
	bf.SetParent(this);
	btn1 = bf.CreateButton("1");
	btn2 = bf.CreateButton("2");
	btn3 = bf.CreateButton("3");
	btnMpy = bf.CreateButton("*");
	btnDiv = bf.CreateButton("/");

	btn4 = bf.CreateButton("4");
	btn5 = bf.CreateButton("5");
	btn6 = bf.CreateButton("6");
	btnAdd = bf.CreateButton("+");
	btnSub = bf.CreateButton("-");

	btn7 = bf.CreateButton("7");
	btn8 = bf.CreateButton("8");
	btn9 = bf.CreateButton("9");
	btnClr = bf.CreateButton("C");
	btnMod = bf.CreateButton("%");

	btn0 = bf.CreateButton("0");
	btnEql = bf.CreateButton("=");
	btnDec = bf.CreateButton("DEC");
	btnHex = bf.CreateButton("HEX");
	btnBin = bf.CreateButton("BIN");


	//btn1 = new wxButton(this, 100, "1", wxPoint(10, 40),   wxSize(50, 50));
	btn1->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::InputClicked, this);

	//btn4 = new wxButton(this, 100, "4", wxPoint(10, 100),   wxSize(50, 50));
	btn4->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::InputClicked,this);

	//btn7 = new wxButton(this, 100, "7", wxPoint(10, 160),  wxSize(50, 50));
	btn7->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::InputClicked, this);

	//btn2 = new wxButton(this, 100, "2", wxPoint(70, 40),   wxSize(50, 50));
	btn2->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::InputClicked, this);

	//btn5 = new wxButton(this, 100, "5", wxPoint(70, 100),   wxSize(50, 50));
	btn5->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::InputClicked, this);

	//btn8 = new wxButton(this, 100, "8", wxPoint(70, 160),  wxSize(50, 50));
	btn8->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::InputClicked, this);

	//btn3 = new wxButton(this, 100, "3", wxPoint(130, 40),  wxSize(50, 50));
	btn3->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::InputClicked, this);

	//btn6 = new wxButton(this, 100, "6", wxPoint(130, 100),  wxSize(50, 50));
	btn6->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::InputClicked, this);

	//btn9 = new wxButton(this, 100, "9", wxPoint(130, 160), wxSize(50, 50));
	btn9->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::InputClicked, this);

	//btn0 = new wxButton(this, 100, "0", wxPoint(10, 220),  wxSize(50, 50));
	btn0->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::InputClicked, this);

	//btnEql = new wxButton(this, 100, "=", wxPoint(70, 220), wxSize(50, 50));
	btnEql->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::EqualClicked, this);

	//btnSub = new wxButton(this, 100, "-", wxPoint(250, 100),   wxSize(50, 50));
	btnSub->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OperatorClicked, this);

	//btnAdd = new wxButton(this, 100, "+", wxPoint(190, 100), wxSize(50, 50));
	btnAdd->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OperatorClicked, this);

	//btnDiv = new wxButton(this, 100, "/", wxPoint(250, 40),  wxSize(50, 50));
	btnDiv->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OperatorClicked, this);

	//btnMpy = new wxButton(this, 100, "*", wxPoint(190, 40), wxSize(50, 50));
	btnMpy->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OperatorClicked, this);

	//btnMod = new wxButton(this, 100, "%", wxPoint(250, 160),   wxSize(50, 50));
	btnMod->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OperatorClicked, this);

	//btnClr = new wxButton(this, 100, "C", wxPoint(190, 160),   wxSize(50, 50));
	//btnClr->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent evt) {ButtonClicked(btnClr, evt); });

	//btnDec = new wxButton(this, 100, "DEC", wxPoint(130, 220), wxSize(50, 50));
	btnDec->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::BaseClicked, this);

	//btnHex = new wxButton(this, 100, "HEX", wxPoint(190, 220), wxSize(50, 50));
	btnHex->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::BaseClicked, this);

	//btnBin = new wxButton(this, 100, "BIN", wxPoint(250, 220), wxSize(50, 50));
	btnBin->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::BaseClicked, this);

	tbDisplay = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 10), wxSize(290, 20));


}
cMain::~cMain()
{
	CalculatorProcessor* clr = CalculatorProcessor::GetInstance();
	delete clr;
}

void cMain::ButtonClicked(wxButton* btn, wxCommandEvent evt)
{
	wxString str = tbDisplay->GetLabel();
	str += btn->GetLabel();
	tbDisplay->SetLabel(str);
}

void cMain::OperatorClicked(wxCommandEvent& evt)
{
	wxButton* btn = (wxButton*) evt.GetEventObject();
	CalculatorProcessor* clr = CalculatorProcessor::GetInstance();
	wxString str = clr->SetOperator(btn->GetLabel()[0]);
	tbDisplay->SetLabel(str);
}

void cMain::InputClicked(wxCommandEvent& evt)
{
	wxButton* btn = (wxButton*)evt.GetEventObject();
	CalculatorProcessor* clr = CalculatorProcessor::GetInstance();
	wxString str = clr->AppendInput(btn->GetLabel()[0]);
	tbDisplay->SetLabel(str);
}

void cMain::BaseClicked(wxCommandEvent& evt)
{
	wxButton* btn = (wxButton*)evt.GetEventObject();
	CalculatorProcessor* clr = CalculatorProcessor::GetInstance();
	wxString str = clr->SetBase(btn->GetLabel()[0]);
	tbDisplay->SetLabel(str);
}

void cMain::EqualClicked(wxCommandEvent& evt)
{
	CalculatorProcessor* clr = CalculatorProcessor::GetInstance();
	wxString str = clr->Calculate();
	tbDisplay->SetLabel(str);
}



