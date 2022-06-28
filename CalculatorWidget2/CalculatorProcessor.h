#pragma once
#include "wx/wx.h"
#include "MathCommand.h"

class CalculatorProcessor
{
private: 
	static CalculatorProcessor* Instance;

	int SelectedInput = 0;
	

	CalculatorProcessor();

public:
	~CalculatorProcessor();
	static CalculatorProcessor* GetInstance();

	wxString ConvertBase(wxString base10);
	wxString SetBase(char numberBase);
	wxString AppendInput(char input);
	wxString SetOperator(char opr);
	wxString Calculate();

private:
	void Reset();

};

