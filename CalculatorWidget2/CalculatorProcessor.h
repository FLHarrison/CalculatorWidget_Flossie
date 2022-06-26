#pragma once
#include "wx/wx.h"
class CalculatorProcessor
{
private: 
	static CalculatorProcessor* Instance;

	char Base = 'D';
	char Operator = ' ';
	int SelectedInput = 0;
	wxString Inputs[2] = { "0", "0" };

	CalculatorProcessor();

public:
	static CalculatorProcessor* GetInstance();

	wxString ConvertBase(wxString base10);
	wxString SetBase(char numberBase);
	wxString AppendInput(char input);
	wxString SetOperator(char opr);
	wxString Calculate();

private:
	void Reset();

};

