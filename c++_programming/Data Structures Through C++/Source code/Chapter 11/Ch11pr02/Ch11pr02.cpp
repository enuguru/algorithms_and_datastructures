// Ch11pr02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Ch11pr02.h"

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
		char *names[ ] = { 
							"Subhash", 
							"Rahul",
							"John",
							"Sanjay",
							"Vishal"
						} ;

		CStringList str ;

		// adds items to str
		for ( int i = 0 ; i <= 4 ; i++ ) 
			str.AddTail ( names[i] ) ;

		POSITION p ;
		p = str.GetHeadPosition( ) ;

		// displays items
		CString s ;
		cout << "Items of str: " << endl ;
		while ( p != NULL )
		{
			s = str.GetNext ( p ) ;
			cout << ( const char * ) s << "  " ;
		}
		cout << endl ;

		// Changes an item in the list
		p = str.Find ( "John" ) ;
		str.SetAt ( p, "Neha" ) ;
		cout << ( const char * )str.GetAt ( p ) << endl ;

		// inserts an item at end
		p = str.GetTailPosition( ) ;
		str.InsertAfter ( p, "Manish" ) ;
		str.InsertBefore ( p, "Kiran" ) ;

		// removes item at the head node
		p = str.GetHeadPosition( ) ;
		str.RemoveAt ( p ) ;

		// displays items
		cout << "Items in str now: " << endl ;
		p = str.GetHeadPosition( ) ;
		while ( p != NULL )
		{
			s = str.GetNext ( p ) ;
			cout << ( const char * ) s << "  " ;
		}
		cout << endl ;
	}

	return nRetCode;
}


