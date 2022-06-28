#pragma once
#include "wx/wx.h"

class ICommand
{
private:
    static char Base;
    static char CurrentOperator;
    static wxString Inputs[2];

public:
    virtual wxString Execute() = 0;

    static void SetBase(char _base);
    static void SetCurrentOperator(char op);
    static void SetInput(wxString input, int select);

    static char GetBase();
    static char GetCurrentOperator();
    static wxString GetInput(int index);

};

