// sortstr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sortstr.h"

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

		CStringList list ;
		list.AddTail ( "Sanjay" ) ;
		list.AddTail ( "Kunal" ) ;
		list.AddTail ( "Bina" ) ;
		list.AddTail ( "Rahul" ) ;
		list.AddTail ( "Aditi" ) ;

		CString l1, l2 ;
		POSITION p1, p2 ;

		int count = list.GetCount( ) ;
		
		for ( int  j = count - 1 ; j > 0 ; j-- )
		{
			p1 = list.GetHeadPosition( ) ;
			for ( int  i = 0 ; i < j ; i++ )
			{
				p2 = p1 ;
				l1 = list.GetNext ( p1 ) ;
				l2 = list.GetAt ( p1 ) ;
				if ( l1 > l2 )
				{
					list.SetAt ( p2, l2 ) ;
					list.SetAt ( p1, l1 ) ;
				}
			}
		}
		p1 = list.GetHeadPosition( ) ;
		l1="";
		for ( j = 0 ; j < count ; j++ )
			cout << ( LPCTSTR ) list.GetNext ( p1 ) << endl ;
	}

	return nRetCode;
}


