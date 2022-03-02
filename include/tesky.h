// Name:	tesky App
// Purpose:	GPG encryption tool with advanced options
// Author:	Mirko Nikic
// Requirements: gpgme 1.14.0-unknown; wx-config 3.0.5
// Credits: 

#ifndef __TESKY_H__
#define __TESKY_H__

//[1] INCLUDES:
//PROBLEM JER common_lib -> aarch.h
//PROBLEM JER aarch.cpp  -> aarch.h
//ZATO SU GLOBAL VARIABLES FROWNED UPON
#include "common_lib.h"	//CROSS-PLATFORM HEADERS

#include <ostream>

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
	//File
	ID_NewKeyPair = 1,
	ID_Import,
	ID_Export,
	ID_PrintSecretKey,
	ID_Encrypt,
	ID_Decrypt,
	ID_CreateCheksumFiles,
	ID_VerifyChecksumFiles,
	ID_Close,
	//View
	ID_Refresh,
	ID_CertDetails,
	ID_Certificates,
	ID_Notepad,
	ID_Hub,
	ID_Chat,
	//Certificates
	//Tools
	ID_LogViewer,
	ID_ClImport,
	ID_ClEncrypt,
	ID_ClDecrypt,
	//Settings
	ID_SelfTest,
	//Window
	//Help
	ID_About_Mirko,
	//TaskBar-SystemTrayIcon - Icon - Open/SelectCert/ClEncrypt/CleDecrypt/About
	//PanelCertificates - Import/Export/New Certificates
	ID_certNewKey,	//creates new key pair for user
	ID_certOK,		//handles file picker input and search bar
	ID_certPrivKeysList,
	ID_certPubKeysList,
	ID_certImportKeysFile,
	//PanelNotepad - File or Text encryption
	ID_ntpdPubKeysChoice,
	ID_ntpdPrivKeysChoice,
	ID_ntpdClImport,
	ID_ntpdEncrypt,
	ID_ntpdDecrypt,
	ID_ntpdChainButton,
	//PanelHub - Server/Client for key downloading
	ID_hubStartServer,
	ID_hubShareKeys,
	ID_hubConnectClient,
	ID_hubImportKeys,
	//PanelProperties - Setting properties for program
	//PanelChat - you can chat with selected certificate :)
};

class TMenu : public wxFrame
{
public:
	//Constructor
	TMenu(const wxString& title);

	//Variables
		//Notebook
		wxNotebook* notebook;
			//Notepad
			wxTextCtrl* notepadTextBox;
			//Certificates
			wxFilePickerCtrl* importKeysFile;
			wxListBox* privKeysList;
			wxListBox* pubKeysList;
			//Notepad
			wxBitmapButton* chainEncryption;
			bool chain_enabled = false;
			const wxBitmap chained;
			const wxBitmap unchained;
			//wxChoice* choiceList;
				//updatedNotepad
				wxChoice* fromChoices;
				wxChoice* toChoices;
			//SystemTray
			wxTaskBarIcon   *m_taskBarIcon;

	//Event Handlers
	//MenuBar
		//File
	void OnNewKeyPair(wxCommandEvent& event);
	void OnImport(wxCommandEvent& event);
	void OnExport(wxCommandEvent& event);
	void OnPrintSecretKey(wxCommandEvent& event);
	void OnEncrypt(wxCommandEvent& event);
	void OnDecrypt(wxCommandEvent& event);
	void OnCreateCheksumFiles(wxCommandEvent& event);
	void OnVerifyChecksumFiles(wxCommandEvent& event);
	void OnClose(wxCommandEvent& event);
	void OnQuit(wxCommandEvent& event);
		//View
	void OnRefresh(wxCommandEvent& event);
	void OnCertDetails(wxCommandEvent& event);
	void OnCertificates(wxCommandEvent& event);
	void OnNotepad(wxCommandEvent& event);
	void OnHub(wxCommandEvent& event);
	void OnChat(wxCommandEvent& event);
		//Certificates
		//Tools
	void OnLogViewer(wxCommandEvent& event);
	void OnClImport(wxCommandEvent& event);
	void OnClEncrypt(wxCommandEvent& event);
	void OnClDecrypt(wxCommandEvent& event);
		//Settings
	void OnSelfTest(wxCommandEvent& event);
		//Window
		//Help
	void OnAbout_Mirko(wxCommandEvent& event);
	void OnAbout_Tesky(wxCommandEvent& event);
	//Notebook
		//Certificates
	void OnPrivKeysListSelect(wxCommandEvent& event);
	void OnPubKeysListSelect(wxCommandEvent& event);
	void OncertNewKey(wxCommandEvent& event);
	void OncertOK(wxCommandEvent& event);
	void OncertImportKeysFile(wxFileDirPickerEvent& event);
		//Notepad
	void OnPubKeysChoiceSelect(wxCommandEvent& event);
	void OnPrivKeysChoiceSelect(wxCommandEvent& event);
	void OnNtpdEncrypt(wxCommandEvent& event);
	void OnNtpdDecrypt(wxCommandEvent& event);
	void OnNtpdChainClick(wxCommandEvent& event);
		//Hub
	void OnhubStartServer(wxCommandEvent& event);
	void OnhubShareKeys(wxCommandEvent& event);
	void OnhubConnectClient(wxCommandEvent& event);
	void OnhubImportKeys(wxCommandEvent& event);
		//Chat
		//Properties
		//MDNetwork
		//Public/Private key methods
	void OnPublicKeyChangeUpdateGUI();
	void OnPrivateKeyChangeUpdateGUI();
	void OnPublicResetGUI();
	void OnPrivateResetGUI();
	void init_GUI();
	void UpdateGUI();

private:
	DECLARE_EVENT_TABLE()
};

//static event table
BEGIN_EVENT_TABLE(TMenu, wxFrame)
//MenuBar
	//File
	EVT_MENU(ID_NewKeyPair, TMenu::OnNewKeyPair)
	EVT_MENU(ID_Import, TMenu::OnImport)
	EVT_MENU(ID_Export, TMenu::OnExport)
	EVT_MENU(ID_PrintSecretKey, TMenu::OnPrintSecretKey)
	EVT_MENU(ID_Encrypt, TMenu::OnEncrypt)
	EVT_MENU(ID_Decrypt, TMenu::OnDecrypt)
	EVT_MENU(ID_CreateCheksumFiles, TMenu::OnCreateCheksumFiles)
	EVT_MENU(ID_VerifyChecksumFiles, TMenu::OnVerifyChecksumFiles)
	EVT_MENU(ID_Close, TMenu::OnClose)
	EVT_MENU(wxID_EXIT, TMenu::OnQuit)
	//View
	EVT_MENU(ID_Refresh, TMenu::OnRefresh)
	EVT_MENU(ID_CertDetails, TMenu::OnCertDetails)
	EVT_MENU(ID_Certificates, TMenu::OnCertificates)
	EVT_MENU(ID_Notepad, TMenu::OnNotepad)
	EVT_MENU(ID_Hub, TMenu::OnHub)
	EVT_MENU(ID_Chat, TMenu::OnChat)
	//Settings
	//Tools
	EVT_MENU(ID_LogViewer, TMenu::OnLogViewer)
	EVT_MENU(ID_ClImport, TMenu::OnClImport)
	EVT_MENU(ID_ClEncrypt, TMenu::OnClEncrypt)
	EVT_MENU(ID_ClDecrypt, TMenu::OnClDecrypt)
	//Settings
	EVT_MENU(ID_SelfTest, TMenu::OnSelfTest)
	//Window
	//Help
	EVT_MENU(wxID_ABOUT, TMenu::OnAbout_Tesky)
	EVT_MENU(ID_About_Mirko, TMenu::OnAbout_Mirko)
//Notebook
	//Certificates
		EVT_BUTTON(ID_certNewKey, TMenu::OncertNewKey)
		EVT_BUTTON(ID_certOK, TMenu::OncertOK)
		EVT_LISTBOX(ID_certPrivKeysList, TMenu::OnPrivKeysListSelect)
		EVT_LISTBOX(ID_certPubKeysList, TMenu::OnPubKeysListSelect)
		EVT_FILEPICKER_CHANGED(ID_certImportKeysFile, TMenu::OncertImportKeysFile)
	//Notepad
		EVT_CHOICE(ID_ntpdPubKeysChoice, TMenu::OnPubKeysChoiceSelect)
		//EVT_CHOICE(ID_ntpdPrivKeysChoice, TMenu::OnPrivKeysChoiceSelect)
		EVT_BUTTON(ID_ntpdClImport, TMenu::OnClImport)
		EVT_BUTTON(ID_ntpdEncrypt, TMenu::OnNtpdEncrypt)
		EVT_BUTTON(ID_ntpdDecrypt, TMenu::OnNtpdDecrypt)
		EVT_BUTTON(ID_ntpdChainButton, TMenu::OnNtpdChainClick)
	//Hub
		EVT_BUTTON(ID_hubStartServer, TMenu::OnhubStartServer)
		EVT_BUTTON(ID_hubShareKeys, TMenu::OnhubShareKeys)
		EVT_BUTTON(ID_hubConnectClient, TMenu::OnhubConnectClient)
		EVT_BUTTON(ID_hubImportKeys, TMenu::OnhubImportKeys)
	//Chat
	//Properties
	//MDNetwork
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