#pragma once

#include "wx/wx.h"

class cMain : public wxFrame
{
private:

	wxButton* btn1 = nullptr;
	wxButton* btn2 = nullptr;
	wxButton* btn3 = nullptr;
	wxButton* btn4 = nullptr;
	wxButton* btn5 = nullptr;
	wxButton* btn6 = nullptr;
	wxButton* btn7 = nullptr;
	wxButton* btn8 = nullptr;
	wxButton* btn9 = nullptr;
	wxButton* btn0 = nullptr;
        
	wxButton* btnEql = nullptr;         
	wxButton* btnSub = nullptr;         
	wxButton* btnAdd = nullptr;          
	wxButton* btnDiv = nullptr;          
	wxButton* btnMpy = nullptr;       
	wxButton* btnMod = nullptr;          
	wxButton* btnClr = nullptr;   

	wxButton* btnDec = nullptr;
	wxButton* btnHex = nullptr;
	wxButton* btnBin = nullptr;

	wxTextCtrl* tbDisplay = nullptr;
	 
public: 
	cMain();
	~cMain(); 

	void ButtonClicked(wxButton* btn, wxCommandEvent evt);
};

