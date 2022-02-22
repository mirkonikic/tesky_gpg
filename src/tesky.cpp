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

	//Test TaskBarIcon
	if ( !wxTaskBarIcon::IsAvailable() )
    {
        wxMessageBox
        (
            "There appears to be no system tray support in your current environment. This sample may not behave as expected.",
            "Warning",
            wxOK | wxICON_EXCLAMATION
        );
    }

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

	TMenu *frame = new TMenu(wxT("Tesky v0.03"));
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

//[MENU]
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
	
//[FRAME]
	//MainPanel
	wxPanel* panel = new wxPanel(this, wxID_ANY);
	
	//Notebook
	wxNotebook* notebook = new wxNotebook(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_BOTTOM);

	//setup notebook
	notebook->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	notebook->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );
	
	//Create tabs for notebook
	wxPanel* tab1 = new wxPanel(notebook, wxID_ANY);
    wxPanel* tab2 = new wxPanel(notebook, wxID_ANY);
    wxPanel* tab3 = new wxPanel(notebook, wxID_ANY);
    wxPanel* tab4 = new wxPanel(notebook, wxID_ANY);
	
	//TopSizer -> panel -> PanelSizer -> Notebook -> Tabs
		//Certificates -> BoxSizerV -> 
			//BoxSizerH -> Button -> Button -> FilePicker -> Label -> Search -> Button
			//GridSizer -> 
				//BoxSizerV -> Label -> ListBox
				//BoxSizerV -> Label -> ListBox
		//Notepad -> BoxSizerV ->
			//BoxSizerV -> RichTextCrtl
			//BoxSizerH -> Button -> Button -> Button -> wxChoice
		//Hub -> BoxSizerV ->
			//GridSizer ->
				//Panel -> BoxSizerV -> 
					//BoxSizerV -> StaticText
					//BoxSizerV -> StaticText -> StaticText
					//BoxSizerV -> Button -> Button
				//Panel -> BoxSizerV -> 
					//BoxSizerV -> StaticText
					//BoxSizerV -> StaticText -> TextInput
					//BoxSizerV -> Button -> Button
			//BoxSizerV -> wxCheckListBox
		//Properties -> BoxSizer -> StaticText



	//Create Certificates, Notepad, Hub and Properties tabs
		//Certificates - Import Create Certificates, Select to which you are talking to
		wxBoxSizer* certSizer = new wxBoxSizer(wxVERTICAL);
			wxBoxSizer* certBoxSizer = new wxBoxSizer(wxHORIZONTAL);
				wxButton* newKeyButton = new wxButton(tab1, wxID_ANY, wxT("New key"), wxDefaultPosition, wxDefaultSize, 0);
				wxStaticText* importKeysLabel = new wxStaticText(tab1, wxID_ANY, wxT("Import keys:"), wxDefaultPosition, wxDefaultSize, 0);
				wxFilePickerCtrl* importKeysFile = new wxFilePickerCtrl(tab1, wxID_ANY, wxEmptyString, wxT("Import keys"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE);
				wxStaticText* searchLabel = new wxStaticText(tab1, wxID_ANY, wxT("Search:"), wxDefaultPosition, wxDefaultSize, 0);
				wxSearchCtrl* searchCtrl = new wxSearchCtrl(tab1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
				wxButton* searchOkButton = new wxButton(tab1, wxID_ANY, wxT("OK"), wxDefaultPosition, wxSize( 40,-1 ), 0);
			wxGridSizer* certGridSizer = new wxGridSizer(2, 0, 0, 0);
				wxBoxSizer* certGridB1Sizer = new wxBoxSizer(wxVERTICAL);
					wxStaticText* privKeysLabel = new wxStaticText(tab1, wxID_ANY, wxT("Private keys:"), wxDefaultPosition, wxDefaultSize, 0);
					wxListBox* privKeysList = new wxListBox(tab1, wxID_ANY, wxDefaultPosition, wxSize( 620,200 ), 0, NULL, 0);
				wxBoxSizer* certGridB2Sizer = new wxBoxSizer(wxVERTICAL);
					wxStaticText* pubKeysLabel = new wxStaticText(tab1, wxID_ANY, wxT("Public keys:"), wxDefaultPosition, wxDefaultSize, 0);
					wxListBox* pubKeysList = new wxListBox(tab1, wxID_ANY, wxDefaultPosition, wxSize( 620,200 ), 0, NULL, 0);

			//CertBoxSizer
			certBoxSizer->SetMinSize(wxSize(-1, 40));
			certBoxSizer->Add(newKeyButton, 0, wxALL, 5);
			certBoxSizer->Add(importKeysLabel, 0, wxALL, 12);
			certBoxSizer->Add(importKeysFile, 0, wxALL, 5);
			certBoxSizer->Add(searchLabel, 0, wxALL, 12);
			certBoxSizer->Add(searchCtrl, 0, wxALL|wxLEFT|wxRESERVE_SPACE_EVEN_IF_HIDDEN, 10);
	#ifndef __WXMAC__
	searchCtrl->ShowSearchButton(true);
	#endif
	searchCtrl->ShowCancelButton(false);
			certBoxSizer->Add(searchOkButton, 0, wxALL, 5);
			//CertGridSizer
			certGridB1Sizer->Add(privKeysLabel, 0, wxALL, 5);
			certGridB1Sizer->Add(privKeysList, 1, wxALL, 5);
			certGridB2Sizer->Add(pubKeysLabel, 0, wxALL, 5);
			certGridB2Sizer->Add(pubKeysList, 1, wxALL, 5);

			certGridSizer->Add(certGridB1Sizer, 1, wxEXPAND, 5);
			certGridSizer->Add(certGridB2Sizer, 1, wxEXPAND, 5);

		certSizer->Add(certBoxSizer, 0, wxALIGN_CENTER, 5);
		certSizer->Add(certGridSizer, 1, wxALIGN_CENTER, 5);

		tab1->SetSizer(certSizer);
		tab1->Layout();
		certSizer->Fit(tab1);



		//Notepad - Encrypt Decrypt, Sign Verify, File search, Save to clipboard
		wxBoxSizer* ntpdSizer = new wxBoxSizer(wxVERTICAL);
		wxBoxSizer* ntpdB1Sizer = new wxBoxSizer(wxVERTICAL);
			wxTextCtrl* notepadTextBox = new wxTextCtrl(tab2, wxID_ANY, "Hi!", wxDefaultPosition, wxSize(620, 300), wxTE_MULTILINE | wxTE_RICH , wxDefaultValidator, wxTextCtrlNameStr);
			//wxTextCtrl* notepadTextBox = new wxTextCtrl(tab2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(640, 300), 0|wxVSCROLL|wxHSCROLL|wxNO_BORDER|wxWANTS_CHARS);
		wxBoxSizer* ntpdB2Sizer = new wxBoxSizer(wxHORIZONTAL);
			wxButton* encryptButton = new wxButton(tab2, wxID_ANY, wxT("Encrypt"), wxDefaultPosition, wxDefaultSize, 0);
			wxButton* decryptButton = new wxButton(tab2, wxID_ANY, wxT("Decrypt"), wxDefaultPosition, wxDefaultSize, 0);
			wxButton* loadFromClipboardButton = new wxButton(tab2, wxID_ANY, wxT("Load from clipboard"), wxDefaultPosition, wxDefaultSize, 0);
//TODO:
//	popuniti wxString sa izborima preko for petlje
//	koliko kljuceva ima toliko izbora
//	i postaviti na onaj koji smo selektovali u certificates
			wxString pub_key_choices[] = {wxT("Mirko"), wxT("dimi"), wxT("rope")};
			int pub_key_n_choices = sizeof(pub_key_choices) / sizeof(wxString);
			wxChoice* choiceList = new wxChoice(tab2, wxID_ANY, wxDefaultPosition, wxSize( 220,-1 ), pub_key_n_choices, pub_key_choices, 0);
			choiceList->SetSelection(1);

//TODO:
//	Dodaj treci box sizer za output, ili dugmice za encrypt to clipboard..
		ntpdB1Sizer->Add(notepadTextBox, 1, wxALL, 5);
		ntpdB2Sizer->Add(encryptButton, 0, wxALL, 5);
		ntpdB2Sizer->Add(decryptButton, 0, wxALL, 5);
		ntpdB2Sizer->Add(loadFromClipboardButton, 0, wxALL, 5);
		ntpdB2Sizer->Add(choiceList, 0, wxALL, 5);

		ntpdSizer->Add(ntpdB1Sizer, 1, wxALIGN_CENTER_HORIZONTAL, 5);
		ntpdSizer->Add(ntpdB2Sizer, 0, wxALIGN_CENTER_HORIZONTAL, 5);
		
		tab2->SetSizer(ntpdSizer);
		tab2->Layout();
		ntpdSizer->Fit(tab2);



		//Hub - Client Server for sharing keys, compatible with website servers
		wxBoxSizer* hubSizer = new wxBoxSizer(wxVERTICAL);
		wxGridSizer* hubGSizer = new wxGridSizer(0, 2, 0, 0);
			wxPanel* hubServerPanel = new wxPanel(tab3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
			hubServerPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));
			wxBoxSizer* serverBoxSizer = new wxBoxSizer(wxVERTICAL);
				wxBoxSizer* serverB1Sizer = new wxBoxSizer(wxHORIZONTAL);
					wxStaticText* serverLabel = new wxStaticText(hubServerPanel, wxID_ANY, wxT("Server side:"), wxDefaultPosition, wxDefaultSize, 0);
				wxBoxSizer* serverB2Sizer = new wxBoxSizer(wxHORIZONTAL);
					wxStaticText* serverAddressLabel = new wxStaticText(hubServerPanel, wxID_ANY, wxT("Server address:"), wxDefaultPosition, wxDefaultSize, 0);
					wxStaticText* serverAddressText = new wxStaticText(hubServerPanel, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0);
				wxBoxSizer* serverB3Sizer = new wxBoxSizer(wxHORIZONTAL);
					wxButton* startServerButton = new wxButton(hubServerPanel, wxID_ANY, wxT("Start Server"), wxDefaultPosition, wxDefaultSize, 0);
					wxButton* shareSelectedKeysButton = new wxButton(hubServerPanel, wxID_ANY, wxT("Share selected keys"), wxDefaultPosition, wxDefaultSize, 0);
			wxPanel* hubClientPanel = new wxPanel(tab3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
			hubClientPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));
			wxBoxSizer* clientBoxSizer = new wxBoxSizer(wxVERTICAL);
				wxBoxSizer* clientB1Sizer = new wxBoxSizer(wxHORIZONTAL);
					wxStaticText* clientLabel = new wxStaticText(hubClientPanel, wxID_ANY, wxT("Server side:"), wxDefaultPosition, wxDefaultSize, 0);
				wxBoxSizer* clientB2Sizer = new wxBoxSizer(wxHORIZONTAL);
					wxStaticText* clientAddressLabel = new wxStaticText(hubClientPanel, wxID_ANY, wxT("Server address:"), wxDefaultPosition, wxDefaultSize, 0);
					wxTextCtrl* clientConnectAddress = new wxTextCtrl(hubClientPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 170,-1 ), 0);
				wxBoxSizer* clientB3Sizer = new wxBoxSizer(wxHORIZONTAL);
					wxButton* connectClientButton = new wxButton(hubClientPanel, wxID_ANY, wxT("Connect"), wxDefaultPosition, wxDefaultSize, 0);
					wxButton* ImportSelectedKeysButton = new wxButton(hubClientPanel, wxID_ANY, wxT("Import selected keys"), wxDefaultPosition, wxDefaultSize, 0);
		wxBoxSizer* hubBSizer = new wxBoxSizer(wxVERTICAL);
			wxString check_list_choices[] = {wxT("public_key1"), wxT("public_key2"), wxT("public_key3"), wxT("public_key4")};
			int chech_list_n_choices = sizeof(check_list_choices) / sizeof(wxString);
			wxCheckListBox* hubCheckListBox = new wxCheckListBox(tab3, wxID_ANY, wxDefaultPosition, wxSize( 620,200 ), chech_list_n_choices, check_list_choices, 0);
		
		//server
		
		hubGSizer->Add(hubServerPanel, 1, wxEXPAND | wxALL, 5);

		//client

		hubGSizer->Add(hubClientPanel, 1, wxEXPAND | wxALL, 5);

		hubBSizer->Add(hubCheckListBox, 0, wxALL, 5);

		hubSizer->Add(hubGSizer, 1, wxEXPAND, 5);
		hubSizer->Add(hubBSizer, 1, wxEXPAND, 5);
		
		tab3->SetSizer(hubSizer);
		tab3->Layout();
		hubSizer->Fit(tab3);



		//Properties - Minimize option, few others
		wxBoxSizer* propSizer = new wxBoxSizer(wxVERTICAL);
		wxStaticText* soonLabel = new wxStaticText(tab4, wxID_ANY, wxT("Soon.."), wxDefaultPosition, wxDefaultSize, 0);

		propSizer->Add(soonLabel, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxTOP, 220);
		
		tab4->SetSizer(propSizer);
		tab4->Layout();
		propSizer->Fit(tab4);

	//Add tabs to notebook
	notebook->AddPage(tab1, L"Certificates");
    notebook->AddPage(tab2, L"Notepad");
	notebook->AddPage(tab3, L"Hub");
	notebook->AddPage(tab4, L"Properties");

	//PanelSizer
    wxBoxSizer* panelSizer = new wxBoxSizer(wxVERTICAL);
    panelSizer->Add(notebook, 1, wxEXPAND);
    panel->SetSizer(panelSizer);

    //TopSizer
    wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);
    topSizer->SetMinSize(640, 480);
    topSizer->Add(panel, 1, wxEXPAND);
    SetSizerAndFit(topSizer);

	//Create taskbar icon
	m_taskBarIcon = new wxTaskBarIcon();
	if(!m_taskBarIcon->SetIcon(wxIcon(smile_xpm), wxT("wxTaskBarIcon Sample")))
		wxMessageBox(wxT("Could not set the icon!"));

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
