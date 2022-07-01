// Program Ch02pr06
// Program to multiply two polynomials

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
		void polymul ( poly &p1, poly &p2 ) ;
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
void poly :: polyadd ( poly &p1, poly &p2 )
{
	int coeff, exp ;
    poly p ;

	int c = p1.noofterms ;
	int d = p2.noofterms ;

	for ( int i = 0, j = 0 ; i <= c || j <= d ; )
	{
		if ( p1.t[i].coeff == 0 && p2.t[j].coeff == 0 )
			break ;
		if ( p1.t[i].exp >= p2.t[j].exp )
		{
			if ( p1.t[i].exp == p2.t[j].exp )
			{
				coeff = p1.t[i].coeff + p2.t[j].coeff ;
				exp = p1.t[i].exp ;
				i++ ;
				j++ ;
			}
			else
			{
				coeff = p1.t[i].coeff ;
				exp = p1.t[i].exp ;
				i++ ;
			}
		}
		else
		{
			coeff = p2.t[j].coeff ;
			exp = p2.t[j].exp ;
			j++ ;
		}
		p.polyappend ( coeff, exp ) ;
	}
	*this = p ;
}

// multiplies two polynomials p1 and p2
void poly :: polymul ( poly &p1, poly &p2 )
{
	int coeff, exp ;
	poly t1, t2 ;

	if ( p1.noofterms != 0 && p2.noofterms != 0 )
	{
		for ( int i = 0 ; i < p1.noofterms ; i++ )
		{
            poly p ;
			for ( int j = 0 ; j < p2.noofterms ; j++ )
			{
				coeff = p1.t[ i ].coeff * p2.t[ j ].coeff ;
				exp = p1.t[ i ].exp + p2.t[ j ].exp ;
				p.polyappend ( coeff, exp ) ;
			}

			if ( i != 0 )
			{
				t2.polyadd ( t1, p ) ;
				t1 = t2  ;
			}
			else
				t1 = p ;
		}

		*this = t2 ;
	}
}

void main( )
{
	poly p1 ;

	p1.polyappend ( 1, 4 ) ;
	p1.polyappend ( 2, 3 ) ;
	p1.polyappend ( 2, 2 ) ;
	p1.polyappend ( 2, 1 ) ;

	poly p2 ;
	p2.polyappend ( 2, 3 ) ;
	p2.polyappend ( 3, 2 ) ;
	p2.polyappend ( 4, 1 ) ;

	poly p3 ;
	p3.polymul( p1, p2 ) ;

	cout << endl << "First polynomial: " << endl  ;
	p1.display( ) ;

	cout << endl << "Second polynomial: " << endl ;
	p2.display( ) ;

	cout << endl << "Resultant polynomial: " << endl ;
	p3.display( ) ;
}