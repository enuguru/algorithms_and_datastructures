// Sorting of a sturcture on multiple keys

#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

const int MAX = 5 ;

class student
{

	private :


		struct stud
		{
			char name[25] ;
			int age ;
			float height ;
		} s[5], temp ;

	public :

		void getdata( ) ;
		void sort( ) ;
		void display( ) ;
} ;

// accepts data for 5 students
void student :: getdata( )
{
	cout << endl ;
	for ( int i = 0 ; i < MAX ; i++ )
	{
		cout << "\nStudent's Name: " ;
		gets ( s[i].name ) ;
		cout << "\nStudent's Age: " ;
		cin >> s[i].age ;
		cout << "\nStudent's Height: " ;
		cin >> s[i].height ;
	}
}


// sorts data as per key value
void student :: sort( )
{
	for ( int i = 0 ; i < MAX - 2 ; i++ )
	{
		for ( int j = 0 ; j < ( MAX - 2 ) - i ; j++ )
		{
			if ( strcmp ( s[j].name, s[j + 1].name ) >= 0 )
			{
				if ( strcmp ( s[j].name, s[j + 1].name ) == 0 )
				{
					if ( s[j].age > s[j + 1].age )
					{
						temp = s[j] ;
						s[j] = s[j + 1] ;
						s[j + 1] = temp ;
					}
				}
				else
				{
					temp = s[j] ;
					s[j] = s[j + 1] ;
					s[j + 1] = temp ;
				}
			}
		}
	}
}	

// displays sorted data
void student :: display( )
{
	cout << "\nRecords after sorting :-\n" ;
	cout << "Students Name\tAge\tHeight\n" ;
	for ( int i = 0 ; i < MAX ; i++ )
	{
		cout << s[i].name << "\t\t"
		     << s[i].age << "\t\t"
		     << s[i].height ;
		cout << endl ;
	}
}


void main( )
{
	clrscr( ) ;

	student s ;
	s.getdata( ) ;
	s.sort( ) ;
	s.display( ) ;
}
