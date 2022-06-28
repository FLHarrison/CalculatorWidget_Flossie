#pragma once
#pragma warning(disable : 4996)

#include <vector>
#include "ICommand.h"

class MathCommand : public ICommand {

private:
    char Operator;
    int (*Func)(int, int);

    static std::vector<MathCommand*> Commands;

public:
    MathCommand(char op, int (*func)(int, int));

    char GetOperator();
    void SetOperator(char op);

    static MathCommand* GetCommand();

    wxString Execute();

};