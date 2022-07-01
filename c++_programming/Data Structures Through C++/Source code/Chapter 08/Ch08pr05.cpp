// Program Ch08pr05
// Program for threaded binary tree

#include <iostream.h>

enum boolean
{
	false = 0,
	true = 1
} ;

class ttree
{

	private :

		struct thtree
		{
			enum boolean left ;
			thtree *leftchild ;
			int data ;
			thtree *rightchild ;
			enum boolen right ;
		} *th_head ;

	public :

		ttree( ) ;
		void insert ( int num ) ;
		void remove ( int num ) ;
		static void search ( thtree **sr, int num, thtree **par,
							 thtree **x, int *found ) ;
		void inorder( ) ;
		~ttree( ) ;
} ;

// initialises data member
ttree :: ttree( )
{
    th_head = NULL ;
}

// inserts a node in a threaded binary tree
void ttree :: insert ( int num )
{
	thtree *head = th_head, *p, *z ;

	// allocating a new node
	z = new thtree ;

	z -> left = true ;  // indicates a thread
	z -> data = num ;   // assign new data
	z -> right = true ;  // indicates a thread

	// if tree is empty
	if ( th_head == NULL )
	{
		head = new thtree ;

		// the entire tree is treated as a
		// left sub-tree of the head node
		head -> left = false ;

		// z becomes leftchild of the head node
		head -> leftchild = z ;
		head -> data = -9999 ;  // no data
		head -> rightchild = head ;

		// right link will always be pointing
		// pointing to itself
		head -> right = false ;

		th_head = head ;

		// left thread to head
		z -> leftchild = head ;

		// right thread to head
		z -> rightchild = head ;
	}
	else  // if tree is non-empty
	{
		p = head -> leftchild ;

		// traverse till the thread is found attached to the head
		while ( p != head )
		{
			if ( p -> data > num )
			{
				// checking for a thread
				if ( p -> left != true )
					p = p -> leftchild ;
				else
				{
					z -> leftchild = p -> leftchild ;
					p -> leftchild = z ;

					// indicates a link
					p -> left = false ;
					z -> right = true ;
					z -> rightchild = p ;
					return ;
				}
			}
			else
			{
				if ( p -> data < num )
				{
					if ( p -> right != true )
						p = p -> rightchild ;
					else
					{
						z -> rightchild = p -> rightchild ;
						p -> rightchild = z ;

						// indicates a link
						p -> right = false ;
						z -> left = true ;
						z -> leftchild = p ;
						return ;
					}
				}
			}
		}
	}
}

// deletes a node from the binary search tree
void ttree :: remove ( int num )
{
	int found ;
	thtree *parent, *x, *xsucc ;

	// if tree is empty
	if ( th_head == NULL )
	{
		cout << "\nTree is empty" ;
		return ;
	}

	parent = x = NULL ;

	// call to search function to find
	// the node to be deleted
	search ( &th_head, num, &parent, &x, &found ) ;

	// if the node to deleted is not found
	if ( found == false )
	{
		cout << "\nData to be deleted, not found" ;
		return ;
	}

	// if the node to be deleted has two children
	if ( x -> left == false && x -> right == false )
	{
		parent = x ;
		xsucc = x -> rightchild ;

		while ( xsucc -> left == false )
		{
			parent = xsucc ;
			xsucc = xsucc -> leftchild ;
		}

		x -> data = xsucc -> data ;
		x = xsucc ;
	}

	// if the node to be deleted has no child
	if ( x -> left == true && x -> right == true )
	{
		// if node to be deleted is a root node
		if ( parent == NULL )
		{
			th_head -> leftchild = th_head ;
			th_head -> left = true ;

			delete x ;
			return ;
		}

		if ( parent -> rightchild == x )
		{
			parent -> right = true ;
			parent -> rightchild = x -> rightchild ;
		}
		else
		{
			parent -> left = true ;
			parent -> leftchild = x -> leftchild ;
		}

		delete x ;
		return ;
	}

	// if the node to be deleted
	// has only rightchild
	if ( x -> left == true && x -> right == false )
	{
		// node to be deleted is a root node
		if ( parent == NULL )
		{
			th_head -> leftchild = x -> rightchild ;
			delete x ;
			return ;
		}

		if ( parent -> leftchild == x )
		{
			parent -> leftchild = x -> rightchild ;
			x -> rightchild -> leftchild = x -> leftchild ;
		}
		else
		{
			parent -> rightchild = x -> rightchild ;
			x -> rightchild -> leftchild = parent ;
		}
		delete x ;
		return ;
	}

	// if the node to be deleted has only left child
	if ( x -> left == false && x -> right == true )
	{
		// the node to be deleted is a root node
		if ( parent == NULL )
		{
			parent = x ;
			xsucc = x -> leftchild ;

			while ( xsucc -> right == false )
			xsucc = xsucc -> rightchild ;

			xsucc -> rightchild = th_head ;

			th_head -> leftchild = x -> leftchild ;

			delete x ;
			return ;
		}

		if ( parent -> leftchild == x )
		{
			parent -> leftchild = x -> leftchild ;
			x -> leftchild -> rightchild = parent ;
		}
		else
		{
			parent -> rightchild = x -> leftchild ;
			x -> leftchild -> rightchild = x -> rightchild ;
		}

		delete  x ;
		return ;
	}
}

// returns the address of the node to be
// deleted, address of its parent and
// whether the node is found or not

void ttree :: search ( thtree **root, int num, thtree **par,
					   thtree **x, int *found )
{
	thtree *q ;

	q = ( *root ) -> leftchild ;
	*found = false ;
	*par = NULL ;

	while ( q != root )
	{
		// if the node to be
		// deleted is found
		if ( q -> data == num )
		{
			*found = true ;
			*x = q ;
			return ;
		}

		*par = q ;

		if ( q -> data > num )
		{
			if ( q -> left == true )
			{
				*found = false ;
				x = NULL ;
				return ;
			}
			q = q -> leftchild ;
		}
		else
		{
			if ( q -> right == true )
			{
				*found = false ;
				*x = NULL ;
				return ;
			}
			q = q -> rightchild ;
		}
	}
}

// traverses the threaded binary tree in in-order
void ttree :: inorder( )
{
	thtree *p ;

	p = th_head -> leftchild ;

	while ( p != th_head )
	{
		while ( p -> left == false )
			p = p -> leftchild ;

		cout << p -> data <<  "\t" ;

		while ( p -> right == true )
		{
			p = p -> rightchild ;

			if ( p == th_head )
				break ;

			cout << p -> data << "\t" ;

		}
		p = p -> rightchild ;
	}
}

ttree :: ~ttree( )
{
    while ( th_head -> leftchild != th_head )
    	remove ( th_head -> leftchild -> data ) ;
}

void main( )
{
	ttree th ;

	th.insert ( 11 ) ;
	th.insert ( 9 ) ;
	th.insert ( 13 ) ;
	th.insert ( 8 ) ;
	th.insert ( 10 ) ;
	th.insert ( 12 ) ;
	th.insert ( 14 ) ;
	th.insert ( 15 ) ;
	th.insert ( 7 ) ;

	cout << "Threaded binary tree before deletion:\n"  ;
	th.inorder( ) ;

	th.remove ( 10 ) ;
	cout << "\nThreaded binary tree after deletion:\n"  ;
	th.inorder( ) ;

	th.remove ( 14 ) ;
	cout << "\nThreaded binary tree after deletion:\n" ;
	th.inorder( ) ;

	th.remove ( 8 ) ;
	cout << "\nThreaded binary tree after deletion:\n" ;
	th.inorder( ) ;

	th.remove ( 13 ) ;
	cout << "\nThreaded binary tree after deletion:\n" ;
	th.inorder( ) ;
}

