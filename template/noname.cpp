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


	m_panel4->SetSizer( bSizer10 );
	m_panel4->Layout();
	bSizer10->Fit( m_panel4 );
	menu->AddPage( m_panel4, wxT("Certificates"), false );
	m_panel5 = new wxPanel( menu, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );


	m_panel5->SetSizer( bSizer4 );
	m_panel5->Layout();
	bSizer4->Fit( m_panel5 );
	menu->AddPage( m_panel5, wxT("Notepad"), false );
	m_panel6 = new wxPanel( menu, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );


	m_panel6->SetSizer( bSizer5 );
	m_panel6->Layout();
	bSizer5->Fit( m_panel6 );
	menu->AddPage( m_panel6, wxT("Settings"), true );

	bSizer2->Add( menu, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
}

TMenu::~TMenu()
{
}
