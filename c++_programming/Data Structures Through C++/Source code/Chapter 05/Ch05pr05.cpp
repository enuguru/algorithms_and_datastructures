// Program Ch05pr04
// Program to store sparse matrix as a linked list

#include <iostream.h>

const int MAX1 = 3 ;
const int MAX2 = 3 ;

// structure for col headnode
struct cheadnode
{
	int colno ;
	struct node *down ;
	cheadnode *next ;
} ;

// structure for row headnode
struct rheadnode
{
	int rowno ;
	struct node * right ;
	rheadnode *next ;
} ;

// structure for node to store element
struct node
{
	int row ;
	int col ;
	int val ;
	node *right ;
	node *down ;
} ;

// structure for special headnode
struct spmat
{
	rheadnode *firstrow ;
	cheadnode *firstcol ;
	int noofrows ;
	int noofcols ;
} ;

class sparse
{
	private :

		int *sp ;
		int row  ;
		spmat *smat ;
		cheadnode *chead[MAX2] ;
		rheadnode *rhead[MAX1] ;
		node *nd ;

	public :

		sparse( ) ;
		void create_array( ) ;
		void display( ) ;
		int count( ) ;
		void create_triplet ( sparse &s ) ;
		void create_llist( ) ;
		void insert ( spmat *smat, int r, int c, int v ) ;
		void show_llist( ) ;
		~sparse( ) ;
} ;

// initializes data member
sparse :: sparse( )
{
	// create row headnodes
	for ( int i = 0 ; i < MAX1 ; i++ )
		rhead[i] = new rheadnode ;

	// initialize and link row headnodes together
	for ( i = 0 ; i < MAX1 - 1 ; i++ )
	{
		rhead[i] -> next = rhead[i + 1] ;
		rhead[i] -> right = NULL ;
		rhead[i] -> rowno = i ;
	}
	rhead[i] -> right = NULL ;
	rhead[i] -> next = NULL ;

	// create col headnodes
	for ( i = 0 ; i < MAX1 ; i++ )
		chead[i] = new cheadnode ;

	// initialize and link col headnodes together
	for ( i = 0 ; i < MAX2 - 1 ; i++ )
	{
		chead[i] -> next = chead[i + 1] ;
		chead[i] -> down = NULL ;
		chead[i] -> colno = i ;
	}
	chead[i] -> down = NULL ;
	chead[i] -> next = NULL ;

	// create and initialize special headnode
	smat = new spmat ;
	smat -> firstcol = chead[0] ;
	smat -> firstrow = rhead[0] ;
	smat -> noofcols = MAX2 ;
	smat -> noofrows = MAX1 ;
}

// creates, dynamically the matrix of size MAX1 x MAX2
void sparse :: create_array( )
{
	int n ;

	sp = new int[MAX1 * MAX2] ;

	// get the element and store it
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

// creates an array of triplet containing info. about non-zero elements
void sparse :: create_triplet ( sparse &s )
{
	int r = 0 , c = -1, l = -1 ;

	row = s.count( ) ;
	sp = new int[row * 3] ;

	for ( int i = 0 ; i < MAX1 * MAX2 ; i++ )
	{
		c++ ;
		// sets the row and column values
		if ( ( ( i % MAX2 ) == 0 ) && ( i != 0 ) )
		{
			r++ ;
			c = 0 ;
		}

		// checks for non-zero element. Row, column and
		// non-zero element value is assigned to the matrix //

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

// stores information of triplet in a linked list form
void sparse :: create_llist( )
{
	int j = 0 ;
	for ( int i = 0 ; i < row ; i++, j+= 3 )
		insert ( smat, * ( sp + j ), * ( sp + j + 1 ), * ( sp + j + 2) ) ;
}

// inserts element to the list
void sparse :: insert ( spmat *smat , int r, int c, int v )
{
	// allocate and initialize memory for the node
	nd = new node ;
	nd -> col = c ;
	nd -> row = r ;
	nd -> val = v ;

	node *temp1, *temp2 ;

	// get the first row headnode
	rheadnode *rh = smat -> firstrow ;

	// get the proper row headnode
	for ( int i = 0 ; i < r ; i++ )
		rh = rh -> next ;
	temp1 = rh -> right ;

	// if no element added in a row
	if ( temp1 == NULL )
	{
		rh -> right = nd ;
		nd -> right = NULL ;
	}
	else
	{
		// add element at proper position
		while ( ( temp1 != NULL  ) && ( temp1 -> col < c ) )
		{
			temp2 = temp1 ;
			temp1 = temp1 -> right ;
		}
		temp2 -> right = nd ;
		nd -> right = NULL ;
	}

	// link proper col headnode with the node
	cheadnode *ch = smat -> firstcol ;
	for ( int j = 0 ; j < c ; j++ )
		ch = ch -> next ;
	temp1 = ch -> down ;

	// if col not pointing to any node
	if ( temp1 == NULL )
	{
		ch -> down = nd ;
		nd -> down = NULL ;
	}
	else
	{
		// link previous node in column with next node in same column
		while ( ( temp1 != NULL ) && ( temp1 -> row < r ) )
		{
			temp2 = temp1 ;
			temp1 = temp1 -> down ;
		}
		temp2 -> down = nd ;
		nd -> down = NULL ;
	}
}

void sparse :: show_llist( )
{
	// get the first row headnode
	int r = smat -> noofrows ;
	node *temp ;

	cout << endl ;

	for ( int i = 0 ; i < r ; i++ )
	{
		temp = rhead[i] -> right ;
		if ( temp != NULL )
		{
			while ( temp -> right != NULL )
			{
				cout << "Row: " << temp -> row << " Col: " << temp -> col << " Val: " << temp -> val << endl ;
				temp = temp -> right ;
			}
			if ( temp -> row == i )
				cout << "Row: " << temp -> row << " Col: " << temp -> col << " Val: " << temp -> val << endl ;
		}
	}
}

// deallocates memory
sparse :: ~sparse( )
{
	int r = smat -> noofrows ;
	rheadnode *rh ;
	node *temp1, *temp2 ;

	// deallocate memeory of nodes by traversing rowwise
	for ( int i = r - 1 ; i >= 0 ; i-- )
	{
		rh = rhead[i] ;
		temp1 = rh -> right ;

		while ( temp1 != NULL )
		{
			temp2 = temp1 -> right ;
			delete temp1 ;
			temp1 = temp2 ;
		}
	}

	// deallocate memory of row headnodes
	for ( i = r - 1 ; i >= 0 ; i-- )
		delete rhead[i] ;

	// deallocate memory of col headnodes
	int c = smat -> noofcols ;
	for ( i = c - 1 ; i >= 0 ; i-- )
		delete chead[i] ;
}

void main( )
{
	sparse s1 ;
	s1.create_array( ) ;

	cout << "\nElements in sparse matrix: " ;
	s1.display( ) ;

	sparse s2 ;
	s2.create_triplet ( s1 ) ;

	s2.create_llist( ) ;
	cout << "\n\nInformation stored in linked list : " ;
	s2.show_llist( ) ;
}