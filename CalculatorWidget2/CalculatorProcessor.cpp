#include "CalculatorProcessor.h"

CalculatorProcessor* CalculatorProcessor::Instance = nullptr;

CalculatorProcessor::CalculatorProcessor()
{
	new MathCommand('+', [](int a, int b) { return a + b; });
	new MathCommand('-', [](int a, int b) { return a - b; });
	new MathCommand('*', [](int a, int b) { return a * b; });
	new MathCommand('/', [](int a, int b) { return a / b; });
	new MathCommand('%', [](int a, int b) { return a % b; });
}

CalculatorProcessor::~CalculatorProcessor()
{
	ICommand::SetCurrentOperator('+'); delete MathCommand::GetCommand();
	ICommand::SetCurrentOperator('-'); delete MathCommand::GetCommand();
	ICommand::SetCurrentOperator('*'); delete MathCommand::GetCommand();
	ICommand::SetCurrentOperator('/'); delete MathCommand::GetCommand();
	ICommand::SetCurrentOperator('%'); delete MathCommand::GetCommand();
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
	if (ICommand::GetBase() == 'D')
	{
		return base10;
	}
	int* input = new int(0);
	base10.ToInt(input);
	int divisor = 2;
	int remaindor = 0;
	wxString result = "";
	if (ICommand::GetBase() == 'H')
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
	delete input;
	return result;
}

wxString CalculatorProcessor::SetBase(char numberBase)
{
	ICommand::SetBase(numberBase);
	wxString equation = ConvertBase(ICommand::GetInput(0)) + " " + ICommand::GetCurrentOperator() + " " + ConvertBase(ICommand::GetInput(1));
	return equation;
}

wxString CalculatorProcessor::AppendInput(char input)
{
	if (ICommand::GetInput(SelectedInput) == "0") 
	{
		ICommand::SetInput("", SelectedInput);
	}
	ICommand::SetInput(ICommand::GetInput(SelectedInput) + input, SelectedInput);
	wxString equation = ConvertBase(ICommand::GetInput(0)) + " " + ICommand::GetCurrentOperator() + " " + ConvertBase(ICommand::GetInput(1));
	return equation;
}

wxString CalculatorProcessor::SetOperator(char opr)
{
	SelectedInput = 1;
	ICommand::SetCurrentOperator(opr);
	wxString equation = ConvertBase(ICommand::GetInput(0)) + " " + ICommand::GetCurrentOperator() + " " + ConvertBase(ICommand::GetInput(1));
	return equation;
}

wxString CalculatorProcessor::Calculate()
{
	wxString equation = ConvertBase(ICommand::GetInput(0)) + " " + ICommand::GetCurrentOperator() + " " + ConvertBase(ICommand::GetInput(1));
	char op = ICommand::GetCurrentOperator();
	if ((op == '/' || op == '%') && ICommand::GetInput(1) == "0") {
		return equation;
	}
	wxString ans = " = " + ConvertBase(MathCommand::GetCommand()->Execute());
	equation += ans;
	Reset();
	return equation;
}

void CalculatorProcessor::Reset()
{
	SelectedInput = 0;
	ICommand::SetInput("0", 0);
	ICommand::SetInput("0", 1);
}
