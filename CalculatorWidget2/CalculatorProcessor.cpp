#include "CalculatorProcessor.h"

CalculatorProcessor* CalculatorProcessor::Instance = nullptr;

CalculatorProcessor::CalculatorProcessor()
{
}

CalculatorProcessor* CalculatorProcessor::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = new CalculatorProcessor();
	}
	return Instance;
}

wxString CalculatorProcessor::ConvertBase(wxString base10)
{
	if (Base == 'D')
	{
		return base10;
	}
	int* input = new int(0);
	base10.ToInt(input);
	int divisor = 2;
	int remaindor = 0;
	wxString result = "";
	if (Base == 'H')
	{
		divisor = 16;
	}
	wxString alpha = "0123456789ABCDEF";
	while (*input > 0)
	{
		remaindor = *input % divisor;
		*input = *input / divisor;
		result = alpha[remaindor] + result;
	}	
	return result;
}

wxString CalculatorProcessor::SetBase(char numberBase)
{
	Base = numberBase;
	wxString equation = ConvertBase(Inputs[0]) + " " + Operator + " " + ConvertBase(Inputs[1]);
	return equation;
}

wxString CalculatorProcessor::AppendInput(char input)
{
	if (Inputs[SelectedInput] == "0") 
	{
		Inputs[SelectedInput] = "";
	}
	Inputs[SelectedInput] += input;
	wxString equation = ConvertBase( Inputs[0]) + " " + Operator + " " + ConvertBase( Inputs[1]);
	return equation;
}

wxString CalculatorProcessor::SetOperator(char opr)
{
	Operator = opr;
	SelectedInput = 1;
	wxString equation = ConvertBase( Inputs[0]) + " " + Operator + " " + ConvertBase( Inputs[1]);
	return equation;
}

wxString CalculatorProcessor::Calculate()
{
	int* input1 = new int(0);
	int* input2 = new int(0);
	int answer = 0;
	Inputs[0].ToInt(input1);
	Inputs[1].ToInt(input2);
	wxString equation = ConvertBase(Inputs[0]) + " " + Operator + " " + ConvertBase(Inputs[1]);
	if ((Operator == '/' || Operator == '%') && Inputs[1] == "0") 
	{
		delete input1; delete input2; return equation;
	}
	switch (Operator)
	{
	case '+': answer = *input1 + *input2; break;
	case '-': answer = *input1 - *input2; break;
	case '*': answer = *input1 * *input2; break;
	case '/': answer = *input1 / *input2; break;
	case '%': answer = *input1 % *input2; break;
	default: delete input1; delete input2;  return equation;
	}
	wxString ans = " = " + ConvertBase(wxString::FromDouble(answer));
	equation += ans;
	Reset();
	delete input1; delete input2;
	return equation;
}

void CalculatorProcessor::Reset()
{
	SelectedInput = 0;
	Inputs[0] = "0";
	Inputs[1] = "0";
}
