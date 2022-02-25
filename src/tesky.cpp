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
	//if (!wxTaskBarIcon::IsAvailable())
    //    wxMessageBox("There appears to be no system tray support in your current environment. This sample may not behave as expected.", "Warning", wxOK | wxICON_EXCLAMATION);

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

	TMenu *frame = new TMenu(wxT(" Tesky v0.12 "));
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
				wxFilePickerCtrl* importKeysFile = new wxFilePickerCtrl(tab1, wxID_ANY, wxEmptyString, wxT("Import keys"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE);
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
			wxButton* loadFromClipboardButton = new wxButton(tab2, ID_ntpdClImport, wxT("Load from clipboard"), wxDefaultPosition, wxDefaultSize, 0);
//TODO:
//	popuniti wxString sa izborima preko for petlje
//	koliko kljuceva ima toliko izbora
//	i postaviti na onaj koji smo selektovali u certificates
//	KAKO DA MODIFIKUJEM CHOICES
			//wxString pub_key_choices[] = {wxT("public_key1"), wxT("public_key2"), wxT("public_key3"), wxT("public_key4")};
			//int pub_key_n_choices = sizeof(pub_key_choices) / sizeof(wxString);
			wxString pub_key_choices[] = {};
			int pub_key_n_choices = 0;
			choiceList = new wxChoice(tab2, ID_ntpdPubKeysChoice, wxDefaultPosition, wxSize( 220,-1 ), pub_key_n_choices, pub_key_choices, 0);
			
//TODO:
//	ZASTO NE RADI pub_curr_key->id

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

	//Update GUI
	//E sada imam nekoliko opcija
	//1. nadji nacin da pozivas append za chojs i list iz aarch.c
	//2. napravi updateGUI koji ce da appenduje od broja el, do broja linkdlist
	//3. dve metode 1. init_gui(); 2. update_gui()
	//		1. add all elements from list on beginning
	//		2. append or delete a key
	init_GUI();

	//Create taskbar icon

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
void TMenu::OncertNewKey(wxCommandEvent& event)
{
	printf("newkey pressed\n");
	//UVEK KAD POZIVAS ADD ILI DELETE, POZIVAS I UPDATE GUI
	//tesky_add_to_pubkeylist("pubkey7", "user8");
	//UpdateGUI();
	event.Skip();
}
void TMenu::OncertOK(wxCommandEvent& event){event.Skip();}
//Notepad methods
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
}
void TMenu::OnPublicKeyChangeUpdateGUI()
{
	//update all elements that keep track of public keys
	pubKeysList->SetSelection(pub_curr_key->id);
	choiceList->SetSelection(pub_curr_key->id);
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
				choiceList->Append(p1->user_name);	//dodajemo u choice list
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
		choiceList->Append(p1->user_name);
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

void TMenu::OnNtpdEncrypt(wxCommandEvent& event){event.Skip();}
void TMenu::OnNtpdDecrypt(wxCommandEvent& event){event.Skip();}
//Hub methods
void TMenu::OnhubStartServer(wxCommandEvent& event){event.Skip();}
void TMenu::OnhubShareKeys(wxCommandEvent& event){event.Skip();}
void TMenu::OnhubConnectClient(wxCommandEvent& event){event.Skip();}
void TMenu::OnhubImportKeys(wxCommandEvent& event){event.Skip();}
//Chat methods
//Properties methods
//MDNetwork methods
