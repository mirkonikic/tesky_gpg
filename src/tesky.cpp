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
//TODO:
//	Add debug/verbose flag, koja daje visak informacija u terminalu

	tesky_aarch_info();		//print name of platform
	tesky_init_gpgme();		//initialize engine and gpgme lib
	tesky_init_keylists();	//initialize linked list, if .tesky, fill the lists
		
//DONE:
//	Na kraju uredi kod za razlicite arhitekture:
//include/probe.h - include-uje jednu od sledecih implementacija funkcija, ostatak se nalazi u main.cpp
//	src/arch/win32/probe.cpp
//	src/arch/linux/probe.cpp
//	src/arch/mac/probe.cpp
//DONE:
//	Check if the .tesky directory exists, if it does not, create one
//	If it does, import all the keys stored inside of the directory and continue from than on
//TODO:
//	Ako postoji, izvuci sve kljuceve iznutra i ubaci u linked listu, tako je najlakse
//	Nek postoje dve linked liste, priv i pub keys
//	Nek postoji selected_priv pokazivac na priv key koji smo selektovali i pub na key koji smo selektovali
//	kad to zavrsis ucitao si kljuceve, pripremio podatke nad kojima radis i mozemo da krenemo
//TODO:
//	podesi da izbor kljuca bude pored tabova, lakse je
//	Sada, u Certificates, na klik New Key, kreiramo nov fajl i pozivamo odgovarajucu gpgme funkciju, otvaramo nov prozor :)
//	Import keys i Search Bar su ez bas
//	U Notepadu, izabrati kome pisemo, pa Encrypt poziva odgovarajucu gpgme funkciju uz odgovarajuci public kljuc
//	Decrypt poziva odgovarajucu gpgme funkciju uz selektovani prvi kljuc
//	Hub moras da implementiras vec mrezu i jednostavni file sharing, stim sto NAT predstavlja problem
//	Jos Redesign
//	SADA TESKY ULAZI U ALPHA VERZIJU :)
//	System Tray Icon

	//Test TaskBarIcon
	if (!wxTaskBarIcon::IsAvailable())
        wxMessageBox("There appears to be no system tray support in your current environment. This sample may not behave as expected.", "Warning", wxOK | wxICON_EXCLAMATION);

	//Write mirko to clipboard
	//wxTheClipboard->Open();
	//wxTheClipboard->SetData( new wxTextDataObject("Mirko") );
	//wxTheClipboard->Close();

	//Read from clipboard
	/*
	wxTextDataObject data;
	wxTheClipboard->Open();	
	wxTheClipboard->GetData(data);
	wxMessageBox(data.GetText());
	wxTheClipboard->Close();
	*/





	// Ovde implementiraj:
	//	Crypter -> implementira metode neophodne za rad
	//	Interface -> je tehnicki iskontrolisan od strane wxwidgets
	//	Provider -> napravicu connect i recieve/send metode u klasi
	//	Controller -> singleton koji prati sta se desava i utice na osnovu toga
	// 





	TMenu *frame = new TMenu(wxT(" Tesky v0.46 "));
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
	//wxMenu *clipMenu = new wxMenu;



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
		//File
		fileMenu->Append(ID_NewKeyPair, wxT("New certificate\tCtrl-N"), wxT("Create New Key Pair"));
		fileMenu->Append(ID_Import, wxT("Import keys\tCtrl-I"), wxT("Import Public/Private Key"));
		fileMenu->Append(ID_Export, wxT("Export keys\tCtrl-E"), wxT("Export Public/Private Key"));
		fileMenu->Append(ID_PrintSecretKey, wxT("Print secret key\tCtrl-P"), wxT("Print out key"));
		fileMenu->Append(ID_Encrypt, wxT("Encrypt/Sign"), wxT("Encrypt Message or File"));
		fileMenu->Append(ID_Decrypt, wxT("Decrypt/Verify"), wxT("Decrypt Message or File"));
		fileMenu->Append(ID_CreateCheksumFiles, wxT("Create Cheksum Files"), wxT("Create Cheksum Files"));
		fileMenu->Append(ID_VerifyChecksumFiles, wxT("Verify Cheksum Files"), wxT("Verify Cheksum Files"));
		fileMenu->Append(ID_Close, wxT("Close\tCtrl-W"), wxT("Close/Stay in Background"));
		fileMenu->Append(wxID_EXIT, wxT("E&xit\tCtrl-Q"), wxT("Quit this program"));
		//View
		viewMenu->Append(ID_Refresh, wxT("Refresh\tF5"), wxT("Refresh current list"));
		viewMenu->Append(ID_CertDetails, wxT("Certificate details"), wxT("Details about selected certificate"));
		viewMenu->Append(ID_Certificates, wxT("Certificates"), wxT("Open Certificates tab"));
		viewMenu->Append(ID_Notepad, wxT("Notepad"), wxT("Open Notepad tab"));
		viewMenu->Append(ID_Hub, wxT("Hub"), wxT("Open Hub tab"));
		viewMenu->Append(ID_Chat, wxT("Chat"), wxT("Open Chat tab"));
		//Certificates
		certMenu->Append(wxID_ANY, wxT("&????...\tF1"), wxT("Show about dialog"));
		//Tools
		toolMenu->Append(ID_LogViewer, wxT("Log viewer"), wxT("View log files"));
		toolMenu->Append(ID_ClImport, wxT("Import from Clipboard"), wxT("Import data from Clipboard"));
		toolMenu->Append(ID_ClEncrypt, wxT("Clipboard Encrypt"), wxT("Encrypt data in Clipboard"));
		toolMenu->Append(ID_ClDecrypt, wxT("Clipboard Decrypt"), wxT("Decrypt data in Clipboard"));
		//Settings
		settMenu->Append(ID_SelfTest, wxT("Self test"), wxT("Perform self test"));
		//Window
		wndwMenu->Append(wxID_ANY, wxT("&????\tF1"), wxT("Show about dialog"));
		//Help
		helpMenu->Append(wxID_ABOUT, wxT("&About Tesky v0.06"), wxT("Show about dialog"));
		helpMenu->Append(ID_About_Mirko, wxT("&About Mirko and Credits"), wxT("Show about mirko dialog"));
		
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
	notebook = new wxNotebook(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_BOTTOM);

	//setup notebook
	//notebook->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT));
	notebook->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
	//wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT)
	//wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND)

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
				wxButton* newKeyButton = new wxButton(tab1, ID_certNewKey, wxT("New key"), wxDefaultPosition, wxDefaultSize, 0);
				wxStaticText* importKeysLabel = new wxStaticText(tab1, wxID_ANY, wxT("Import keys:"), wxDefaultPosition, wxDefaultSize, 0);
				importKeysFile = new wxFilePickerCtrl(tab1, ID_certImportKeysFile, wxEmptyString, wxT("Import keys"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE);
				wxStaticText* searchLabel = new wxStaticText(tab1, wxID_ANY, wxT("Search:"), wxDefaultPosition, wxDefaultSize, 0);
				wxSearchCtrl* searchCtrl = new wxSearchCtrl(tab1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
				wxButton* searchOkButton = new wxButton(tab1, ID_certOK, wxT("OK"), wxDefaultPosition, wxSize( 40,-1 ), 0);
			wxGridSizer* certGridSizer = new wxGridSizer(2, 0, 0, 0);
				wxBoxSizer* certGridB1Sizer = new wxBoxSizer(wxVERTICAL);
					wxStaticText* privKeysLabel = new wxStaticText(tab1, wxID_ANY, wxT("Private keys:"), wxDefaultPosition, wxDefaultSize, 0);
					privKeysList = new wxListBox(tab1, ID_certPrivKeysList, wxDefaultPosition, wxSize( 620,200 ), 0, NULL, 0);
				wxBoxSizer* certGridB2Sizer = new wxBoxSizer(wxVERTICAL);
					wxStaticText* pubKeysLabel = new wxStaticText(tab1, wxID_ANY, wxT("Public keys:"), wxDefaultPosition, wxDefaultSize, 0);
					pubKeysList = new wxListBox(tab1, ID_certPubKeysList, wxDefaultPosition, wxSize( 620,200 ), 0, NULL, 0);

//TODO:
//	popuniti preko for loop-a iz publistkey
			//OSMISLI KAKO DA UBACIM ADDED STVARI U GUI
/* TEST
			privKeysList->Append( wxT("priv_key1") );
			privKeysList->Append( wxT("priv_key2") );

			pubKeysList->Append( wxT("priv_key1") );
			pubKeysList->Append( wxT("priv_key2") );
			pubKeysList->Append( wxT("priv_key3") );
			pubKeysList->Append( wxT("priv_key4") );		
*/

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
			notepadTextBox = new wxTextCtrl(tab2, wxID_ANY, "Hi!", wxDefaultPosition, wxSize(620, 300), wxTE_MULTILINE | wxTE_RICH , wxDefaultValidator, wxTextCtrlNameStr);
			//wxTextCtrl* notepadTextBox = new wxTextCtrl(tab2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(640, 300), 0|wxVSCROLL|wxHSCROLL|wxNO_BORDER|wxWANTS_CHARS);
		wxBoxSizer* ntpdB2Sizer = new wxBoxSizer(wxHORIZONTAL);
			wxButton* encryptButton = new wxButton(tab2, ID_ntpdEncrypt, wxT("Encrypt"), wxDefaultPosition, wxDefaultSize, 0);
			wxButton* decryptButton = new wxButton(tab2, ID_ntpdDecrypt, wxT("Decrypt"), wxDefaultPosition, wxDefaultSize, 0);
			//wxButton* loadFromClipboardButton = new wxButton(tab2, ID_ntpdClImport, wxT("Load from clipboard"), wxDefaultPosition, wxDefaultSize, 0);
//TODO:
//	popuniti wxString sa izborima preko for petlje
//	koliko kljuceva ima toliko izbora
//	i postaviti na onaj koji smo selektovali u certificates
//	KAKO DA MODIFIKUJEM CHOICES
			//wxString pub_key_choices[] = {wxT("public_key1"), wxT("public_key2"), wxT("public_key3"), wxT("public_key4")};
			//int pub_key_n_choices = sizeof(pub_key_choices) / sizeof(wxString);
			wxString from_choices[] = {wxT("Clipboard"), wxT("Notepad")};	//, wxT("File")
			wxString to_choices[] = {wxT("Clipboard"), wxT("Notepad")};		// wxT("File"),
			int from_to_n_choices = 2;
			//choiceList = new wxChoice(tab2, ID_ntpdPubKeysChoice, wxDefaultPosition, wxSize( 220,-1 ), pub_key_n_choices, pub_key_choices, 0);
			fromChoices = new wxChoice(tab2, ID_ntpdPubKeysChoice, wxDefaultPosition, wxDefaultSize, from_to_n_choices, from_choices, 0);
			toChoices = new wxChoice(tab2, ID_ntpdPubKeysChoice, wxDefaultPosition, wxDefaultSize, from_to_n_choices, to_choices, 0);

			//label /
			wxStaticText* label_slash = new wxStaticText(tab2, wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
			label_slash->Wrap( -1 );
			//label from
			wxStaticText* label_from = new wxStaticText(tab2, wxID_ANY, wxT("from:"), wxDefaultPosition, wxDefaultSize, 0 );
			label_from->Wrap( -1 );
			//label to
			wxStaticText* label_to = new wxStaticText(tab2, wxID_ANY, wxT("to:"), wxDefaultPosition, wxDefaultSize, 0 );
			label_to->Wrap( -1 );
			
			chainEncryption = new wxBitmapButton(tab2, ID_ntpdChainButton, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );
			chainEncryption->SetBitmap( wxBitmap(wxT("img/tesky_broken_link.png"), wxBITMAP_TYPE_ANY));

//TODO:
//	ZASTO NE RADI pub_curr_key->id

			//choiceList->SetSelection(1);
			toChoices->SetSelection(1);
			fromChoices->SetSelection(1);

//TODO:
//	Dodaj treci box sizer za output, ili dugmice za encrypt to clipboard..
		ntpdB1Sizer->Add(notepadTextBox, 1, wxALL, 5);
		ntpdB2Sizer->Add(encryptButton, 0, wxALL, 5);
		//   /
		ntpdB2Sizer->Add(label_slash, 0, wxALIGN_CENTER|wxALL, 5 );
		ntpdB2Sizer->Add(decryptButton, 0, wxALL, 5);
		//    from
		ntpdB2Sizer->Add(label_from, 0, wxALIGN_CENTER|wxALL, 5 );
		ntpdB2Sizer->Add(fromChoices, 0, wxALL, 5 );
		//ntpdB2Sizer->Add(loadFromClipboardButton, 0, wxALL, 5);
		//    to
		ntpdB2Sizer->Add(label_to, 0, wxALIGN_CENTER|wxALL, 5 );
		ntpdB2Sizer->Add(toChoices, 0, wxALL, 5 );
		//ntpdB2Sizer->Add(choiceList, 0, wxALL, 5);
		ntpdB2Sizer->Add(chainEncryption, 0, wxALL, 5);

		ntpdSizer->Add(ntpdB1Sizer, 1, wxALIGN_CENTER_HORIZONTAL, 5);
		ntpdSizer->Add(ntpdB2Sizer, 0, wxALIGN_CENTER_HORIZONTAL, 5);
		
		tab2->SetSizer(ntpdSizer);
		tab2->Layout();
		ntpdSizer->Fit(tab2);



		//Hub - Client Server for sharing keys, compatible with website servers
		wxBoxSizer* hubSizer = new wxBoxSizer(wxVERTICAL);
		wxGridSizer* hubGSizer = new wxGridSizer(0, 2, 0, 0);
			wxPanel* hubServerPanel = new wxPanel(tab3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_RAISED);
			hubServerPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));
			wxBoxSizer* serverBoxSizer = new wxBoxSizer(wxVERTICAL);
				wxBoxSizer* serverB1Sizer = new wxBoxSizer(wxHORIZONTAL);
					wxStaticText* serverLabel = new wxStaticText(hubServerPanel, wxID_ANY, wxT("Server side:"), wxDefaultPosition, wxDefaultSize, 0);
				wxBoxSizer* serverB2Sizer = new wxBoxSizer(wxHORIZONTAL);
					wxStaticText* serverAddressLabel = new wxStaticText(hubServerPanel, wxID_ANY, wxT("Server address:"), wxDefaultPosition, wxDefaultSize, 0);
					wxTextCtrl* serverAddressText = new wxTextCtrl(hubServerPanel, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(150,-1), wxTE_READONLY);
				wxBoxSizer* serverB3Sizer = new wxBoxSizer(wxHORIZONTAL);
					wxButton* startServerButton = new wxButton(hubServerPanel, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0);
					wxButton* shareSelectedKeysButton = new wxButton(hubServerPanel, wxID_ANY, wxT("Share selected keys"), wxDefaultPosition, wxDefaultSize, 0);
			wxPanel* hubClientPanel = new wxPanel(tab3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_RAISED);
			hubClientPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));
			wxBoxSizer* clientBoxSizer = new wxBoxSizer(wxVERTICAL);
				wxBoxSizer* clientB1Sizer = new wxBoxSizer(wxHORIZONTAL);
					wxStaticText* clientLabel = new wxStaticText(hubClientPanel, wxID_ANY, wxT("Client side:"), wxDefaultPosition, wxDefaultSize, 0);
				wxBoxSizer* clientB2Sizer = new wxBoxSizer(wxHORIZONTAL);
					wxStaticText* clientAddressLabel = new wxStaticText(hubClientPanel, wxID_ANY, wxT("Server address:"), wxDefaultPosition, wxDefaultSize, 0);
					wxTextCtrl* clientConnectAddress = new wxTextCtrl(hubClientPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(150,-1), 0);
				wxBoxSizer* clientB3Sizer = new wxBoxSizer(wxHORIZONTAL);
					wxButton* connectClientButton = new wxButton(hubClientPanel, wxID_ANY, wxT("Connect"), wxDefaultPosition, wxDefaultSize, 0);
					wxButton* importSelectedKeysButton = new wxButton(hubClientPanel, wxID_ANY, wxT("Import selected keys"), wxDefaultPosition, wxDefaultSize, 0);
		wxBoxSizer* hubBSizer = new wxBoxSizer(wxVERTICAL);
			wxString check_list_choices[] = {wxT("public_key1"), wxT("public_key2"), wxT("public_key3"), wxT("public_key4")};
			int chech_list_n_choices = sizeof(check_list_choices) / sizeof(wxString);
			wxCheckListBox* hubCheckListBox = new wxCheckListBox(tab3, wxID_ANY, wxDefaultPosition, wxSize(620,200), chech_list_n_choices, check_list_choices, 0);

		//server
		serverB1Sizer->Add(serverLabel, 0, wxALL, 5);
		serverB2Sizer->Add(serverAddressLabel, 0, wxALL, 5);
		serverB2Sizer->Add(serverAddressText, 0, wxALL, 5);
		serverB3Sizer->Add(startServerButton, 0, wxALL, 5);
		serverB3Sizer->Add(shareSelectedKeysButton, 0, wxALL, 5);
		serverBoxSizer->Add(serverB1Sizer, 0, wxALL, 5);
		serverBoxSizer->Add(serverB2Sizer, 0, wxALL, 5);
		serverBoxSizer->Add(serverB3Sizer, 0, wxALL, 5);
		hubServerPanel->SetSizer(serverBoxSizer);
		hubServerPanel->Layout();
		serverBoxSizer->Fit(hubServerPanel);
		//client
		clientB1Sizer->Add(clientLabel, 0, wxALL, 5);
		clientB2Sizer->Add(clientAddressLabel, 0, wxALL, 5);
		clientB2Sizer->Add(clientConnectAddress, 0, wxALL, 5);
		clientB3Sizer->Add(connectClientButton, 0, wxALL, 5);
		clientB3Sizer->Add(importSelectedKeysButton, 0, wxALL, 5);
		clientBoxSizer->Add(clientB1Sizer, 0, wxALL, 5);
		clientBoxSizer->Add(clientB2Sizer, 0, wxALL, 5);
		clientBoxSizer->Add(clientB3Sizer, 0, wxALL, 5);
		hubClientPanel->SetSizer(clientBoxSizer);
		hubClientPanel->Layout();
		clientBoxSizer->Fit(hubClientPanel);
		
		hubGSizer->Add(hubServerPanel, 0, wxALL, 2);
		hubGSizer->Add(hubClientPanel, 0, wxALL, 2);

		hubBSizer->Add(hubCheckListBox, 1, wxALL | wxEXPAND, 0);

		hubSizer->Add(hubGSizer, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);
		hubSizer->Add(hubBSizer, 1, wxALL | wxEXPAND, 0);
		
		tab3->SetSizer(hubSizer);
		tab3->Layout();
		hubSizer->Fit(tab3);



//TODO:
//	Add CHAT tab later on
//	Add MDNetwork later on
//	Popravi: fali info kad se neko konektuje na server, 



		//Properties - Minimize option, few others
		wxBoxSizer* propSizer = new wxBoxSizer(wxVERTICAL);
		wxStaticText* soonLabel = new wxStaticText(tab4, wxID_ANY, wxT("Soon.."), wxDefaultPosition, wxDefaultSize, 0);

		propSizer->Add(soonLabel, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxTOP, 220);
		
		tab4->SetSizer(propSizer);
		tab4->Layout();
		propSizer->Fit(tab4);

	//Add tabs to notebook
	notebook->AddPage(tab1, L"Certificates");	//could be Keys
    notebook->AddPage(tab2, L"Notepad");		//could be Lab	
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

	//Update GUI
	//E sada imam nekoliko opcija
	//1. nadji nacin da pozivas append za chojs i list iz aarch.c
	//2. napravi updateGUI koji ce da appenduje od broja el, do broja linkdlist
	//3. dve metode 1. init_gui(); 2. update_gui()
	//		1. add all elements from list on beginning
	//		2. append or delete a key
	init_GUI();

	//Create taskbar icon
	//wxBitmap(wxT("img/tesky_link.png")
	MyTaskBarIcon* m_taskBarIcon = new MyTaskBarIcon();

    // we should be able to show up to 128 characters on Windows
    if (!m_taskBarIcon->SetIcon(wxIcon(wxT("img/tesky_link.png")),
                                 "wxTaskBarIcon Sample\n"
                                 "With a very, very, very, very\n"
                                 "long tooltip whose length is\n"
                                 "greater than 64 characters."))
    {
        wxLogError("Could not set icon.");
    }

	//Enable gpgme.h library
	//Add functionalities to buttons
	//Enable Clipboard
	//Enable system tray icon, na desni klik clipboard en/dec
	//Right Click enc/dec files ili ako je txt file samo dec to clipbrd

	//Bind(wxEVT_MENU, &TMenu::ClImport, this, ID_Hello);
}

//[Method implementations:]
/*	Cool way i generated methods from event enum :D
	clear; 
	for i in $(cat src/tesky.cpp | grep "(ID*" | cut -c20-45 | cut -d " " -f 1); 
	do 
		echo "void On$(echo $i | cut -c4- | tr -d ",")(wxCommandEvent& event);"; 
	done; 
	for i in $(cat src/tesky.cpp | grep "(ID*" | cut -c20-45 | cut -d " " -f 1); 
	do 
		echo -e "void TMenu::On$(echo $i | cut -c4- | tr -d ",")(wxCommandEvent& event)\n{\n\n\tevent.Skip();\n}\n"; 
	done
*/

//MENUBAR methods
void TMenu::OnNewKeyPair(wxCommandEvent& event){event.Skip();}
void TMenu::OnImport(wxCommandEvent& event){event.Skip();}
void TMenu::OnExport(wxCommandEvent& event){event.Skip();}
void TMenu::OnPrintSecretKey(wxCommandEvent& event){event.Skip();}
void TMenu::OnEncrypt(wxCommandEvent& event){event.Skip();}
void TMenu::OnDecrypt(wxCommandEvent& event){event.Skip();}
void TMenu::OnCreateCheksumFiles(wxCommandEvent& event){event.Skip();}
void TMenu::OnVerifyChecksumFiles(wxCommandEvent& event){event.Skip();}
void TMenu::OnClose(wxCommandEvent& event){event.Skip();}
void TMenu::OnRefresh(wxCommandEvent& event){event.Skip();}
void TMenu::OnCertDetails(wxCommandEvent& event){event.Skip();}
void TMenu::OnCertificates(wxCommandEvent& event){notebook->ChangeSelection(0);event.Skip();}
void TMenu::OnNotepad(wxCommandEvent& event){notebook->ChangeSelection(1);event.Skip();}
void TMenu::OnHub(wxCommandEvent& event){notebook->ChangeSelection(2);event.Skip();}
void TMenu::OnChat(wxCommandEvent& event){event.Skip();}
void TMenu::OnLogViewer(wxCommandEvent& event){event.Skip();}
//Done Climport, maybe needs optimization
void TMenu::OnClImport(wxCommandEvent& event)
{
	//Read from clipboard
	wxTextDataObject data;
	wxTheClipboard->Open();	
	wxTheClipboard->GetData(data);
	wxTheClipboard->Close();

	//move to notepad and import data from clipboard
	notebook->ChangeSelection(1);
	notepadTextBox->ChangeValue(data.GetText());

	event.Skip();
}
void TMenu::OnClEncrypt(wxCommandEvent& event){event.Skip();}
void TMenu::OnClDecrypt(wxCommandEvent& event){event.Skip();}
//after finishing the program, make a self test methd that pops up the message on what went wrong
void TMenu::OnSelfTest(wxCommandEvent& event){event.Skip();}
void TMenu::OnAbout_Mirko(wxCommandEvent& event)
{
	wxString msg;
	msg.Printf(wxT("Mirko developed this program for personal use"));
	wxMessageBox(msg, wxT("About Mirko"), wxOK | wxICON_INFORMATION, this);
	event.Skip();
}
void TMenu::OnAbout_Tesky(wxCommandEvent& event)
{
	wxString msg;
	msg.Printf(wxT("Welcome to Tesky v0.07 GPG encryption tool\n\t\tDeveloped by Mirko Nikic :D\n"));

	wxMessageBox(msg, wxT("About Tesky"), wxOK | wxICON_INFORMATION, this);
	event.Skip();
}
void TMenu::OnQuit(wxCommandEvent& event){Close();event.Skip();}
//Notebook methods
//Certificates methods
void TMenu::OncertImportKeysFile(wxFileDirPickerEvent& event)
{
	const char *path = strdup(importKeysFile->GetPath().mb_str().data());
	//printf("%s\n", path);
	tesky_import_key(path);
	UpdateGUI();
	event.Skip();
}
void TMenu::OnPrivKeysListSelect(wxCommandEvent& event)
{
	//prolazim kroz kljuceve da nadjem onaj sa id-om kliknutog kljuca
	privkey *pcurr = priv_head_node;
	int selected_n = privKeysList->GetSelection();
	while(pcurr->next!=nullptr && (pcurr->id)<selected_n)
	{
		pcurr = pcurr->next;
	}
	
	//uporedjujem jer je mozda zbog nullptra prekinut while
	if(pcurr->id != selected_n)
		printf("Nisam nasao choiceList id..");

	priv_curr_key = pcurr;
	OnPrivateKeyChangeUpdateGUI();
	event.Skip();
}
void TMenu::OnPubKeysListSelect(wxCommandEvent& event)
{
	//prolazim kroz kljuceve da nadjem onaj sa id-om kliknutog kljuca
	pubkey *pcurr = pub_head_node;
	int selected_n = pubKeysList->GetSelection();
	while(pcurr->next!=nullptr && (pcurr->id)<selected_n)
	{
		printf("LISTBOX: curr %d next %d search %d\n", pcurr->id, pcurr->next->id, selected_n);
		pcurr = pcurr->next;
	}
	
	//uporedjujem jer je mozda zbog nullptra prekinut while
	if(pcurr->id != selected_n)
		printf("Nisam nasao choiceList id..");

	pub_curr_key = pcurr;
	OnPublicKeyChangeUpdateGUI();
	event.Skip();	
}

TDialog::TDialog(wxFrame* parent) : wxDialog(parent, wxID_ANY, "Key Generation Menu", wxDefaultPosition, wxSize(480, 330))
{
	//definisati elemente gui-a
	wxStaticText* newKeyName;
	wxStaticText* newKeyEmail;
	wxStaticText* newKeyType;
	wxStaticText* newKeyPassword;
	wxStaticText* newKeyDate;
	wxStaticText* newKeyComment;
	
	wxGridSizer* newKeyGridSizer = new wxGridSizer( 0, 2, 0, 0 );

//left side
	wxBoxSizer* newKeyLeftSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* newKeyLeftTopSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* newKeyNameSizer = new wxBoxSizer( wxHORIZONTAL );
	wxBoxSizer* newKeyEmailSizer = new wxBoxSizer( wxHORIZONTAL );
	wxBoxSizer* newKeyTypeSizer = new wxBoxSizer( wxVERTICAL );
	wxBoxSizer* newKeyChoicesSizer = new wxBoxSizer( wxHORIZONTAL );
	wxBoxSizer* newKeyOkSizer = new wxBoxSizer( wxHORIZONTAL );
	wxBoxSizer* newKeyOkBSizer = new wxBoxSizer( wxVERTICAL );

	newKeyName = new wxStaticText( this, wxID_ANY, wxT("Name: "), wxDefaultPosition, wxDefaultSize, 0 );
	nkNameInput = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 160,-1 ), 0 );
	newKeyEmail = new wxStaticText( this, wxID_ANY, wxT("Email: "), wxDefaultPosition, wxDefaultSize, 0 );
	nkEmailInput = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 167,-1 ), 0 );
	newKeyType = new wxStaticText( this, wxID_ANY, wxT("Key type and length:"), wxDefaultPosition, wxDefaultSize, 0 );
	wxString nkAlgoChoiceChoices[] = { wxT("RSA") };
	int nkAlgoChoiceNChoices = sizeof( nkAlgoChoiceChoices ) / sizeof( wxString );
	nkAlgoChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 130,-1 ), nkAlgoChoiceNChoices, nkAlgoChoiceChoices, 0 );
	nkAlgoChoice->SetSelection( 0 );
	wxString nkLengthChoiceChoices[] = { wxT("4096") };
	int nkLengthChoiceNChoices = sizeof( nkLengthChoiceChoices ) / sizeof( wxString );
	nkLengthChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 130,-1 ), nkLengthChoiceNChoices, nkLengthChoiceChoices, 0 );
	nkLengthChoice->SetSelection( 0 );
	nkOkButton = new wxButton( this, ID_nkOk, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );

	newKeyNameSizer->SetMinSize( wxSize( -1,40 ) );
	newKeyEmailSizer->SetMinSize( wxSize( -1,60 ) );
	newKeyTypeSizer->SetMinSize( wxSize( -1,60 ) );

	newKeyNameSizer->Add( newKeyName, 0, wxALIGN_CENTER|wxALL, 10 );
	newKeyNameSizer->Add( nkNameInput, 0, wxALIGN_CENTER|wxALL, 5 );
	newKeyEmailSizer->Add( newKeyEmail, 0, wxALIGN_CENTER|wxLEFT, 10 );
	newKeyEmailSizer->Add( nkEmailInput, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	newKeyTypeSizer->Add( newKeyType, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 10 );
	newKeyChoicesSizer->Add( nkAlgoChoice, 0, wxALIGN_CENTER|wxALL, 5 );
	newKeyChoicesSizer->Add( nkLengthChoice, 0, wxALIGN_CENTER|wxALL, 5 );
	newKeyTypeSizer->Add( newKeyChoicesSizer, 1, wxEXPAND, 5 );
	newKeyOkBSizer->Add( nkOkButton, 0, wxALL, 5 );
	newKeyOkSizer->Add( newKeyOkBSizer, 1, wxALIGN_BOTTOM|wxALL, 15 );


	newKeyLeftTopSizer->Add( newKeyNameSizer, 1, wxEXPAND, 5 );
	newKeyLeftTopSizer->Add( newKeyEmailSizer, 0, wxLEFT, 5 );
	newKeyLeftTopSizer->Add( newKeyTypeSizer, 1, wxEXPAND, 5 );


	newKeyLeftSizer->Add( newKeyLeftTopSizer, 1, 0, 5 );
	newKeyLeftSizer->Add( newKeyOkSizer, 1, wxALIGN_CENTER_HORIZONTAL, 5 );

	newKeyGridSizer->Add( newKeyLeftSizer, 1, wxEXPAND, 5 );
//left side done

//right side
	wxBoxSizer* newKeyRightSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* newKeyPasswordSizer = new wxBoxSizer( wxHORIZONTAL );
	wxBoxSizer* newKeyDateSizer = new wxBoxSizer( wxHORIZONTAL );
	wxBoxSizer* newKeyCommentSizer = new wxBoxSizer( wxVERTICAL );
	wxBoxSizer* newKeyCancelSizer = new wxBoxSizer( wxHORIZONTAL );
	wxBoxSizer* newKeyCancelBSizer = new wxBoxSizer( wxVERTICAL );

	newKeyPassword = new wxStaticText( this, wxID_ANY, wxT("Passphrase: "), wxDefaultPosition, wxDefaultSize, 0 );
	nkPasswordInput = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	newKeyDate = new wxStaticText( this, wxID_ANY, wxT("Expire-Date: "), wxDefaultPosition, wxDefaultSize, 0 );
	nkDateInput = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	newKeyComment = new wxStaticText( this, wxID_ANY, wxT("Name-Comment:"), wxDefaultPosition, wxDefaultSize, 0 );
	nkCommentInput = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	nkCancelButton = new wxButton( this, ID_nkCancel, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );

	newKeyPassword->Wrap( -1 );
	newKeyDate->Wrap( -1 );
	newKeyComment->Wrap( -1 );

	newKeyPasswordSizer->SetMinSize( wxSize( -1,40 ) );
	nkPasswordInput->SetMinSize( wxSize( 120,-1 ) );
	newKeyDateSizer->SetMinSize( wxSize( -1,60 ) );
	nkDateInput->SetMinSize( wxSize( 120,-1 ) );
	newKeyCommentSizer->SetMinSize( wxSize( -1,60 ) );


	newKeyPasswordSizer->Add( newKeyPassword, 0, wxALIGN_CENTER|wxALL, 10 );
	newKeyPasswordSizer->Add( nkPasswordInput, 0, wxALIGN_CENTER|wxALL, 5 );
	newKeyDateSizer->Add( newKeyDate, 0, wxALIGN_CENTER|wxALL, 10 );
	newKeyDateSizer->Add( nkDateInput, 0, wxALIGN_CENTER|wxALL, 5 );
	newKeyCommentSizer->Add( newKeyComment, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 10 );
	newKeyCommentSizer->Add( nkCommentInput, 0, wxALL|wxEXPAND, 5 );
	newKeyCancelBSizer->Add( nkCancelButton, 0, wxALL, 5 );
	newKeyCancelSizer->Add( newKeyCancelBSizer, 1, wxALIGN_BOTTOM|wxALL, 15 );

	newKeyRightSizer->Add( newKeyPasswordSizer, 1, wxEXPAND, 5 );
	newKeyRightSizer->Add( newKeyDateSizer, 1, wxEXPAND, 5 );
	newKeyRightSizer->Add( newKeyCommentSizer, 1, wxEXPAND, 5 );
	newKeyRightSizer->Add( newKeyCancelSizer, 1, wxALIGN_CENTER_HORIZONTAL, 5 );

	newKeyGridSizer->Add( newKeyRightSizer, 1, wxEXPAND, 5 );
//right side done



	this->SetSizer( newKeyGridSizer );
	this->Layout();
	this->Centre( wxBOTH );

}

void TMenu::OncertNewKey(wxCommandEvent& event)
{
//TODO:
//	NEKAKO napravi da znaju da ne moraju da postave password
//	NEKAKO napravi da znaju da expire date moze da ne istice

	printf("NEW_KEY: generation menu opened\n");
	
	TDialog *dialog = new TDialog(this);
	dialog->ShowWindowModal();

	printf("NEW_KEY: generation menu closed\n");
	
	UpdateGUI();

	event.Skip();

	//UVEK KAD POZIVAS ADD ILI DELETE, POZIVAS I UPDATE GUI
	//tesky_add_to_pubkeylist("pubkey7", "user8");
	//UpdateGUI();

	/*
	gpgme_error_t gpgme_op_genkey (gpgme_ctx_t ctx, const char *parms, gpgme_data_t public, gpgme_data_t secret)
The function gpgme_op_genkey generates a new key pair in the context ctx. The meaning of public and secret depends on the crypto backend.

GPG does not support public and secret, they should be NULL. GnuPG will generate a key pair and add it to the standard key ring. The fingerprint of the generated key is available with gpgme_op_genkey_result.

GpgSM requires public to be a writable data object. GpgSM will generate a secret key (which will be stored by gpg-agent, and return a certificate request in public, which then needs to be signed by the certification authority and imported before it can be used. GpgSM does not make the fingerprint available.

The argument parms specifies parameters for the key in an string that looks something like XML. The details about the format of parms are specific to the crypto engine used by ctx. The first line of the parameters must be <GnupgKeyParams format="internal"> and the last line must be </GnupgKeyParams>. Every line in between the first and last lines is treated as a Header: Value pair. In particular, no XML escaping is necessary if you need to include the characters <, >, or &.

Here is an example for GnuPG as the crypto engine (all parameters of OpenPGP key generation are documented in the GPG manual):

<GnupgKeyParms format="internal">
Key-Type: default
Subkey-Type: default
Name-Real: Joe Tester
Name-Comment: with stupid passphrase
Name-Email: joe@foo.bar
Expire-Date: 0
Passphrase: abc
</GnupgKeyParms>
Here is an example for GpgSM as the crypto engine (all parameters of OpenPGP key generation are documented in the GPGSM manual):

<GnupgKeyParms format="internal">
Key-Type: RSA
Key-Length: 1024
Name-DN: C=de,O=g10 code,OU=Testlab,CN=Joe 2 Tester
Name-Email: joe@foo.bar
</GnupgKeyParms>
*/


	//on ok create event, on cancel close this tab
	//add button ok, cancel, name, last name, email, password, algo, key-length
	//comment, expire date

	event.Skip();
}
void TMenu::OncertOK(wxCommandEvent& event){event.Skip();}
//Notepad methods
void TMenu::OnNtpdChainClick(wxCommandEvent& event)
{
	//check if the chain_enabled is true
	//set icon of the button and chain_enabled :)
	
	if(chain_enabled)
		chainEncryption->SetBitmap(wxBitmap(wxT("img/tesky_broken_link.png"), wxBITMAP_TYPE_ANY));
	else {chainEncryption->SetBitmap(wxBitmap(wxT("img/tesky_link.png"), wxBITMAP_TYPE_ANY));}
		chain_enabled = !chain_enabled;
	
	//na osnovu ovoga ce se pmenjati nacin enkripcije
	event.Skip();
}
//OnNtpdClImport -> OnClImport, isti su :D
//Moved OnPrivKeyChoiceSelect to OnCurrentPublicKeyChange
	//So that all elements change when one gets changed
void TMenu::OnPrivKeysChoiceSelect(wxCommandEvent& event)
{
	/* NEMAM PRIV KEY CHOICE LIST JOS
	//prolazim kroz kljuceve da nadjem onaj sa id-om kliknutog kljuca
	privkey *pcurr = (privkey *)malloc(sizeof(privkey));
	int selected_n = privKeysList->GetSelection();
	while(pcurr->next!=nullptr && (pcurr->id)<selected_n)
	{
		pcurr = pcurr->next;
	}
	
	//uporedjujem jer je mozda zbog nullptra prekinut while
	if(pcurr->id != selected_n)
		printf("Nisam nasao choiceList id..");

	priv_curr_key = pcurr;
	OnPrivateKeyChangeUpdateGUI();	
	*/
	event.Skip();
}
void TMenu::OnPubKeysChoiceSelect(wxCommandEvent& event)
{
	//prolazim kroz kljuceve da nadjem onaj sa id-om kliknutog kljuca
/*
	pubkey *pcurr = pub_head_node;
	int selected_n = choiceList->GetSelection();
	printf("%d trazim\n", selected_n);
	while(pcurr->next!=nullptr && (pcurr->id)<selected_n)
	{
		printf("CHOICE: curr %d next %d search %d\n", pcurr->id, pcurr->next->id, selected_n);
		pcurr = pcurr->next;
	}

	//uporedjujem jer je mozda zbog nullptra prekinut while
	if(pcurr->id != selected_n)
		printf("Nisam nasao choiceList id.. %d != %d\n", pcurr->id, selected_n);

	pub_curr_key = pcurr;
	OnPublicKeyChangeUpdateGUI();
	event.Skip();
*/
}
void TMenu::OnPublicKeyChangeUpdateGUI()
{
	//update all elements that keep track of public keys
	pubKeysList->SetSelection(pub_curr_key->id);
	//choiceList->SetSelection(pub_curr_key->id);
}
void TMenu::OnPrivateKeyChangeUpdateGUI()
{
	//update all elements that keep track of private keys
	privKeysList->SetSelection(priv_curr_key->id);
	//PrivateChoiceList->SetSelection(priv_curr_key->id);
}
void TMenu::UpdateGUI()
{
//TODO:
//	Ne smes da castujes unsigned int u (int) jer moze da nastane buffer overflow vuln
//	Bolje prevedi oba u long? tamo nijedan ni drugi nece preteci
	
//TODO:
//	Imaju 50 slova za ime, ostatak za mejl, da bi bilo uredno
//	to cu preko for petlje uraditi :)	
	//append when new element is added to list
	int n_pubList = pubKeysList->GetCount();
	int n_privList = privKeysList->GetCount();
	if(n_pubList < n_pubkey)		//ima vise elemenata u kljucevima nego GUI
	{
		printf("UPDATE: vise elemenata ima List:%d < pub: %d\n", pubKeysList->GetCount(), n_pubkey);
		pubkey *p1 = pub_head_node;					//krecemo od pocetnog el. liste jer ne znamo za koliko je veci broj elemenata liste od GUI-a
		while(p1!=nullptr)
		{
			if((p1->id+1) > n_pubList)				//posto je id manji za jedan od broja tog elementa, dodajemo +1
			{	
				std::string buf(p1->user_name);
				long unsigned int n = buf.length();
				for(long unsigned int i=0; i<(40-n); i++)
				{
					buf.append("..");
				}
				buf.append(p1->email);
				//choiceList->Append(p1->user_name);	//dodajemo u choice list
				pubKeysList->Append(buf);	//dodajemo u pub keys list
			}
			p1 = p1->next;		//sledeci element liste proveravamo
		}
	}
		
	//delete when some element is deleted from list
	if(n_privList < n_privkey)		//ima vise elemenata u kljucevima nego GUI
	{
		printf("UPDATE: vise elemenata ima List:%d < pub: %d\n", privKeysList->GetCount(), n_privkey);
		privkey *p2 = priv_head_node;
		while(p2!=nullptr)
		{
			if((p2->id+1) > n_privList)
			{
				std::string buf2(p2->user_name);
				long unsigned int n = buf2.length();
				for(long unsigned int i=0; i<(40-n); i++)
				{
					buf2.append("..");
				}
				buf2.append(p2->email);
				privKeysList->Append(buf2);
			}
			p2 = p2->next;
		}
	}
}
void TMenu::init_GUI()
{
	//populate GUI elements with elements from public/priv linkedlist elements
	//check if there are any elements
	if(n_pubkey == 0 && n_privkey == 0)
		return;
	
	pubkey *p1 = pub_head_node;
	privkey *p2 = priv_head_node;

	//public keys list -> choiceList.append() & pubKeysList->append()
	while(p1!=nullptr)
	{
		std::string buf(p1->user_name);
		long unsigned int n = buf.length();
		for(long unsigned int i=0; i<(40-n); i++)
		{
			buf.append("..");
		}
		buf.append(p1->email);
		//choiceList->Append(p1->user_name);
		pubKeysList->Append(buf);
		p1 = p1->next;
	}
	//private keys list -> //PrivChoiceList.append() & privKeysList->append()
	while(p2!=nullptr)
	{
		std::string buf2(p2->user_name);
		long unsigned int n = buf2.length();
		for(long unsigned int i=0; i<(40-n); i++)
		{
			buf2.append("..");
		}
		buf2.append(p2->email);
		//PrivChoiceList->Append
		privKeysList->Append(buf2);
		p2 = p2->next;
	}

	//set selections in choiceList
	if(pub_curr_key != nullptr)
		OnPublicKeyChangeUpdateGUI();
	if(priv_curr_key != nullptr)
		OnPrivateKeyChangeUpdateGUI();
}
void TMenu::OnNtpdEncrypt(wxCommandEvent& event)
{
	//check fromChoices and toChoices wxChoices
	int from_selection = fromChoices->GetSelection();
	int to_selection = toChoices->GetSelection();
	
	//process input accordingly
	const char *arg;
	wxTextDataObject data;
	switch(from_selection)
	{
		case 0:
			wxTheClipboard->Open();	
			wxTheClipboard->GetData(data);
			wxTheClipboard->Close();
			arg = strdup(data.GetText());
			printf("ENCRYPTION ENGINE: Input set to Clipboard :D");
			break;
		case 1:
			arg = strdup(notepadTextBox->GetValue().mb_str().data());
			printf("ENCRYPTION ENGINE: Input set to Notepad :D");
			break;
		default:
			arg = strdup(notepadTextBox->GetValue().mb_str().data());	
			break;
	}

	//call the encrypt method
	std::string result = tesky_encrypt_data(arg, strlen(arg));
	
	//save to the beforementioned output
	wxString data_out(result.c_str());
	switch(to_selection)
	{
		case 0:
			wxTheClipboard->Open();	
			wxTheClipboard->SetData(new wxTextDataObject(data_out) );
			wxTheClipboard->Close();
			printf("ENCRYPTION ENGINE: Output set to Clipboard :D\n\n\n");
			break;
		case 1:
			notepadTextBox->ChangeValue(data_out);//result.c_str());
			printf("ENCRYPTION ENGINE: Output set to Notepad :D\n\n\n");
			break;
		default:
			notepadTextBox->ChangeValue(data_out);//result.c_str());
			break;
	}

	event.Skip();
}
void TMenu::OnNtpdDecrypt(wxCommandEvent& event)
{
	//DECRYPTION zavisi od link-a odnosno chain-a
	//ako nije povezan - broken link - false
	//		tada enkriptuje i dekriptuje sa leva na desno
	//		Notepad -> Clipboard oba
	//ako jeste povezan
	//		tada enkriptuje L->D, a dekriptuje D->L
	//		E: Notepad->Clipboard     D: Clipboard->Notepad
	
	//check fromChoices and toChoices wxChoices
	int from_selection = fromChoices->GetSelection();
	int to_selection = toChoices->GetSelection();
	
	//process input accordingly
	const char *arg;
	wxTextDataObject data;
	
	//u slucaju da je chain off - false - isto kao enkripcija
	//		chain == 0
	//		to == 0 -> Clipboard
	//		to == 1 -> Notepad

	//u slucaju da je chain on - true - suprotno od enkripcije
	//		chain == 1
	//		to == 1 -> Clipboard
	//		to == 0 -> Notepad
	if(from_selection == chain_enabled)
	{
			wxTheClipboard->Open();	
			wxTheClipboard->GetData(data);
			wxTheClipboard->Close();
			arg = strdup(data.GetText());
			printf("DECRYPTION ENGINE: Input set to Clipboard :D\n");
	}
	else if(from_selection == !chain_enabled)
	{
			arg = strdup(notepadTextBox->GetValue().mb_str().data());	
			printf("DECRYPTION ENGINE: Input set to Notepad :D\n");
	}
	
	//call the encrypt method
	std::string result = tesky_decrypt_data(arg, strlen(arg));
	//save to the beforementioned output
	wxString data_out(result.c_str());

	//u slucaju da je chain off - false - isto kao enkripcija
	//		chain == 0
	//		to == 0 -> Clipboard
	//		to == 1 -> Notepad

	//u slucaju da je chain on - true - suprotno od enkripcije
	//		chain == 1
	//		to == 1 -> Clipboard
	//		to == 0 -> Notepad
	if(to_selection == chain_enabled)
	{
			wxTheClipboard->Open();	
			wxTheClipboard->SetData(new wxTextDataObject(data_out) );
			wxTheClipboard->Close();
			printf("DECRYPTION ENGINE: Output set to Clipboard :D\n\n\n");
	}
	else if(to_selection == !chain_enabled)
	{
			notepadTextBox->ChangeValue(data_out);//result.c_str());
			printf("DECRYPTION ENGINE: Output set to Notepad :D\n\n\n");
	}

	event.Skip();
}
//Hub methods
void TMenu::OnhubStartServer(wxCommandEvent& event){event.Skip();}
void TMenu::OnhubShareKeys(wxCommandEvent& event){event.Skip();}
void TMenu::OnhubConnectClient(wxCommandEvent& event){event.Skip();}
void TMenu::OnhubImportKeys(wxCommandEvent& event){event.Skip();}
//Chat methods
//Properties methods
//MDNetwork methods


void TDialog::onNKOK(wxCommandEvent& event)
{
//TODO:
//	Input Validation

	//pozvati generaciju kljuca
	std::string name = strdup(nkNameInput->GetValue().mb_str().data());
	std::string email = strdup(nkEmailInput->GetValue().mb_str().data());
	std::string password = strdup(nkPasswordInput->GetValue().mb_str().data());
	std::string comment = strdup(nkCommentInput->GetValue().mb_str().data());
	std::string algo = strdup(nkAlgoChoice->GetString(nkAlgoChoice->GetSelection()).mb_str().data());
	std::string length = strdup(nkLengthChoice->GetString(nkLengthChoice->GetSelection()).mb_str().data());
	wxDateTime date = nkDateInput->GetValue();
	std::time_t t = std::time(0);  // t is an integer type
	int timestamp = date.GetTicks() - t;
	if(timestamp < 1)	//ako razlika nije veca od jednog dana
		timestamp = 0;	//ne istice :)
		
	//generate key
	std::string key_info = "<GnupgKeyParms format=\"internal\">\n";
	key_info.append("Key-Type: " + algo + "\n");
	key_info.append("Key-Length: " + length + "\n");
	key_info.append("Name-Real: " + name + "\n");
	key_info.append("Name-Comment: " + comment + "\n");
	key_info.append("Name-Email: " + email + "\n");
	key_info.append("Expire-Date: " + std::to_string(timestamp/(60*60*24)) + "\n");
	key_info.append("Passphrase: " + password + "\n");
	key_info.append("</GnupgKeyParms>\n");
	printf("%s\n", key_info.c_str());
//	const char *key_info = "<GnupgKeyParms format=\"internal\">\n"
//						"Key-Type: default\n"
//						"Key-Length: %s\n", length"
//						"Name-Real: Joe Tester\n"
//						"Name-Comment: with stupid passphrase\n"
//						"Name-Email: joe@foo.bar\n"
//						"Expire-Date: 0\n"
//						"Passphrase: abc\n"
//						"</GnupgKeyParms>\n";

	tesky_generate_new_keypair(key_info.c_str());

	this->Destroy();
	event.Skip();
}
void TDialog::onNKCancel(wxCommandEvent& event)
{
	//zatvoriti prozorce	
	this->Destroy();
}

wxMenu *MyTaskBarIcon::CreatePopupMenu()
{
    wxMenu *menu = new wxMenu;
    menu->Append(PU_RESTORE, "&Open/Minimize Window");
    menu->AppendSeparator();
    menu->Append(PU_NEW_ICON, "&Encrypt clipboard");
//    menu->Append(PU_NEW_ICON, "&Set New Icon");
    menu->AppendSeparator();
    menu->AppendCheckItem(PU_CHECKMARK, "&Decyrpt clipboard");
//    menu->AppendCheckItem(PU_CHECKMARK, "Test &check mark");
    menu->AppendSeparator();
//    wxMenu *submenu = new wxMenu;
//    submenu->Append(PU_SUB1, "One submenu");
//    submenu->AppendSeparator();
//    submenu->Append(PU_SUB2, "Another submenu");
//    menu->Append(PU_SUBMAIN, "Submenu", submenu);
    /* OSX has built-in quit menu for the dock menu, but not for the status item */
#ifdef __WXOSX__
    if ( OSXIsStatusItem() )
#endif
    {
        menu->AppendSeparator();
        menu->Append(PU_EXIT,    "&Quit");
    }
    return menu;
}

void MyTaskBarIcon::OnLeftButtonDClick(wxTaskBarIconEvent&)
{
    printf("ikonica kliknuta :)\n");
	CreatePopupMenu();
}