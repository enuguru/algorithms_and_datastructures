// Ch11pr01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Ch11pr01.h"

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
		CUIntArray  arr1 ;
		arr1.SetSize ( 5 ) ;
		cout << "\nElements in arr1: " << endl ;
		for ( int  i = 0 ; i < 5 ; i++ )
		{
			arr1[i] = i + 1 ;
			cout << arr1[i] << " " ;
		}
		cout << endl ;

		// determines the number of elements
		int  size = arr1.GetSize( ) ;
		cout << "\nSize of Array arr1: " << size << endl ;

		// determines the maximum index
		int  ub = arr1.GetUpperBound( ) ;
		cout << "\nUpper bound of arr1: " << ub << endl ;

		// extracts an element from the specified position
		UINT  item = arr1.GetAt ( 2 ) ;
		cout << "\nElement at 2: " << item << endl ;

		// sets an element at the specified position
		arr1.SetAt ( 3, 99 ) ;
		item = arr1.GetAt ( 3 ) ;
		cout << "\nNew item at 3: " << item << endl ;

		// inserts an element at the specified position
		arr1.InsertAt ( 2, 100 ) ;
		cout << "\nNew Elements of arr1: " << endl ;
		for ( i = 0 ; i <= arr1.GetUpperBound( ) ; i++ )
			cout << arr1[i] << " " ;
		cout << endl ;

		// deletes an element from the specified position
		arr1.RemoveAt ( 3, 2 ) ;
		cout  <<  "\nArray arr1 After Removing: " << endl ;
		for ( i = 0 ; i <= arr1.GetUpperBound( ) ; i++ )
			cout << arr1[i ] << " " ;
		cout << endl ;

		// appends a new array to the existing array
		CUIntArray  arr2 ; 	
		arr2.SetSize ( 5 ) ;
		for ( i = 0 ; i < 5 ; i++ )
			arr2[i] = i + 50 ;

		arr1.Append ( arr2 ) ;
		cout << "\nResultant array: " << endl ;
		for ( i = 0 ; i <= arr1.GetUpperBound( ) ; i++ )
			cout << arr1[ i ] << " " ;
		cout << endl ;

		// copies one array to another
		CUIntArray arr3 ;
		arr3.SetSize ( size ) ;
		arr3.Copy ( arr1 ) ;

		// displays elements in arr3
		cout << "\nElements in arr3: " << endl ;
		for ( i = 0 ; i <= arr3.GetUpperBound( ) ; i++ )
			cout << arr3[i] << " " ;
		cout << endl ;

		// removes all elements from the array
		arr1.RemoveAll( ) ; 	
		arr2.RemoveAll( ) ;
		size = arr1.GetSize( ) ;
		cout << "\nSize of Array arr1: " << size << endl ;
	}
	return nRetCode;
}


