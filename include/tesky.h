#ifndef __TESKY_H__
#define __TESKY_H__

//[1] INCLUDES:

#include <ostream>

//interface to gnupg
#include <gpgme.h>

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

//include classes	




//[2] APPLICATION CLASS:

class TeskyApp: public wxApp
{
	public:
		virtual bool OnInit();
};

DECLARE_APP(TeskyApp)

#endif
