// Program Ch04pr14
// Program to add two polynomials maintained as linked lists.

#include <iostream.h>

class poly
{
	private :

		// structure containing data part and link part
		struct polynode
		{
			float coeff ;
			int exp ;
			polynode *link ;
		} *p ;

	public :

		poly( ) ;
		void poly_append ( float c, int e ) ;
		void display_poly( ) ;
		void poly_add( poly &l1, poly &l2 ) ;
		~poly( ) ;
} ;

// initializes data member
poly :: poly( )
{
	p = NULL ;
}

// adds a term to a polynomial
void poly :: poly_append ( float c, int e )
{
	polynode *temp = p ;

	// creates a new node if the list is empty
	if ( temp == NULL )
	{
		temp = new polynode ;
		p = temp ;
	}
	else
	{
		// traverse the entire linked list
		while ( temp -> link != NULL )
			temp = temp -> link ;

		// create new nodes at intermediate stages
		temp -> link = new polynode ;
		temp = temp -> link ;
	}

	// assign coefficient and exponent
	temp -> coeff = c ;
	temp -> exp = e ;
	temp -> link = NULL ;
}

// displays the contents of linked list representing a polynomial
void poly :: display_poly( )
{
	polynode *temp = p ;
	int f = 0 ;

	cout << endl ;
	// traverse till the end of the linked list
	while ( temp != NULL )
	{
		if ( f != 0 )
		{
			// display sign of a term
			if ( temp -> coeff > 0 )
				cout << " + " ;
			else
				cout << " " ;
		}
		if ( temp -> exp != 0 )
			cout << temp -> coeff << "x^" << temp -> exp ;
		else
			cout << temp -> coeff ;
		temp = temp -> link ;
		f = 1 ;
	}
}

// adds two polynomials
void poly :: poly_add ( poly &l1, poly &l2 )
{
	polynode *z ;

	// if both linked lists are empty
	if ( l1.p == NULL && l2.p == NULL )
		return ;

	// traverse till one of the list ends
	polynode *temp1, *temp2 ;
	temp1 = l1.p ;
	temp2 = l2.p ;

	while ( temp1 != NULL && temp2 != NULL )
	{
		// create a new node if the list is empty
		if ( p == NULL )
		{
			p = new polynode ;
			z = p ;
		}

		// create new nodes at intermediate stages
		else
		{
			z -> link = new polynode ;
			z = z -> link ;
		}

		// store a term of the larger degree polynomial
		if ( temp1 -> exp < temp2 -> exp )
		{
			z -> coeff = temp2 -> coeff ;
			z -> exp = temp2 -> exp ;

			// go to the next node
			temp2 = temp2 -> link ;
		}
		else
		{
			if ( temp1 -> exp > temp2 -> exp )
			{
				z -> coeff = temp1 -> coeff ;
				z -> exp = temp1 -> exp ;

				// go to the next node
				temp1 = temp1 -> link ;
			}
			else
			{
				// add the coefficients, when exponents are equal
				if ( temp1 -> exp == temp2 -> exp )
				{
					// assigning the added coefficient
					z -> coeff = temp1 -> coeff + temp2 -> coeff ;
					z -> exp = temp1 -> exp ;

					// go to the next node
					temp1 = temp1 -> link ;
					temp2 = temp2 -> link ;
				}
			}
		}
	}

	// assign remaining terms of the
	// first polynomial to the result
	while ( temp1 != NULL )
	{
		if ( p == NULL )
		{
			p = new polynode ;
			z = p ;
		}
		else
		{
			z -> link = new polynode ;
			z = z -> link ;
		}

		// assign coefficient and exponent
		z -> coeff = temp1 -> coeff ;
		z -> exp = temp1 -> exp ;

		// go to the next node
		temp1 = temp1 -> link ;
	}

	// assign remaining terms of
	// second polynomial to the result
	while ( temp2 != NULL )
	{
		if ( p == NULL )
		{
			p = new polynode ;
			z = p ;
		}
		else
		{
			z -> link = new  polynode ;
			z = z -> link ;
		}

		// assign coefficient and exponent
		z -> coeff = temp2 -> coeff ;
		z -> exp = temp2 -> exp ;

		// go to the next node
		temp2 = temp2 -> link ;
	}

	// assign NULL at end of resulting linked list
	z -> link = NULL ;
}

// deallocates memory
poly :: ~poly( )
{
	polynode *q ;

	while ( p != NULL )
	{
		q = p -> link ;
		delete p ;
		p = q ;
	}
}

void main( )
{
	poly p1 ;

	p1.poly_append ( 1.4, 5 ) ;
	p1.poly_append ( 1.5, 4 ) ;
	p1.poly_append ( 1.7, 2 ) ;
	p1.poly_append ( 1.8, 1 ) ;
	p1.poly_append ( 1.9, 0 ) ;

	cout << "\nFirst polynomial:" ;
	p1.display_poly( ) ;

	poly p2 ;
	
	p2.poly_append ( 1.5, 6 ) ;
	p2.poly_append ( 2.5, 5 ) ;
	p2.poly_append ( -3.5, 4 ) ;
	p2.poly_append ( 4.5, 3 ) ;
	p2.poly_append ( 6.5, 1 ) ;

	cout << "\nSecond polynomial:" ;
	p2.display_poly( ) ;

	poly p3 ;
	p3.poly_add ( p1, p2 ) ;

	cout << "\nResultant polynomial: " ;
	p3.display_poly( ) ;
}

