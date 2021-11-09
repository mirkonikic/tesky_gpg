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

#endif
