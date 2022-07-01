// Program Ch04pr15
// Program to multiply two polynomials maintained as linked lists.

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
		void poly_multiply ( poly &p1, poly &p2 ) ;
		void padd ( float c, int e ) ;
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
	polynode *temp ;
	temp = p ;

	// create a new node if the list is empty
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

// multiplies the two polynomials
void poly :: poly_multiply ( poly &p1, poly &p2 )
{
	polynode *temp1, *temp2 ;
	float coeff1, exp1 ;

	// point to the starting of first linked list
	temp1 = p1.p ;

	// point to the starting of second linked list
	temp2 = p2.p ;

	if ( temp1 == NULL && temp2 == NULL )
		return ;

	// if one of the list is empty
	if ( temp1 == NULL )
		p = p2.p ;
	else
	{
		if ( temp2 == NULL )
			p = temp1 ;
		else // if both linked lists exist
		{
			// for each term of the first list
			while ( temp1 != NULL )
			{
				// multiply each term of the second linked list
				// with a term of the first linked list
				while ( temp2 != NULL )
				{
					coeff1 = temp1 -> coeff * temp2 -> coeff ;
					exp1 = temp1 -> exp + temp2 -> exp ;
					temp2 = temp2 -> link ;

					// add the new term to the resultant polynomial
					padd ( coeff1, exp1 ) ;
				}

				// reposition the pointer to the starting of
   				// the second linked list
				temp2 = p2.p ;

				// go to the next node
				temp1 = temp1 -> link ;
			}
		}
	}
}

// adds a term to the polynomial in
// the descending order of the exponent
void poly :: padd ( float c, int e )
{
	polynode *r, *temp ;
	temp = p ;

	// if list is empty or if the node is to be
	// inserted before the first node
	if ( temp == NULL || c > temp -> exp )
	{
		r = new polynode ;
		r -> coeff = c ;
		r -> exp = e ;
		if ( p == NULL )
		{
			r -> link = NULL ;
			p = r ;
		}
		else
		{
			r -> link = temp ;
			p = r ;
		}
	}
	else
	{
		// traverse the entire linked list to
		// search the position to insert a new node
		while ( temp != NULL )
		{
			if ( temp -> exp == e )
			{
				temp -> coeff += c ;
				return ;
			}

			if ( temp -> exp > c && ( temp -> link -> exp < c ||
				 temp -> link == NULL ) )
			{
				r = new polynode ;
				r -> coeff = c;
				r -> exp = e ;
				r -> link = NULL ;
				temp -> link = r ;
				return ;
			}

			// go to next node
			temp = temp -> link ;
		}

		r -> link = NULL ;
		temp -> link = r ;
	}
}

// deallocates memeory
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

	p1.poly_append ( 3, 5 ) ;
	p1.poly_append ( 2, 4 ) ;
	p1.poly_append ( 1, 2 ) ;

	cout << "\nFirst polynomial: " << endl ;
	p1.display_poly( ) ;

	poly p2 ;
	p2.poly_append ( 1, 6 ) ;
	p2.poly_append ( 2, 5 ) ;
	p2.poly_append ( 3, 4 ) ;

	cout << "\nSecond polynomial: " << endl ;
	p2.display_poly( ) ;

	poly p3 ;
	p3.poly_multiply ( p1, p2 ) ;

	cout << "\nResultant polynomial: " << endl ;
	p3.display_poly( ) ;
}

