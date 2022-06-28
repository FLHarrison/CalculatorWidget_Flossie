#include "MathCommand.h"

std::vector<MathCommand*> MathCommand::Commands;

MathCommand::MathCommand(char op, int(*func)(int, int))
{
    Func = func;
    Operator = op;
    Commands.push_back(this);
}

char MathCommand::GetOperator()
{
    return Operator;
}

wxString MathCommand::Execute() {
    if (GetInput(0) == "" || GetInput(1) == "") {
        return "0";
    }
    int* left = new int(0);
    int* right = new int(0);
    GetInput(0).ToInt(left);
    GetInput(1).ToInt(right);
    int answer = Func(*left, *right);
    wxString str = wxString::FromDouble(answer);
    delete left; delete right;
    return str;
}

void MathCommand::SetOperator(char op)
{
    Operator = op;
}

MathCommand* MathCommand::GetCommand()
{
    for (int i = 0; i < Commands.size(); i++) {
        if (Commands[i]->Operator == GetCurrentOperator()) {
            return Commands[i];
        }
    }
    return nullptr;
}