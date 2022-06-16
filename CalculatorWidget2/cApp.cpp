#include "cApp.h"

wxIMPLEMENT_APP(cApp); 

cApp::cApp() {}

cApp::~cApp() {}

bool cApp::OnInit()
{
	window = new cMain();
	window->Show(); 
	return true;
}