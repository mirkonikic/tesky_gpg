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

private:
	DECLARE_EVENT_TABLE()
};

//static event table
BEGIN_EVENT_TABLE(TMenu, wxFrame)
	EVT_MENU(wxID_ABOUT, TMenu::OnAboutTesky)
	EVT_MENU(wxID_EXIT, TMenu::OnQuit)
END_EVENT_TABLE()
