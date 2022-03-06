///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-40-g8042f487)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "noname.h"

///////////////////////////////////////////////////////////////////////////

TMenu::TMenu( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : forward_declare( parent, id, title, pos, size, style, name )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_menubar1 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	wxMenuItem* m_menuItem1;
	m_menuItem1 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem1 );

	wxMenuItem* m_menuItem2;
	m_menuItem2 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem2 );

	wxMenuItem* m_menuItem3;
	m_menuItem3 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem3 );

	wxMenuItem* m_menuItem4;
	m_menuItem4 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem4 );

	wxMenuItem* m_menuItem5;
	m_menuItem5 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem5 );

	wxMenuItem* m_menuItem6;
	m_menuItem6 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem6 );

	wxMenuItem* m_menuItem7;
	m_menuItem7 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem7 );

	wxMenuItem* m_menuItem8;
	m_menuItem8 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem8 );

	wxMenuItem* m_menuItem9;
	m_menuItem9 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem9 );

	wxMenuItem* m_menuItem10;
	m_menuItem10 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem10 );

	m_menubar1->Append( m_menu1, wxT("File") );

	m_menu2 = new wxMenu();
	wxMenuItem* m_menuItem11;
	m_menuItem11 = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem11 );

	wxMenuItem* m_menuItem12;
	m_menuItem12 = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem12 );

	wxMenuItem* m_menuItem13;
	m_menuItem13 = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem13 );

	m_menubar1->Append( m_menu2, wxT("View") );

	m_menu3 = new wxMenu();
	wxMenuItem* m_menuItem14;
	m_menuItem14 = new wxMenuItem( m_menu3, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem14 );

	m_menubar1->Append( m_menu3, wxT("Certificate") );

	m_menu4 = new wxMenu();
	wxMenuItem* m_menuItem15;
	m_menuItem15 = new wxMenuItem( m_menu4, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem15 );

	wxMenuItem* m_menuItem16;
	m_menuItem16 = new wxMenuItem( m_menu4, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem16 );

	wxMenuItem* m_menuItem17;
	m_menuItem17 = new wxMenuItem( m_menu4, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem17 );

	m_menubar1->Append( m_menu4, wxT("Tools") );

	m_menu5 = new wxMenu();
	wxMenuItem* m_menuItem18;
	m_menuItem18 = new wxMenuItem( m_menu5, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu5->Append( m_menuItem18 );

	m_menubar1->Append( m_menu5, wxT("Settings") );

	m_menu6 = new wxMenu();
	wxMenuItem* m_menuItem19;
	m_menuItem19 = new wxMenuItem( m_menu6, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu6->Append( m_menuItem19 );

	m_menubar1->Append( m_menu6, wxT("Window") );

	m_menu7 = new wxMenu();
	wxMenuItem* m_menuItem20;
	m_menuItem20 = new wxMenuItem( m_menu7, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu7->Append( m_menuItem20 );

	m_menubar1->Append( m_menu7, wxT("Help") );

	this->SetMenuBar( m_menubar1 );

	m_statusBar1 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	menu = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_BOTTOM );
	menu->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	menu->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );

	m_panel4 = new wxPanel( menu, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel4->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVEBORDER ) );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	bSizer11->SetMinSize( wxSize( -1,40 ) );
	m_button7 = new wxButton( m_panel4, wxID_ANY, wxT("New key"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button7, 0, wxALL, 5 );

	m_staticText8 = new wxStaticText( m_panel4, wxID_ANY, wxT("Import keys:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer11->Add( m_staticText8, 0, wxALL, 12 );

	m_filePicker3 = new wxFilePickerCtrl( m_panel4, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	bSizer11->Add( m_filePicker3, 0, wxALL, 5 );

	m_staticText9 = new wxStaticText( m_panel4, wxID_ANY, wxT("Search:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer11->Add( m_staticText9, 0, wxALL, 12 );

	m_searchCtrl2 = new wxSearchCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	m_searchCtrl2->ShowSearchButton( true );
	#endif
	m_searchCtrl2->ShowCancelButton( false );
	bSizer11->Add( m_searchCtrl2, 0, wxALL|wxLEFT|wxRESERVE_SPACE_EVEN_IF_HIDDEN, 10 );

	m_button10 = new wxButton( m_panel4, wxID_ANY, wxT("OK"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer11->Add( m_button10, 0, wxALL, 5 );


	bSizer10->Add( bSizer11, 1, wxALIGN_CENTER, 5 );

	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 2, 0, 0, 0 );

	gSizer1->SetMinSize( wxSize( -1,250 ) );
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	m_staticText6 = new wxStaticText( m_panel4, wxID_ANY, wxT("Private keys:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer14->Add( m_staticText6, 0, wxALL, 5 );

	m_listBox5 = new wxListBox( m_panel4, wxID_ANY, wxDefaultPosition, wxSize( 620,200 ), 0, NULL, 0 );
	m_listBox5->Append( wxT("mirko_priv") );
	bSizer14->Add( m_listBox5, 0, wxALL, 5 );


	gSizer1->Add( bSizer14, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );

	m_staticText7 = new wxStaticText( m_panel4, wxID_ANY, wxT("Public keys:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer15->Add( m_staticText7, 0, wxALL, 5 );

	m_listBox6 = new wxListBox( m_panel4, wxID_ANY, wxDefaultPosition, wxSize( 620,200 ), 0, NULL, 0 );
	m_listBox6->Append( wxT("rope_key") );
	m_listBox6->Append( wxT("dimi_key") );
	m_listBox6->Append( wxT("elon_musk") );
	bSizer15->Add( m_listBox6, 0, wxALL, 5 );


	gSizer1->Add( bSizer15, 1, wxEXPAND, 5 );


	bSizer10->Add( gSizer1, 1, wxEXPAND, 5 );


	m_panel4->SetSizer( bSizer10 );
	m_panel4->Layout();
	bSizer10->Fit( m_panel4 );
	menu->AddPage( m_panel4, wxT("Certificates"), false );
	m_panel5 = new wxPanel( menu, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	bSizer7->SetMinSize( wxSize( -1,310 ) );
	m_textCtrl4 = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 620,300 ), wxTE_MULTILINE );
	bSizer7->Add( m_textCtrl4, 0, wxALL, 5 );


	bSizer4->Add( bSizer7, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	bSizer8->SetMinSize( wxSize( -1,15 ) );
	m_button11 = new wxButton( m_panel5, wxID_ANY, wxT("Encrypt"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_button11, 0, wxALL, 5 );

	m_staticText14 = new wxStaticText( m_panel5, wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer8->Add( m_staticText14, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button12 = new wxButton( m_panel5, wxID_ANY, wxT("Decrypt"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_button12, 0, wxALL, 5 );

	m_staticText12 = new wxStaticText( m_panel5, wxID_ANY, wxT("from:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer8->Add( m_staticText12, 0, wxALIGN_CENTER|wxALL, 5 );

	wxString m_choice4Choices[] = { wxT("Clipboard"), wxT("File"), wxT("Notepad") };
	int m_choice4NChoices = sizeof( m_choice4Choices ) / sizeof( wxString );
	m_choice4 = new wxChoice( m_panel5, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice4NChoices, m_choice4Choices, 0 );
	m_choice4->SetSelection( 0 );
	bSizer8->Add( m_choice4, 0, wxALL, 5 );

	m_staticText11 = new wxStaticText( m_panel5, wxID_ANY, wxT("to:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer8->Add( m_staticText11, 0, wxALIGN_CENTER|wxALL, 5 );

	wxString m_choice5Choices[] = { wxT("Clipboard"), wxT("File"), wxT("Notepad") };
	int m_choice5NChoices = sizeof( m_choice5Choices ) / sizeof( wxString );
	m_choice5 = new wxChoice( m_panel5, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice5NChoices, m_choice5Choices, 0 );
	m_choice5->SetSelection( 0 );
	bSizer8->Add( m_choice5, 0, wxALL, 5 );

	m_bpButton1 = new wxBitmapButton( m_panel5, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );
	bSizer8->Add( m_bpButton1, 0, wxALL, 5 );


	bSizer4->Add( bSizer8, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	m_panel5->SetSizer( bSizer4 );
	m_panel5->Layout();
	bSizer4->Fit( m_panel5 );
	menu->AddPage( m_panel5, wxT("Lab"), false );
	m_panel41 = new wxPanel( menu, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	wxGridSizer* gSizer9;
	gSizer9 = new wxGridSizer( 0, 2, 0, 0 );

	m_panel8 = new wxPanel( m_panel41, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel8->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer201;
	bSizer201 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText131 = new wxStaticText( m_panel8, wxID_ANY, wxT("Server side:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText131->Wrap( -1 );
	bSizer201->Add( m_staticText131, 0, wxALL, 5 );


	bSizer18->Add( bSizer201, 1, wxALIGN_CENTER, 5 );

	wxBoxSizer* bSizer211;
	bSizer211 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText161 = new wxStaticText( m_panel8, wxID_ANY, wxT("Server address:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText161->Wrap( -1 );
	bSizer211->Add( m_staticText161, 0, wxALL, 5 );

	m_textCtrl31 = new wxTextCtrl( m_panel8, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 170,-1 ), wxTE_READONLY );
	bSizer211->Add( m_textCtrl31, 0, wxALL, 5 );


	bSizer18->Add( bSizer211, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer221;
	bSizer221 = new wxBoxSizer( wxHORIZONTAL );

	m_button131 = new wxButton( m_panel8, wxID_ANY, wxT("Start Server"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer221->Add( m_button131, 0, wxALL, 5 );

	m_button141 = new wxButton( m_panel8, wxID_ANY, wxT("Share selected keys"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer221->Add( m_button141, 0, wxALL, 5 );


	bSizer18->Add( bSizer221, 1, wxEXPAND, 5 );


	m_panel8->SetSizer( bSizer18 );
	m_panel8->Layout();
	bSizer18->Fit( m_panel8 );
	gSizer9->Add( m_panel8, 1, wxEXPAND | wxALL, 5 );

	m_panel9 = new wxPanel( m_panel41, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel9->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );

	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText13 = new wxStaticText( m_panel9, wxID_ANY, wxT("Client side:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer20->Add( m_staticText13, 0, wxALL, 5 );


	bSizer19->Add( bSizer20, 1, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText16 = new wxStaticText( m_panel9, wxID_ANY, wxT("Server address:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer21->Add( m_staticText16, 0, wxALL, 5 );

	m_textCtrl3 = new wxTextCtrl( m_panel9, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 170,-1 ), 0 );
	bSizer21->Add( m_textCtrl3, 0, wxALL, 5 );


	bSizer19->Add( bSizer21, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );

	m_button13 = new wxButton( m_panel9, wxID_ANY, wxT("Connect"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_button13, 0, wxALL, 5 );

	m_button14 = new wxButton( m_panel9, wxID_ANY, wxT("Import selected keys"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_button14, 0, wxALL, 5 );


	bSizer19->Add( bSizer22, 1, wxEXPAND, 5 );


	m_panel9->SetSizer( bSizer19 );
	m_panel9->Layout();
	bSizer19->Fit( m_panel9 );
	gSizer9->Add( m_panel9, 1, wxEXPAND | wxALL, 5 );


	bSizer9->Add( gSizer9, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );

	wxString m_checkList1Choices[] = { wxT("public_key1"), wxT("public_key2"), wxT("public_key3"), wxT("public_key4") };
	int m_checkList1NChoices = sizeof( m_checkList1Choices ) / sizeof( wxString );
	m_checkList1 = new wxCheckListBox( m_panel41, wxID_ANY, wxDefaultPosition, wxSize( 620,200 ), m_checkList1NChoices, m_checkList1Choices, 0 );
	bSizer17->Add( m_checkList1, 0, wxALL, 5 );


	bSizer9->Add( bSizer17, 1, wxEXPAND, 5 );


	m_panel41->SetSizer( bSizer9 );
	m_panel41->Layout();
	bSizer9->Fit( m_panel41 );
	menu->AddPage( m_panel41, wxT("Hub"), true );
	m_panel7 = new wxPanel( menu, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel7->Hide();

	menu->AddPage( m_panel7, wxT("Chat"), false );
	m_panel6 = new wxPanel( menu, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	m_staticText22 = new wxStaticText( m_panel6, wxID_ANY, wxT("Soon.."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer5->Add( m_staticText22, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxTOP, 150 );


	m_panel6->SetSizer( bSizer5 );
	m_panel6->Layout();
	bSizer5->Fit( m_panel6 );
	menu->AddPage( m_panel6, wxT("Properties"), false );
	m_panel10 = new wxPanel( menu, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel10->Hide();

	menu->AddPage( m_panel10, wxT("MDNetwork"), false );

	bSizer2->Add( menu, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
}

TMenu::~TMenu()
{
}

MyDialog1::MyDialog1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxGridSizer* newKeyGridSizer;
	newKeyGridSizer = new wxGridSizer( 0, 2, 0, 0 );

	wxBoxSizer* newKeyLeftSizer;
	newKeyLeftSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* newKeyLeftTopSizer;
	newKeyLeftTopSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* newKeyNameSizer;
	newKeyNameSizer = new wxBoxSizer( wxHORIZONTAL );

	newKeyNameSizer->SetMinSize( wxSize( -1,40 ) );
	newKeyName = new wxStaticText( this, wxID_ANY, wxT("Name: "), wxDefaultPosition, wxDefaultSize, 0 );
	newKeyName->Wrap( -1 );
	newKeyNameSizer->Add( newKeyName, 0, wxALIGN_CENTER|wxALL, 10 );

	nkNameInput = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 160,-1 ), 0 );
	newKeyNameSizer->Add( nkNameInput, 0, wxALIGN_CENTER|wxALL, 5 );


	newKeyLeftTopSizer->Add( newKeyNameSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* newKeyEmailSizer;
	newKeyEmailSizer = new wxBoxSizer( wxHORIZONTAL );

	newKeyEmailSizer->SetMinSize( wxSize( -1,60 ) );
	newKeyEmail = new wxStaticText( this, wxID_ANY, wxT("Email: "), wxDefaultPosition, wxDefaultSize, 0 );
	newKeyEmail->Wrap( -1 );
	newKeyEmailSizer->Add( newKeyEmail, 0, wxALIGN_CENTER|wxLEFT, 10 );

	nkEmailInput = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 167,-1 ), 0 );
	newKeyEmailSizer->Add( nkEmailInput, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );


	newKeyLeftTopSizer->Add( newKeyEmailSizer, 0, wxLEFT, 5 );

	wxBoxSizer* newKeyTypeSizer;
	newKeyTypeSizer = new wxBoxSizer( wxVERTICAL );

	newKeyTypeSizer->SetMinSize( wxSize( -1,60 ) );
	newKeyType = new wxStaticText( this, wxID_ANY, wxT("Key type and length:"), wxDefaultPosition, wxDefaultSize, 0 );
	newKeyType->Wrap( -1 );
	newKeyTypeSizer->Add( newKeyType, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 10 );

	wxBoxSizer* newKeyChoicesSizer;
	newKeyChoicesSizer = new wxBoxSizer( wxHORIZONTAL );

	wxString nkAlgoChoiceChoices[] = { wxT("RSA") };
	int nkAlgoChoiceNChoices = sizeof( nkAlgoChoiceChoices ) / sizeof( wxString );
	nkAlgoChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 130,-1 ), nkAlgoChoiceNChoices, nkAlgoChoiceChoices, 0 );
	nkAlgoChoice->SetSelection( 0 );
	newKeyChoicesSizer->Add( nkAlgoChoice, 0, wxALIGN_CENTER|wxALL, 5 );

	wxString nkLengthChoiceChoices[] = { wxT("4096") };
	int nkLengthChoiceNChoices = sizeof( nkLengthChoiceChoices ) / sizeof( wxString );
	nkLengthChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 130,-1 ), nkLengthChoiceNChoices, nkLengthChoiceChoices, 0 );
	nkLengthChoice->SetSelection( 0 );
	newKeyChoicesSizer->Add( nkLengthChoice, 0, wxALIGN_CENTER|wxALL, 5 );


	newKeyTypeSizer->Add( newKeyChoicesSizer, 1, wxEXPAND, 5 );


	newKeyLeftTopSizer->Add( newKeyTypeSizer, 1, wxEXPAND, 5 );


	newKeyLeftSizer->Add( newKeyLeftTopSizer, 1, 0, 5 );

	wxBoxSizer* newKeyOkSizer;
	newKeyOkSizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* newKeyOkBSizer;
	newKeyOkBSizer = new wxBoxSizer( wxVERTICAL );

	nkOkButton = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	newKeyOkBSizer->Add( nkOkButton, 0, wxALL, 5 );


	newKeyOkSizer->Add( newKeyOkBSizer, 1, wxALIGN_BOTTOM|wxALL, 15 );


	newKeyLeftSizer->Add( newKeyOkSizer, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	newKeyGridSizer->Add( newKeyLeftSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* newKeyRightSizer;
	newKeyRightSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* newKeyPasswordSizer;
	newKeyPasswordSizer = new wxBoxSizer( wxHORIZONTAL );

	newKeyPasswordSizer->SetMinSize( wxSize( -1,40 ) );
	newKeyPassword = new wxStaticText( this, wxID_ANY, wxT("Passphrase: "), wxDefaultPosition, wxDefaultSize, 0 );
	newKeyPassword->Wrap( -1 );
	newKeyPasswordSizer->Add( newKeyPassword, 0, wxALIGN_CENTER|wxALL, 10 );

	nkPasswordInput = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	nkPasswordInput->SetMinSize( wxSize( 120,-1 ) );

	newKeyPasswordSizer->Add( nkPasswordInput, 0, wxALIGN_CENTER|wxALL, 5 );


	newKeyRightSizer->Add( newKeyPasswordSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* newKeyDateSizer;
	newKeyDateSizer = new wxBoxSizer( wxHORIZONTAL );

	newKeyDateSizer->SetMinSize( wxSize( -1,60 ) );
	newKeyDate = new wxStaticText( this, wxID_ANY, wxT("Expire-Date: "), wxDefaultPosition, wxDefaultSize, 0 );
	newKeyDate->Wrap( -1 );
	newKeyDateSizer->Add( newKeyDate, 0, wxALIGN_CENTER|wxALL, 10 );

	nkDateInput = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	nkDateInput->SetMinSize( wxSize( 120,-1 ) );

	newKeyDateSizer->Add( nkDateInput, 0, wxALIGN_CENTER|wxALL, 5 );


	newKeyRightSizer->Add( newKeyDateSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* newKeyCommentSizer;
	newKeyCommentSizer = new wxBoxSizer( wxVERTICAL );

	newKeyCommentSizer->SetMinSize( wxSize( -1,60 ) );
	newKeyComment = new wxStaticText( this, wxID_ANY, wxT("Name-Comment:"), wxDefaultPosition, wxDefaultSize, 0 );
	newKeyComment->Wrap( -1 );
	newKeyCommentSizer->Add( newKeyComment, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 10 );

	nkCommentInput = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	newKeyCommentSizer->Add( nkCommentInput, 0, wxALL|wxEXPAND, 5 );


	newKeyRightSizer->Add( newKeyCommentSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* newKeyCancelSizer;
	newKeyCancelSizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* newKeyCancelBSizer;
	newKeyCancelBSizer = new wxBoxSizer( wxVERTICAL );

	nkCancelButton = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	newKeyCancelBSizer->Add( nkCancelButton, 0, wxALL, 5 );


	newKeyCancelSizer->Add( newKeyCancelBSizer, 1, wxALIGN_BOTTOM|wxALL, 15 );


	newKeyRightSizer->Add( newKeyCancelSizer, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	newKeyGridSizer->Add( newKeyRightSizer, 1, wxEXPAND, 5 );


	this->SetSizer( newKeyGridSizer );
	this->Layout();

	this->Centre( wxBOTH );
}

MyDialog1::~MyDialog1()
{
}
