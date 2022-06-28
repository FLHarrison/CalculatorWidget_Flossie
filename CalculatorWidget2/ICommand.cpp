#include "ICommand.h"

char ICommand::Base = 'D';
char ICommand::CurrentOperator = ' ';
wxString ICommand::Inputs[2] = { "", "" };


void ICommand::SetBase(char _base)
{
	Base = _base;
}

void ICommand::SetCurrentOperator(char op)
{
	CurrentOperator = op;
}

void ICommand::SetInput(wxString input, int select)
{
	if (select > -1 && select < 2)
	{
		Inputs[select] = input;
	}
}

char ICommand::GetBase()
{
	return Base;
}

char ICommand::GetCurrentOperator()
{
	return CurrentOperator;
}

wxString ICommand::GetInput(int index)
{
	if (index < 2 && index > -1)
	{
		return Inputs[index];
	}
	return "";
}
