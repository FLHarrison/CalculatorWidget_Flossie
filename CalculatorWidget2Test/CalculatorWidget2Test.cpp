#pragma once
#include "../CalculatorWidget2/MathCommand.cpp"
#include "../CalculatorWidget2/ICommand.cpp"
#include "../CalculatorWidget2/CalculatorProcessor.h"
#include "../CalculatorWidget2/CalculatorProcessor.cpp"

bool TestInput(wxString input, CalculatorProcessor* _cpu, int selected);

int main()
{
	//Testing: GetInstance
	//   -CalculatorProcessor Constructor
	//   -MathCommand Constroctor
	CalculatorProcessor* _cpu = CalculatorProcessor::GetInstance();
	//In Binary 9 = 1001
	//Testing: ConvertBase and SetBase
	_cpu->SetBase('B');
	wxString result = _cpu->ConvertBase("9");
	if (result != "1001")
	{
		std::cout << "Conversion to Binary Failed! \n";
	}

	//In Hex 12 = C
	//Testing: ConvertBase and SetBase
	_cpu->SetBase('H');
	result = _cpu->ConvertBase("12");
	if (result != "C")
	{
		std::cout << "Conversion to HEX Failed! \n";
	}

	//Testing: ConvertBase and SetBase
	_cpu->SetBase('D');
	result = _cpu->ConvertBase("9");
	if (result != "9")
	{
		std::cout << "Conversion to Decimal Failed! \n";
	}

	if (TestInput("123", _cpu, 0) == false)
	{
		std::cout << "Input 0 Failed! \n";
	}

	_cpu->SetOperator('+');
	if (ICommand::GetCurrentOperator() != '+')
	{
		std::cout << "Operator Change Failed! \n";
	}

	if (TestInput("234", _cpu, 1) == false)
	{
		std::cout << "Input 1 Failed! \n";
	}

	//Testing Addition
	if (MathCommand::GetCommand()->Execute() != "357")
	{
		std::cout << "Addition Failed! \n";
	}

	//Testing Subtraction
	ICommand::SetInput("500", 0);
	ICommand::SetInput("5", 1);
	_cpu->SetOperator('-');
	if (MathCommand::GetCommand()->Execute() != "495")
	{
		std::cout << "Subtraction Failed! \n";
	}

	//Testing Multiplication
	_cpu->SetOperator('*');
	if (MathCommand::GetCommand()->Execute() != "2500")
	{
		std::cout << "Multiplication Failed! \n";
	}

	//Testing Division
	_cpu->SetOperator('/');
	if (MathCommand::GetCommand()->Execute() != "100")
	{
		std::cout << "Divison Failed! \n";
	}

	//Testing Modulos
	_cpu->SetOperator('%');
	if (MathCommand::GetCommand()->Execute() != "0")
	{
		std::cout << "Modulos Failed! \n";
	}
	delete _cpu;
}
/// <summary>
/// Adds all the charaters from the wxString to ICommand's Input
/// Checks that ICommand's Input is the same as Input.
/// </summary>
/// <param name="input">the string to add to ICommand.</param>
/// <param name="_cpu">The CalculatorProcessor to test.</param>
/// <param name="selected">The Input Index.</param>
/// <returns>True, if Input = ICommand Input, Otherwise False.</returns>
bool TestInput(wxString input, CalculatorProcessor* _cpu, int selected)
{
	for (int i = 0; i < input.length(); i++)
	{
		_cpu->AppendInput(input[i]);
	}
	return ICommand::GetInput(selected) == input;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
