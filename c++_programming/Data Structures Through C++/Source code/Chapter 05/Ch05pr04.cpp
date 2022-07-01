// Program Ch05pr04
// Program to multiply two sparse matrices

#include <iostream.h>

const int MAX1 = 3 ;
const int MAX2 = 3 ;
const int MAXSIZE = 20 ;

#define TRUE 1
#define FALSE 2

class sparse
{
	private :

		int *sp ;
		int row ;
		int *result ;
		
	public :

		sparse( ) ;
		void create_array(  ) ;
		 int count( ) ;
		void display( ) ;
		void create_tuple ( sparse &s ) ;
		void display_tuple( ) ;
		void prodmat ( sparse &a, sparse &b ) ;
		static void searchina ( int *sp, int ii, int*p, int*flag ) ;
		static void searchinb ( int *sp, int jj, int colofa, int*p, int*flag ) ;
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
void sparse :: create_array(  )
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
		if ( i % 3 == 0 )
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
		if ( ( ( i % 3 ) == 0 ) && ( i != 0 ) )
		{
			r++ ;
			c = 0 ;
		}

		// checks for non-zero element,
		// row, column and non-zero value
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

// performs multiplication of sparse matrices
void sparse :: prodmat ( sparse &a, sparse &b )
{
     int sum, k, position, posi, flaga, flagb ;
     k = 1 ;

     result = new int[MAXSIZE * 3] ;

	for ( int i = 0 ; i < * ( a.sp + 0 * 3 + 0 ) ; i++ )
	{
		for ( int j = 0 ; j < * ( b.sp + 0 * 3 + 1 ) ; j++  )
		{
			// search if an element present at ith row
			searchina ( a.sp, i, &position, &flaga ) ;
			if ( flaga == TRUE )
			{
				sum = 0 ;

				// run loop till there are element at ith row 
				// in first 3-tuple
				while ( * ( a.sp + position * 3 + 0 ) == i )
				{
					// search if an element present at ith col.
					// in second 3-tuple
					searchinb ( b.sp, j, * ( a.sp + position * 3 + 1 ),
						    &posi, &flagb ) ;
					 
					// if found then multiply
					if ( flagb == TRUE )
						sum = sum + * ( a.sp + position * 3 + 2 ) *
							    * ( b.sp + posi * 3 + 2 ) ;
					position = position + 1 ;
				}

				// add result 
				if ( sum != 0 )
				{
					* ( result + k * 3 + 0 ) = i ;
					* ( result + k * 3 + 1 ) = j ;
					* ( result + k * 3 + 2 ) = sum ;
					k = k + 1 ;
				}
            }
         }
      }
      
	// add total no. of rows, cols and non-zero values
	* ( result + 0 * 3 + 0 ) = * ( a.sp + 0 * 3 + 0 ) ;
	* ( result + 0 * 3 + 1 ) = * ( b.sp + 0 * 3 + 1 ) ;
	* ( result + 0 * 3 + 2 ) = k - 1 ;
}

// searches if an element present at iith row
void sparse :: searchina ( int *sp, int ii, int *p, int *flag )
{
	int j ;
	*flag = FALSE ;
	for ( j = 1 ; j <= * ( sp + 0 * 3 + 2 ) ; j++ )
	{
		if ( * ( sp + j * 3 + 0 ) == ii )
		{
			*p = j ;
			*flag = TRUE ;
			return ;
		}
	 }
}

// searches if an element where col. of first 3-tuple
// is equal to row of second 3-tuple
void sparse :: searchinb ( int *sp, int jj, int colofa, int *p, int *flag )
{
     int j ;
     *flag = FALSE ;
	 for ( j = 1 ; j <= * ( sp + 0 * 3 + 2 ) ; j++ )
     {
		if ( * ( sp + j * 3 + 1 ) == jj && * ( sp + j * 3 + 0 ) == colofa )
		{
			*p = j ;
			*flag = TRUE ;
			return ;
		}
    }
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
	s5.prodmat ( s2, s4 ) ;

	cout << endl << "Result of multiplication of two matrices: " ;
	s5.display_result( ) ;
}
