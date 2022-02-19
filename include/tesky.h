#ifndef __TESKY_H__
#define __TESKY_H__

//[1] INCLUDES:

#include <ostream>

#include <gpgme.h>	//interface to gnupg

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/clipbrd.h>
//#include "mondrian.xpm"

//include classes	
#include "tmenu.h"	//main menu when application opens

//[2] APPLICATION CLASS:

class TeskyApp : public wxApp
{
	public:
		virtual bool OnInit();
};

DECLARE_APP(TeskyApp)

//id brojevi za svaki event koji moze da se dogodi
enum
{
	ID_Hello = 1
};

class TMenu : public wxFrame
{
public:
	//Constructor
	TMenu(const wxString& title);

	//Event Handlers
		//File
	void OnQuit(wxCommandEvent& event);
		//View
		//Certificates
		//Tools
		//Settings
		//Window
		//Help
	void OnAboutTesky(wxCommandEvent& event);
	void OnAboutMirko(wxCommandEvent& event);
	void ClImport(wxCommandEvent& event);

private:
	DECLARE_EVENT_TABLE()
};

//static event table
BEGIN_EVENT_TABLE(TMenu, wxFrame)
	EVT_MENU(ID_Hello, TMenu::ClImport)
	EVT_MENU(wxID_ABOUT, TMenu::OnAboutTesky)
	EVT_MENU(wxID_EXIT, TMenu::OnQuit)
END_EVENT_TABLE()

#endif

//Main Screen when opened
//	1. Top Menu
//		-File
//			.NewKeyPair
//			.Import..
//			.Export..
//			.PrintSecretKey
//			.Decrypt/Verify
//			.Encrypt/Sign
//			.CreateCheksumFiles
//			.VerifyChecksumFiles
//			.Close
//			.Quit
//		-View
//			.Certificates
//			.Notepad
//			.Smartcards
//		-Certificates
//		-Tools
//			.Clipboard
//				->Import
//				->Encrypt
//				->Decrypt
//		-Settings
//		-Window
//		-Help
//			.About Tesky
//			.About Mirko

//Three Panels, with three top buttons
//on first panel you can upload your priv key