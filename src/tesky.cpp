//start point of program

//requirements za development:
//	sudo apt-get install libgpgme-dev
//	sudo apt-get install wxwidgets

#include "../include/tesky.h"

//starts the main function and implements passed class
IMPLEMENT_APP(TeskyApp)

//[MAIN:]
bool TeskyApp::OnInit()
{
	//Write mirko to clipboard
	//wxTheClipboard->Open();
	//wxTheClipboard->SetData( new wxTextDataObject("Mirko") );
	//wxTheClipboard->Close();

	//Read from clipboard
	wxTextDataObject data;
	wxTheClipboard->Open();	
	wxTheClipboard->GetData(data);
	wxMessageBox(data.GetText());
	wxTheClipboard->Close();

	TMenu *frame = new TMenu(wxT("Tesky v0.02"));
	frame->Show(true);
	//SetTopWindow(frame);

	//succesfull initialization
	return true;
}

//[Constructor implementations:]
TMenu::TMenu(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	//Set the frame icon
	SetIcon(wxIcon());

	//Create a menu bar
	wxMenu *fileMenu = new wxMenu;
	wxMenu *viewMenu = new wxMenu;
	wxMenu *certMenu = new wxMenu;
	wxMenu *toolMenu = new wxMenu;
	wxMenu *settMenu = new wxMenu;
	wxMenu *wndwMenu = new wxMenu;
	wxMenu *helpMenu = new wxMenu;
	wxMenu *clipMenu = new wxMenu;



//              -File
//                      .NewKeyPair
//                      .Import..
//                      .Export..
//                      .PrintSecretKey
//                      .Decrypt/Verify
//                      .Encrypt/Sign
//                      .CreateCheksumFiles
//                      .VerifyChecksumFiles
//                      .Close
//                      .Quit
//              -View
//                      .Certificates
//                      .Notepad
//                      .Smartcards
//              -Certificates
//              -Tools
//                      .Clipboard
//                              ->Import
//                              ->Encrypt
//                              ->Decrypt
//              -Settings
//              -Window
//              -Help
//                      .About Tesky
//                      .About Mirko

	//Append items to menu's
	toolMenu->Append(ID_Hello, wxT("ClImport"), wxT("Import Certificate from Clipboard"));
	toolMenu->Append(wxID_ANY, wxT("ClEncrypt"), wxT("Encrypt data in Clipboard"));
	toolMenu->Append(wxID_ANY, wxT("ClDecrypt"), wxT("Decrypt data in Clipboard"));
	helpMenu->Append(wxID_ABOUT, wxT("&About...\tF1"), wxT("Show about dialog"));
	wndwMenu->Append(wxID_ANY, wxT("&????...\tF1"), wxT("Show about dialog"));
	settMenu->Append(wxID_ANY, wxT("&????...\tF1"), wxT("Show about dialog"));
	certMenu->Append(wxID_ANY, wxT("&????...\tF1"), wxT("Show about dialog"));
	viewMenu->Append(wxID_ANY, wxT("Certificates"), wxT("Open Certificates tab"));
	viewMenu->Append(wxID_ANY, wxT("Notepad"), wxT("Open Notepad tab"));
	viewMenu->Append(wxID_ANY, wxT("Smartcards"), wxT("Open Smartcards tab"));
	fileMenu->Append(wxID_ANY, wxT("NewKeyPair\tCtrl-N"), wxT("Create New Key Pair"));
	fileMenu->Append(wxID_ANY, wxT("Import..\tCtrl-I"), wxT("Import Public/Private Key"));
	fileMenu->Append(wxID_ANY, wxT("Export..\tCtrl-E"), wxT("Export Public/Private Key"));
	fileMenu->Append(wxID_ANY, wxT("PrintSecretKey\tCtrl-P"), wxT("Print out key"));
	fileMenu->Append(wxID_ANY, wxT("Encrypt/Sign"), wxT("Encrypt Message or File"));
	fileMenu->Append(wxID_ANY, wxT("Decrypt/Verify"), wxT("Decrypt Message or File"));
	fileMenu->Append(wxID_ANY, wxT("Create Cheksum Files"), wxT("Create Cheksum Files"));
	fileMenu->Append(wxID_ANY, wxT("Verify Cheksum Files"), wxT("Verify Cheksum Files"));
	fileMenu->Append(wxID_ANY, wxT("Close\tCtrl-W"), wxT("Close/Stay in Background"));
	fileMenu->Append(wxID_EXIT, wxT("E&xit\tCtrl-Q"), wxT("Quit this program"));


	//append freshly created menu to the menu bar
	wxMenuBar *menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, wxT("&File"));
	menuBar->Append(viewMenu, wxT("&View"));
	menuBar->Append(certMenu, wxT("&Certificates"));
	menuBar->Append(toolMenu, wxT("&Tools"));
	menuBar->Append(settMenu, wxT("&Settings"));
	menuBar->Append(wndwMenu, wxT("&Window"));
	menuBar->Append(helpMenu, wxT("&Help"));

	//Attach Menu Bar to the frame
	SetMenuBar(menuBar);

	//Create a status bar
	CreateStatusBar(2);
	SetStatusText(wxT("GnuPG Mirko's Implementation"));

	//Bind(wxEVT_MENU, &TMenu::ClImport, this, ID_Hello);
}

//[Method implementations:]
void TMenu::OnAboutTesky(wxCommandEvent& event)
{
	wxString msg;
	msg.Printf(wxT("Hello and welcome to Tesky v0.02\n\t-written by Mirko"));

	wxMessageBox(msg, wxT("About Tesky"), wxOK | wxICON_INFORMATION, this);
}

void TMenu::OnQuit(wxCommandEvent& event)
{
	Close();
}

void TMenu::ClImport(wxCommandEvent& event)
{
	wxString msg;
	msg.Printf(wxT("CLIMPORT :)"));
	wxMessageBox(msg, wxT("About Tesky"), wxOK | wxICON_INFORMATION, this);
}
