// Ch11pr03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Ch11pr03.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		CMapStringToString m ;
		m["Sunday"] = "Itwar" ;
		m["Monday"] = "Somwar" ;
		m["Tuesday"] = "Mangalwar" ;
		m["Wednesday"] = "Budhwar" ;
		m["Thursday"] = "Guruwar" ;
		m["Friday"] = "Shukrawar" ;
		m["Saturday"] = "Shaniwar" ;

		CString s ;
		if ( m.Lookup ( "Wednesday", s ) ) 
			cout << "Wednesday in Hindi is " << ( const char * ) s << endl ;
		cout << endl ;

		POSITION p ;
		p = m.GetStartPosition( ) ;

		CString key, item ;
		cout << "Items in the map: " << endl ;
		while ( p != NULL ) 
		{
			m.GetNextAssoc ( p, key, item ) ;
			cout << "key = " << ( const char * ) key << "   " << "item = " << ( const char * ) item << endl ;
		}
		cout << endl ;

	}

	return nRetCode;
}


