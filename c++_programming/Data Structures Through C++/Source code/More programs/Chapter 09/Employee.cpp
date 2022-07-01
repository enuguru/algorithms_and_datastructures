// Sorting of a structure on names using bubble sort
// qsort

#include <iostream.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

const int MAX = 5 ;

class employee
{

	private :

		struct emp
		{
			char empid[7] ;
			char name[25] ;
			int age ;
			float sal ;
		} e[5] ;
		char id[5][7] ;

	public :

		void getdata( ) ;
		void sortdata( ) ;
		void display( ) ;
} ;


// accepts data for employees
void employee :: getdata( )
{
	for ( int i = 0 ; i < MAX ; i++ )
	{
		cout << "\nEmployee Id: " ;
		cin >> e[i].empid ;
		cout << "\nEmployee Name: " ;
		cin >> e[i].name ;
		cout << "\nEmployee Age: " ;
		cin >> e[i].age ;
		cout << "\nEmployee Salary: " ;
		cin >> e[i].sal ;

		strcpy ( id[i], e[i].empid ) ;
	}
}

// sorts employee data
void employee :: sortdata( )
{
	char temp[7] ;

	for ( int i = 0 ; i <= MAX - 2 ; i++ )
	{
		for ( int j = 0 ; j <= MAX - 2 - i ; j++ )
		{
			if ( strcmp ( id[j], id[j + 1] ) > 0 )
			{
				strcpy ( temp, id[j] ) ;
				strcpy ( id[j], id[j + 1] ) ;
				strcpy ( id[j + 1], temp ) ;
			}
		}
	}
}

// displays employee data
void employee :: display( )
{
	cout << "\nRecords after sorting" ;
	cout << "\nName, age and salary after sorting :-\n" ;
	for ( int i = 0 ; i < MAX ; i++ )
	{
		for ( int j = 0 ; j < MAX ; j++ )
		{
			if ( strcmp( id[i], e[j].empid ) == 0 )
            {
				cout << e[j].empid << "  "
				     << e[j].name << "  "
				     << e[j].age << "  "
				     << e[j].sal ;
                cout << endl ;
            }
		}
	}
}


void main( )
{
	clrscr( ) ;

	employee e ;

	e.getdata( ) ;
	e.sortdata( ) ;
	e.display( ) ;
}