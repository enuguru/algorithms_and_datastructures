// Program Dictionary
// Proogram that uses linked list to maintain a dictionary

#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

class dict
{

	private :

		struct node
		{
			char data[20] ;
			char m[5][20] ;
			int mcount ;
			struct node * link ;
		} *dic[26] ;

	public :

		dict( ) ;
		void add ( char *str ) ;
		int  search ( char * ) ;
		void show( ) ;
		void deldic( ) ;
} ;

// initialises data member
dict :: dict( )
{
	for ( int i = 0 ; i < 26 ; i++ )
    	dic[i] = NULL ;
}

// adds a word to the dictionary
void dict :: add ( char * str )
{
	int i, j = toupper ( str[0] ) - 65 ;
	node *r, *temp = dic[j], *q ;
	char mean[5][20], ch = 'y' ;

	i = search ( str ) ;
	if ( i )
	{
		cout << "\nWord already exists." ;
		return ;
	}
	q = new node ;
	strcpy ( q -> data, str ) ;
	q -> link = NULL ;

	for ( i = 0 ; tolower ( ch ) == 'y' && i < 5 ; i++ )
	{
		cout << "\n\nEnter the meaning(s) : " ;
		gets ( mean[i] ) ;
		strcpy ( q -> m[i] , mean[i] ) ;
		if ( i != 4 )
			cout << "\nAdd more meanings (y/n) " ;
		else
			cout << "You cannot enter more than 5 meanings." ;
		cin >> ch ;
	}

	q -> mcount = i ;
	if ( dic[j] == NULL || strcmp ( dic[j] -> data, str ) > 0 )
	{
		r = dic[j] ;
		dic[j] = q ;
		q -> link = r ;
		return ;
	}
	else
	{
		while ( temp != NULL )
		{
			if ( ( strcmp ( temp -> data, str ) < 0 ) &&
				 ( ( strcmp ( temp -> link -> data, str ) > 0 ) ||
					 temp -> link == NULL ) )
			{
				q -> link = temp -> link ;
				temp -> link = q ;
				return ;
			}
			temp = temp -> link ;
		}
	}
}

// searches for given word in dictionary
int dict :: search ( char *str )
{
	struct node *n ;
	char temp1[20] ;
	char temp2[20] ;
	int i ;

	n = dic[toupper ( str[0] ) - 65] ;
	strcpy ( temp2, str ) ;
	strupr ( temp2 ) ;

	while ( n != NULL )
	{
		strcpy ( temp1, n -> data ) ;

		if (  strcmp ( strupr ( temp1 ), temp2 ) == 0 )
		{
			cout << "\n" << n -> data << "\t\t" << n -> m[0] ;
			for ( i = 1 ; i < n -> mcount ; i++ )
				cout << "\n\t\t" <<  n -> m[i] ;
			return 1 ;
		}
		n = n -> link ;
	}
	return 0 ;
}

// displays word and its meaning
void dict :: show( )
{
	node *n ;
	int i, j ;

	cout << "Word\t\tMeaning\n" ;
	for ( i = 0 ; i <= 30 ; i++ )
		cout << "-" ;

	for ( i = 0 ; i <= 25 ; i++ )
	{
		n = dic[i] ;
		while ( n != NULL )
		{
			cout << "\n" << n -> data << "\t\t" <<  n -> m[0] ;
			for ( j = 1 ; j < n -> mcount ; j++ )
				cout << "\n\t\t" << n -> m[j] ;
			n = n -> link ;
		}
	}
}

// deallocates memory
void dict :: deldic( )
{
	node *n, *t ;
	int i ;
	cout << endl ;

	for ( i = 0 ; i <= 25 ; i++ )
	{
		n = dic[i] ;
		while ( n != NULL )
		{
			t = n -> link ;
			delete n ;
			n = t ;
		}
	}
}

void main( )
{
	char word[20] ;
	int ch ;
	int i ;

	dict d ;
	char temp ;

	clrscr( ) ;

	while ( 1 )
	{
		clrscr( ) ;
		cout << "\n\t\tDictionary\n" ;
		cout << "\n\t\t1.Add Word.\n" ;
		cout << "\t\t2.Search Word.\n" ;
		cout << "\t\t3.Show Dictionary.\n" ;
		cout << "\t\t0.Exit." ;
		cout << "\n\n\t\tYour Choice " ;
		cin >> ch ;

		switch ( ch )
		{
			case 1 :

				cout << "\nEnter any word : " ;
				cin >> word ;
				d.add ( word ) ;

				cout << "\nPress any key to continue..." ;
				cin >> temp ;
				break ;

			case 2 :

				cout << "\nEnter the word to search : " ;
				cin >> word ;
				i = d.search ( word ) ;
				if ( ! i )
					cout << "Word does not exists." ;

				cout << "\nPress any key to continue..." ;
				cin >> temp ;

				break ;

			case 3 :

				d.show( ) ;

				cout << "\nPress any key to continue..." ;
				cin >> temp ;

				break ;

			case 0 :

				d.deldic( ) ;
				exit ( 0 ) ;
				break ;

			default :

				cout << "\nWrong Choice" ;

				cout << "\nPress any key to continue..." ;
				cin >> temp ;
		}
	}
}

