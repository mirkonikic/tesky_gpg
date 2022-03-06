///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-40-g8042f487)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
class forward_declare;

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statusbr.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>
#include <wx/srchctrl.h>
#include <wx/sizer.h>
#include <wx/listbox.h>
#include <wx/panel.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/bmpbuttn.h>
#include <wx/checklst.h>
#include <wx/notebook.h>
#include <wx/frame.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class TMenu
///////////////////////////////////////////////////////////////////////////////
class TMenu : public forward_declare
{
	private:

	protected:
		wxMenuBar* m_menubar1;
		wxMenu* m_menu1;
		wxMenu* m_menu2;
		wxMenu* m_menu3;
		wxMenu* m_menu4;
		wxMenu* m_menu5;
		wxMenu* m_menu6;
		wxMenu* m_menu7;
		wxStatusBar* m_statusBar1;
		wxNotebook* menu;
		wxPanel* m_panel4;
		wxButton* m_button7;
		wxStaticText* m_staticText8;
		wxFilePickerCtrl* m_filePicker3;
		wxStaticText* m_staticText9;
		wxSearchCtrl* m_searchCtrl2;
		wxButton* m_button10;
		wxStaticText* m_staticText6;
		wxListBox* m_listBox5;
		wxStaticText* m_staticText7;
		wxListBox* m_listBox6;
		wxPanel* m_panel5;
		wxTextCtrl* m_textCtrl4;
		wxButton* m_button11;
		wxStaticText* m_staticText14;
		wxButton* m_button12;
		wxStaticText* m_staticText12;
		wxChoice* m_choice4;
		wxStaticText* m_staticText11;
		wxChoice* m_choice5;
		wxBitmapButton* m_bpButton1;
		wxPanel* m_panel41;
		wxPanel* m_panel8;
		wxStaticText* m_staticText131;
		wxStaticText* m_staticText161;
		wxTextCtrl* m_textCtrl31;
		wxButton* m_button131;
		wxButton* m_button141;
		wxPanel* m_panel9;
		wxStaticText* m_staticText13;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_textCtrl3;
		wxButton* m_button13;
		wxButton* m_button14;
		wxCheckListBox* m_checkList1;
		wxPanel* m_panel7;
		wxPanel* m_panel6;
		wxStaticText* m_staticText22;
		wxPanel* m_panel10;

	public:

		TMenu( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Tesky v0.46"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 640,480 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL, const wxString& name = wxT("tesky v2.0") );

		~TMenu();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog1
///////////////////////////////////////////////////////////////////////////////
class MyDialog1 : public wxDialog
{
	private:

	protected:
		wxStaticText* newKeyName;
		wxTextCtrl* nkNameInput;
		wxStaticText* newKeyEmail;
		wxTextCtrl* nkEmailInput;
		wxStaticText* newKeyType;
		wxChoice* nkAlgoChoice;
		wxChoice* nkLengthChoice;
		wxButton* nkOkButton;
		wxStaticText* newKeyPassword;
		wxTextCtrl* nkPasswordInput;
		wxStaticText* newKeyDate;
		wxDatePickerCtrl* nkDateInput;
		wxStaticText* newKeyComment;
		wxTextCtrl* nkCommentInput;
		wxButton* nkCancelButton;

	public:

		MyDialog1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Key Generation Menu"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 480,330 ), long style = wxDEFAULT_DIALOG_STYLE );

		~MyDialog1();

};

