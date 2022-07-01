// Program Ch08pr06
// Program to reconstruct a binary tree

#include <iostream.h>

const int MAX = 101 ;

class btree
{

	private :

		struct node
		{
			node *left ;
			int data ;
			node *right ;
		} *root ;
		int in[MAX], pre[MAX] ;

	public :

		btree( ) ;
		void buildtree ( int num ) ;
		static void insert ( node **sr, int num ) ;
		void traverse( ) ;
		static void preorder ( node *t, int &v, int *pr ) ;
		static void postorder ( node *t ) ;
		static void inorder ( node *t, int &v, int *inr ) ;
		void rec ( int n ) ;
		static node * recons ( int *inorder, int *preorder, int noofnodes ) ;
		void del( ) ;
		static void deltree ( node *t ) ;
		~btree( ) ;
} ;

// initialises data members
btree :: btree( )
{
	root = NULL ;
}

// calls insert( ) to build binary search tree
void btree :: buildtree ( int num )
{
	insert ( &root, num ) ;
}

// inserts a new node in a binary search tree
void btree :: insert ( node **sr, int num )
{
	if ( *sr == NULL )
	{
		*sr = new node ;

		( *sr ) -> left = NULL ;
		( *sr ) -> data = num ;
		( *sr ) -> right = NULL ;
		return ;
	}
	else  // search the node to which new node will be attached
	{
		// if new data is less, traverse to left
		if ( num < ( *sr ) -> data )
			insert ( & ( ( *sr ) -> left ), num ) ;
		else
			// else traverse to right
			insert ( & ( ( *sr ) -> right ), num ) ;
	}
}

// calls functions to traverse tree
void btree :: traverse( )
{
	int x ;

	cout << "\nIn-order   Traversal:\n" ;
	x = 0 ;
	inorder ( root, x, in ) ;

	cout << "\nPre-order  Traversal:\n" ;
	x = 0 ;
	preorder ( root, x, pre ) ;

	cout << "\nPost-order Traversal:\n"  ;
	postorder ( root ) ;
}

// traverses tree
void btree :: inorder ( node *t, int &v, int *inr )
{
	if ( t != NULL )
	{
		inorder ( t -> left, v, inr ) ;
		inr[v++] = t -> data ;
		cout << t -> data << "\t" ;
		inorder ( t -> right, v, inr ) ;
	}
}

// traverses tree
void btree :: preorder ( node *t, int &v, int *pr )
{
	if ( t != NULL )
	{
		pr[v++] = t -> data ;
		cout << t -> data << "\t" ;
		preorder ( t -> left, v, pr ) ;
		preorder ( t -> right, v, pr ) ;
	}
}

// traverses tree
void btree :: postorder ( node *t )
{
	if ( t != NULL )
	{
		postorder ( t -> left ) ;
		postorder ( t -> right ) ;
		cout << t -> data << "\t" ;
	}
}

// calls recons( ) to reconstruct tree
void btree :: rec ( int n )
{
	root = recons ( in, pre, n ) ;
}

// reconstruct binary search tree
node* btree :: recons ( int *inorder, int *preorder, int noofnodes )
{
	node *temp, *left, *right ;
	int tempin[100], temppre[100], i, j ;

	if ( noofnodes == 0 )
		return NULL ;

	temp = new node ;
	temp -> data = preorder[0] ;
	temp -> left = NULL ;
	temp -> right = NULL ;

	if ( noofnodes == 1 )
		return temp ;

	for ( i = 0 ; inorder[i] != preorder[0] ; )
		i++ ;

	if ( i > 0 )
	{
		for ( j = 0 ; j <= i  ; j++ )
			tempin[j] = inorder[j] ;

		for ( j = 0 ; j < i  ; j++ )
			temppre[j] = preorder[j + 1] ;
	}

	left = recons ( tempin, temppre, i ) ;
	temp -> left = left ;

	if ( i < noofnodes - 1 )
	{
		for ( j = i ; j < noofnodes - 1 ; j++ )
		{
			tempin[j - i] = inorder[j + 1] ;
			temppre[j - i] = preorder[j + 1] ;
		}
	}

	right = recons ( tempin, temppre, noofnodes - i - 1 ) ;
	temp -> right = right ;

	return temp ;
}

// calls deltree
void btree :: del( )
{
	deltree ( root ) ;
	root = NULL ;
}

// calls del to deallocate memory
btree :: ~btree( )
{
	deltree ( root ) ;
}

// deallocates memory
void btree :: deltree ( node *t )
{
	if ( t != NULL )
	{
		deltree ( t -> left ) ;
		deltree ( t -> right ) ;
	}
	delete t ;
}

void main( )
{
	btree bt ;
	int req, num ;

	cout << "Specify the number of items to be inserted: " ;

	while ( 1 )
	{
		cin >> req ;
		if ( req >= MAX || req <= 0 )
			cout << "\nEnter number between 1 to 100.\n" ;
		else
			break ;
	}

	for ( int i = 0 ; i < req ; i++ )
	{
		cout << "Enter the data: " ;
		cin >> num ;
		bt.buildtree ( num ) ;
	}

	bt.traverse( ) ;

	bt.del( ) ;
	bt.rec ( req ) ;

	cout << "\n\nAfter reconstruction of the binary tree.\n"  ;
	bt.traverse( ) ;
}

