//start point of program

//requirements za development:
//	sudo apt-get install libgpgme-dev
//	sudo apt-get install wxwidgets

#include "../include/tesky.h"

IMPLEMENT_APP(TeskyApp)

bool TeskyApp::OnInit()
{
	wxFrame *frame = new wxFrame((wxFrame*) NULL, -1, _T("Tesky v0.1 :)"));
	frame->CreateStatusBar();
	frame->SetStatusText(_T("GnuPG Mirko's implementation"));
	frame->Show(true);
	SetTopWindow(frame);
	return true;
}
