// Program Ch05pr02
// Program to transpose a sparse matrix

#include <iostream.h>

const int MAX1 = 3 ;
const int MAX2 = 3 ;

class sparse
{
	private :

		int *sp ;
		int row ;

	public :

        sparse( ) ;
		void create_array( ) ;
		void display( ) ;
		 int count( ) ;
		void create_tuple ( sparse &s ) ;
		void display_tuple( ) ;
		void transpose ( sparse &s ) ;
		void display_transpose( ) ;
		~sparse( ) ;
} ;

// initialises data members
sparse :: sparse( )
{
	sp = NULL ;
}

// dynamically creates the matrix of size MAX1 x MAX2
void sparse :: create_array( )
{
	int n ;

	sp = new int [MAX1 * MAX2] ;

	for ( int i = 0 ; i < MAX1 * MAX2 ; i++ )
	{
			cout << "\nEnter element no. " << i << ": " ;
			cin >> n ;

			* ( sp + i ) = n ;
	}
}

// displays the contents of the matrix
void sparse :: display( )
{
	// traverses the entire matrix
	for ( int i = 0 ; i < MAX1 * MAX2 ; i++ )
	{
		// positions the cursor to the new line for every new row
		if ( i % MAX2 == 0 )
			cout << endl ;
		cout << * ( sp + i ) << "  " ;
	}
}

// counts the number of non-zero elements
int sparse :: count( )
{
	int cnt = 0 ;

	for ( int i = 0 ; i < MAX1 * MAX2 ; i++ )
	{
		if ( * ( sp + i ) != 0 )
			cnt++ ;
	}
	return cnt ;
}

// creates an array that stores information about non-zero elements
void sparse :: create_tuple ( sparse &s )
{
	int r = 0 , c = -1, l = -1 ;

	row = s.count( ) + 1 ;

	sp = new int[row * 3] ;
    * ( sp + 0 ) = MAX1 ;
    * ( sp + 1 ) = MAX2 ;
    * ( sp + 2 ) = row - 1 ;

    l = 2 ;

	for ( int i = 0 ; i < MAX1 * MAX2 ; i++ )
	{
		c++ ;

		// sets the row and column values
		if ( ( ( i % MAX2 ) == 0 ) && ( i != 0 ) )
		{
			r++ ;
			c = 0 ;
		}

		// checks for non-zero element
		// row, column and non-zero element value
		// is assigned to the matrix
		if ( * ( s.sp + i ) != 0 )
		{
			l++ ;
			* ( sp + l ) = r ;
			l++ ;
			* ( sp + l ) = c ;
			l++ ;
			* ( sp + l ) = * ( s.sp + i ) ;
		}
	}
}

// obtains transpose of an array
void sparse :: transpose ( sparse &s )
{
    // allocate memory
    sp = new int[s.row * 3] ;
    row = s.row ;

    // store total number of rows, cols
    // and non-zero elements
    * ( sp + 0 ) = * ( s.sp + 1 ) ;
    * ( sp + 1 ) = * ( s.sp + 0 ) ;
    * ( sp + 2 ) = * ( s.sp + 2 ) ;

    int col = * ( sp + 1 ) ;
    int elem = * ( sp + 2 ) ;

    if ( elem <= 0 )
        return ;

    int x, p, pos_1, pos_2 ;

    x = 1 ;

    for ( int c = 0 ; c < col ; c++ )
    {
        for ( int y = 1 ; y <= elem ; y++ )
        {
            p = y * 3 + 1 ;
            if ( * ( s.sp + p ) == c )
            {
                pos_2 = x * 3 + 0 ;
                pos_1 = y * 3 + 1 ;
                * ( sp + pos_2 ) = * ( s.sp + pos_1 ) ;

                pos_2 = x * 3 + 1 ;
                pos_1 = y * 3 + 0 ;
                * ( sp + pos_2 ) = * ( s.sp + pos_1 ) ;

                pos_2 = x * 3 + 2 ;
                pos_1 = y * 3 + 2 ;
                * ( sp + pos_2 ) = * ( s.sp + pos_1 ) ;

                x++ ;
            }
        }
    }
}

// displays the contents of 3-tuple
void sparse :: display_tuple( )
{
	for ( int i = 0 ; i < row * 3 ; i++ )
	{
		if ( i % 3 == 0 )
			cout << endl ;
		cout << * ( sp + i ) << "  " ;
	}
}

// displays 3-tuple after transpose operation
void sparse :: display_transpose( )
{
	for ( int i = 0 ; i < row * 3 ; i++ )
	{
		if ( i % 3 == 0 )
			cout << endl ;
		cout << * ( sp + i ) << "  " ;
	}
}

// deallocates memory
sparse :: ~sparse( )
{
	delete sp ;
}

void main( )
{
	sparse s1 ;
	s1.create_array( ) ;

	cout << endl << "Elements in Sparse Matrix: " ;
	s1.display( ) ;

	int c = s1.count( ) ;
	cout << "\n\nNumber of non-zero elements: " << c ;

	sparse s2 ;
	s2.create_tuple ( s1 ) ;
	cout << "\n\nArray of non-zero elements: " ;
	s2.display_tuple( ) ;

	sparse s3 ;
	s3.transpose ( s2 ) ;
	cout << "\n\nTranspose of array: " ;
	s3.display_transpose( ) ;
}
