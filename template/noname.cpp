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
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	bSizer7->SetMinSize( wxSize( -1,310 ) );
	m_richText2 = new wxRichTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxVSCROLL|wxHSCROLL|wxNO_BORDER|wxWANTS_CHARS );
	m_richText2->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer7->Add( m_richText2, 1, wxEXPAND | wxALL, 5 );


	bSizer4->Add( bSizer7, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	bSizer8->SetMinSize( wxSize( -1,15 ) );
	m_button1 = new wxButton( m_panel5, wxID_ANY, wxT("Encrypt"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_button1, 0, wxALL, 5 );

	m_button2 = new wxButton( m_panel5, wxID_ANY, wxT("Decrypt"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_button2, 0, wxALL, 5 );

	m_button3 = new wxButton( m_panel5, wxID_ANY, wxT("Load from clipboard"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_button3, 0, wxALL, 5 );

	wxString m_choice1Choices[] = { wxT("Mirko"), wxT("dimi"), wxT("rope") };
	int m_choice1NChoices = sizeof( m_choice1Choices ) / sizeof( wxString );
	m_choice1 = new wxChoice( m_panel5, wxID_ANY, wxDefaultPosition, wxSize( 220,-1 ), m_choice1NChoices, m_choice1Choices, 0 );
	m_choice1->SetSelection( 1 );
	bSizer8->Add( m_choice1, 0, wxALL, 5 );


	bSizer4->Add( bSizer8, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	m_panel5->SetSizer( bSizer4 );
	m_panel5->Layout();
	bSizer4->Fit( m_panel5 );
	menu->AddPage( m_panel5, wxT("Notepad"), false );
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

	bSizer2->Add( menu, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
}

TMenu::~TMenu()
{
}
