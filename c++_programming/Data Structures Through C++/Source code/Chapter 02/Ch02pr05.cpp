// Program Ch02pr05
// Program to Add two polynomials

#include <iostream.h>

const int MAX = 10 ;

class poly
{
	private :

		struct term
		{
			int coeff ;
			int exp ;
		} t[MAX] ;
		int noofterms ;

	public :

		poly( ) ;
		void polyappend ( int c, int e ) ;
		void polyadd ( poly &p1, poly &p2 ) ;
		void display( ) ;
} ;

// initializes data members of class poly
poly :: poly( )
{
	noofterms = 0 ;
	for ( int i = 0 ; i < MAX ; i++ )
	{
		t[i].coeff = 0 ;
		t[i].exp = 0 ;
	}
}

// adds the term of polynomial to the array t
void poly :: polyappend ( int c, int e )
{
	t[noofterms].coeff = c ;
	t[noofterms].exp =  e ;
	noofterms++ ;
}

// displays the polynomial equation
void poly :: display( )
{
	int flag = 0 ;
	for ( int i = 0 ; i < noofterms ; i++ )
	{
		if ( t[i].exp != 0 )
			cout << t[i].coeff << "x^" << t[i].exp  << " + " ;
		else
		{
			cout << t[i].coeff ;
			flag = 1 ;
		}
	}
	if ( !flag )
		cout << "\b\b  " ;
}

// adds two polynomials p1 and p2
void poly :: polyadd ( poly& p1, poly& p2 )
{
	int c = p1.noofterms > p2.noofterms ? p1.noofterms : p2.noofterms ;

	for ( int i = 0, j = 0 ; i <= c ; noofterms++ )
	{
		if ( p1.t[i].coeff == 0 && p2.t[j].coeff == 0 )
			break ;
		if ( p1.t[i].exp >= p2.t[j].exp )
		{
			if ( p1.t[i].exp == p2.t[j].exp )
			{
				t[noofterms].coeff = p1.t[i].coeff + p2.t[j].coeff ;
				t[noofterms].exp = p1.t[i].exp ;
				i++ ;
				j++ ;
			}
			else
			{
				t[noofterms].coeff = p1.t[i].coeff ;
				t[noofterms].exp = p1.t[i].exp ;
				i++ ;
			}
		}
		else
		{
			t[noofterms].coeff = p2.t[j].coeff ;
			t[noofterms].exp = p2.t[j].exp ;
			j++ ;
		}
	}
}

void main( )
{
	poly p1 ;

	p1.polyappend ( 1, 7 ) ;
	p1.polyappend ( 2, 6 ) ;
	p1.polyappend ( 3, 5 ) ;
	p1.polyappend ( 4, 4 ) ;
	p1.polyappend ( 5, 2 ) ;

	poly p2 ;
	p2.polyappend ( 1, 4 ) ;
	p2.polyappend ( 1, 3 ) ;
	p2.polyappend ( 1, 2 ) ;
	p2.polyappend ( 1, 1 ) ;
	p2.polyappend ( 2, 0 ) ;

	poly p3 ;
	p3.polyadd ( p1, p2 ) ;

	cout << endl << "First polynomial:" << endl  ;
	p1.display( ) ;

	cout << endl << "Second polynomial:" << endl ;
	p2.display( ) ;

	cout << endl << "Resultant polynomial:" << endl ;
	p3.display( ) ;
}