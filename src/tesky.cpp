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
TMenu::TMenu(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxPoint(30, 30), wxSize(640, 480))
{
	//Set the frame icon
	SetIcon(wxIcon());

	//Create a menu bar
	wxMenuBar *menuBar = new wxMenuBar();

	//Create menu's
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
	toolMenu->Append(ID_ClImport, wxT("ClImport"), wxT("Import Certificate from Clipboard"));
	toolMenu->Append(ID_ClEncrypt, wxT("ClEncrypt"), wxT("Encrypt data in Clipboard"));
	toolMenu->Append(ID_ClDecrypt, wxT("ClDecrypt"), wxT("Decrypt data in Clipboard"));
	helpMenu->Append(wxID_ABOUT, wxT("&About...\tF1"), wxT("Show about dialog"));
	wndwMenu->Append(wxID_ANY, wxT("&????...\tF1"), wxT("Show about dialog"));
	settMenu->Append(wxID_ANY, wxT("&????...\tF1"), wxT("Show about dialog"));
	certMenu->Append(wxID_ANY, wxT("&????...\tF1"), wxT("Show about dialog"));
	viewMenu->Append(ID_Certificates, wxT("Certificates"), wxT("Open Certificates tab"));
	viewMenu->Append(ID_Notepad, wxT("Notepad"), wxT("Open Notepad tab"));
	viewMenu->Append(ID_Smartcards, wxT("Smartcards"), wxT("Open Smartcards tab"));
	fileMenu->Append(ID_NewKeyPair, wxT("NewKeyPair\tCtrl-N"), wxT("Create New Key Pair"));
	fileMenu->Append(ID_Import, wxT("Import..\tCtrl-I"), wxT("Import Public/Private Key"));
	fileMenu->Append(ID_Export, wxT("Export..\tCtrl-E"), wxT("Export Public/Private Key"));
	fileMenu->Append(ID_PrintSecretKey, wxT("PrintSecretKey\tCtrl-P"), wxT("Print out key"));
	fileMenu->Append(ID_Encrypt, wxT("Encrypt/Sign"), wxT("Encrypt Message or File"));
	fileMenu->Append(ID_Decrypt, wxT("Decrypt/Verify"), wxT("Decrypt Message or File"));
	fileMenu->Append(ID_CreateCheksumFiles, wxT("Create Cheksum Files"), wxT("Create Cheksum Files"));
	fileMenu->Append(ID_VerifyChecksumFiles, wxT("Verify Cheksum Files"), wxT("Verify Cheksum Files"));
	fileMenu->Append(ID_Close, wxT("Close\tCtrl-W"), wxT("Close/Stay in Background"));
	fileMenu->Append(wxID_EXIT, wxT("E&xit\tCtrl-Q"), wxT("Quit this program"));

	//append menu's to the menu bar
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

	//Create Sizers for frame
	//Create Notebook
	//Create tabs for notebook
	//Create Certificates, Notepad and Properties tabs
	//Enable gpgme.h library
	//Add functionalities to buttons
	//Enable Clipboard
	//Enable system tray icon, na desni klik clipboard en/dec
	//Right Click enc/dec files ili ako je txt file samo dec to clipbrd

	//Bind(wxEVT_MENU, &TMenu::ClImport, this, ID_Hello);
}

//[Method implementations:]
void TMenu::OnAboutTesky(wxCommandEvent& event)
{
	wxString msg;
	msg.Printf(wxT("Hello and welcome to Tesky v0.02\n\t-written by Mirko"));

	wxMessageBox(msg, wxT("About Tesky"), wxOK | wxICON_INFORMATION, this);
	//Event.Skip();
}

void TMenu::OnQuit(wxCommandEvent& event)
{
	Close();
	//Event.Skip();
}

void TMenu::ClImport(wxCommandEvent& event)
{
	wxString msg;
	msg.Printf(wxT("CLIMPORT :)"));
	wxMessageBox(msg, wxT("About Tesky"), wxOK | wxICON_INFORMATION, this);
	//Event.Skip();
}
