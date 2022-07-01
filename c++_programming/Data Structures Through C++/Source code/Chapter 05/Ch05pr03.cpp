// Program Ch05pr03
// Program to add two sparse matrices

#include <iostream.h>

const int MAX1 = 3 ;
const int MAX2 = 3 ;
const int MAXSIZE = 9 ;
const int BIGNUM = 100 ;

class sparse
{
	private :

		int *sp ;
		int row ;
		int *result ;

	public :

		sparse( ) ;
		void create_array( ) ;
		 int count( ) ;
		void display( ) ;
		void create_tuple ( sparse &s ) ;
		void display_tuple( ) ;
		void addmat ( sparse &s1, sparse &s2 ) ;
		void display_result( ) ;
		~sparse( ) ;
} ;

// initialises data members
sparse :: sparse( )
{
	sp = NULL ;
	result = NULL ;
}

// dynamically creates the matrix
void sparse :: create_array( )
{
	int n ;

	// allocate memory
	sp = new int [MAX1 * MAX2] ;

	// add elements to the array
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

	// get the total number of non-zero elements
	// add 1 to store total no. of rows, cols, and non-zero values
	row = s.count( ) + 1 ;

	// allocate memory
	sp = new int[row * 3] ;

	// store information about 
	// total no. of rows, cols, and non-zero values
	* ( sp + 0 ) = MAX1 ;
	* ( sp + 1 ) = MAX2 ;
	* ( sp + 2 ) = row - 1 ;

	l = 2 ;

	// scan the array and store info. about non-zero values
	// in the 3-tuple
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

// displays the contents of the matrix
void sparse :: display_tuple( )
{
	// traverses the entire matrix
	cout << "\nElements in a 3-tuple: " << endl ;

	int j = ( * ( sp + 2 ) * 3 ) + 3 ;

	for ( int i = 0 ; i < j ; i++ )
	{
		// positions the cursor to the new line for every new row
		if ( i % 3 == 0 )
			cout << endl ;
		cout << * ( sp + i ) << "  " ;
	}
}

// carries out addition of two matrices
void sparse :: addmat ( sparse &s1, sparse &s2 )
{
	int i = 1, j = 1, k = 1 ;
	int elem = 1 ;
	int max, amax, bmax ;
	int rowa, rowb, cola, colb, vala, valb ;

	// get the total number of non-zero values
	// from both the matrices
	amax = * ( s1.sp + 2 ) ;
	bmax = * ( s2.sp + 2 ) ;
	max = amax + bmax ;

	// allocate memory for result 
	result = new int[MAXSIZE*3] ;

	while ( elem <= max )
	{
		// check if i < max. non-zero values 
		// in first 3-tuple and get the values
		if ( i <= amax )
		{
			rowa =  * ( s1.sp + i * 3 + 0 ) ;
			cola =  * ( s1.sp + i * 3 + 1 ) ;
			vala =  * ( s1.sp + i * 3 + 2 ) ;
		}
		else
			rowa = cola = BIGNUM ;

		// check if j < max. non-zero values 
		// in secon 3-tuple and get the values
		if ( j <= bmax )
		{
			rowb = * ( s2.sp + j * 3 + 0 ) ;
			colb = * ( s2.sp + j * 3 + 1 ) ;
			valb = * ( s2.sp + j * 3 + 2 ) ;
		}
		else
		    rowb = colb = BIGNUM ;

		// if row no. of both 3-tuple are same
		if ( rowa == rowb )
		{
			// if col no. of both 3-tuple are same
			if ( cola == colb )
			{
				// add tow non-zero values
				// store in result
				* ( result + k * 3 + 0 ) = rowa ;
				* ( result + k * 3 + 1 ) = cola ;
				* ( result + k * 3 + 2 ) = vala + valb ;
				i++ ;
				j++ ;
				max-- ;
			}

			// if col no. of first 3-tuple is < col no. of 
			// second 3-tuple, then add info. as it is
			// to result
			if ( cola < colb )
			{
				* ( result + k * 3 + 0 ) = rowa ;
				* ( result + k * 3 + 1 ) = cola ;
				* ( result + k * 3 + 2 ) = vala ;
				i++ ;
			}

			// if col no. of first 3-tuple is > col no. of 
			// second 3-tuple, then add info. as it is
			// to result
			if ( cola > colb )
			{
				* ( result + k * 3 + 0 ) = rowb ;
				* ( result + k * 3 + 1 ) = colb ;
				* ( result + k * 3 + 2 ) = valb ;
				j++ ;
			}
			k++ ;
	        }

		// if row no. of first 3-tuple is < row no. of 
		// second 3-tuple, then add info. as it is
		// to result
		
		if ( rowa < rowb )
		{
			* ( result + k * 3 + 0 ) = rowa ;
			* ( result + k * 3 + 1 ) = cola ;
			* ( result + k * 3 + 2 ) = vala ;
			i++ ;
			k++ ;
        	}
        
		// if row no. of first 3-tuple is > row no. of 
		// second 3-tuple, then add info. as it is
		// to result 

		if ( rowa > rowb )
		{
			* ( result + k * 3 + 0 ) = rowb ;
			* ( result + k * 3 + 1 ) = colb ;
			* ( result + k * 3 + 2 ) = valb ;
			j++ ;
			k++ ;
		}
		elem++ ;
	}

	// add info about the total no. of rows,
	// cols, and non-zero values that the resultant array
	// contains to the result
	* ( result + 0 ) = MAX1 ;
	* ( result + 1 ) = MAX2 ;
	* ( result + 2 ) = max ;
}

// displays the contents of the matrix
void sparse :: display_result( )
{
	// traverses the entire matrix
	for ( int i = 0 ; i < ( * ( result + 0 + 2 ) + 1 ) * 3 ; i++ )
	{
		// positions the cursor to the new line for every new row
		if ( i % 3 == 0 )
			cout << endl ;
		cout << * ( result + i ) << "  " ;
	}
}


// deallocates memory
sparse :: ~sparse( )
{
	if ( sp != NULL )
		delete sp ;
	if ( result != NULL )
		delete result ;
}

void main( )
{
	sparse s1 ;
	s1.create_array( ) ;

	sparse s2 ;
	s2.create_tuple ( s1 ) ;
	s2.display_tuple( ) ;

	sparse s3 ;
	s3.create_array( ) ;

	sparse s4 ;
	s4.create_tuple ( s3 ) ;
	s4.display_tuple( ) ;

	sparse s5 ;
	s5.addmat ( s2, s4 ) ;

	cout << endl << "Result of addition of two matrices: " ;
	s5.display_result( ) ;
}
