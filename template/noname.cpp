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
	menu->AddPage( m_panel4, wxT("a page"), false );
	m_panel5 = new wxPanel( menu, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );


	m_panel5->SetSizer( bSizer4 );
	m_panel5->Layout();
	bSizer4->Fit( m_panel5 );
	menu->AddPage( m_panel5, wxT("a page"), false );
	m_panel6 = new wxPanel( menu, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );


	m_panel6->SetSizer( bSizer5 );
	m_panel6->Layout();
	bSizer5->Fit( m_panel6 );
	menu->AddPage( m_panel6, wxT("a page"), true );

	bSizer2->Add( menu, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
}

TMenu::~TMenu()
{
}
