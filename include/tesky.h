// Name:	tesky App
// Purpose:	GPG encryption tool with advanced options
// Author:	Mirko Nikic
// Credits: 

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
#include <wx/notebook.h>
#include <wx/taskbar.h>
#include <wx/filepicker.h>
#include <wx/srchctrl.h>
#include <wx/textctrl.h>

#include "icon.xpm"
//include classes	
//#include "tmenu.h"	//main menu when application opens

//[3] VARIABLES:
//globalna varijabla za izabran kljuc sa kojim poslujemo
//int *pub_key;
//preprocesor za lokaciju baza itd
//folder sa kljucevima


//[4] STRUCTS

/*
typedef struct private_key privkey
{
	...
}
*/

/*
typedef struct public_key pubkey
{
	int id;
	pubkey *next;
};
*/

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
	//MenuBar
	ID_ClImport = 1,
	ID_NewKeyPair,
	ID_Import,
	ID_Export,
	ID_PrintSecretKey,
	ID_Decrypt,
	ID_Verify,
	ID_Encrypt,
	ID_Sign,
	ID_CreateCheksumFiles,
	ID_VerifyChecksumFiles,
	ID_Close,
	ID_Quit,
	ID_View,
	ID_Notepad,
	ID_Smartcards,
	ID_Certificates,
	ID_Tools,
	ID_Clipboard,
	ID_ClEncrypt,
	ID_ClDecrypt,
	ID_Settings,
	ID_Window,
	ID_Help,
	ID_About_Tesky,
	ID_About_Mirko,
	//TaskBar-SystemTrayIcon - Icon - Open/SelectCert/ClEncrypt/CleDecrypt/About
	//PanelCertificates - Import/Export/New Certificates
	//PanelHub - Server/Client for key downloading
	//PanelNotepad - File or Text encryption
	//PanelProperties - Setting properties for program
	//PanelChat - you can chat with selected certificate :)
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

	wxTaskBarIcon   *m_taskBarIcon;


private:
	DECLARE_EVENT_TABLE()
};

//static event table
BEGIN_EVENT_TABLE(TMenu, wxFrame)
	EVT_MENU(ID_ClImport, TMenu::ClImport)
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