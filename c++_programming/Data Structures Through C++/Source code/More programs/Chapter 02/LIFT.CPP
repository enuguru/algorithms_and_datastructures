#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <ctype.h>
#include <math.h>

// the base class for lift
class lift
{
	private :

		int floorno ; // stores lift no on which the lift is standing

	public :

		lift( ) ;
		void setfloor ( int n ) ;
		int getfloorno( ) ;
} ;

// constructor
lift::lift( )
{
	floorno = 0 ;
}

// set the floorno to which the lift will move
void lift::setfloor ( int n )
{
	floorno = n ;
}

// get the floorno on which the lift is standing
int lift::getfloorno( )
{
	return floorno ;
}

// class to manage lifts
class liftd
{
	private :

		lift l[5] ;   // an array of lift objects

	public :

		liftd( ) ;
		void showstatus( ) ;
		void allotlift ( int flnos, int flnot, char d ) ;
} ;

// constructor
liftd::liftd( )
{
}

// show current status, i.e. the floor no. on which
// the lifts are standing
void liftd::showstatus( )
{
	for ( int i = 0; i < 5; i++ )
		cout << "Lift : " << i << " is on " << l[i].getfloorno( ) << " floor" << endl ;
}

// allot the lift to the user
void liftd::allotlift ( int flnos, int flnot, char d )
{
	// struct p to store the difference between 2 lifts
	struct p
	{
		int lfno[5] ;
		 int pos[5] ;
		int diff[5] ;
	} arr ;

	int lno = -1 ;	  // to store the lift no. that can be made available
	int i, j ;

	// initialize array
	for ( i = 0; i < 5; i++ )
	{
		arr.lfno[i] = i ;
		 arr.pos[i] = 0 ;
		arr.diff[i] = 0 ;
	}

	while ( lno == -1 )
	{
		// get the current position of a lift
		for ( i = 0 ; i < 5; i++ )
			arr.pos[i] = l[i].getfloorno( ) ;

		for ( i = 0; i < 5; i++ )
		{
			// get the diff. between floor on which lift is standing
			// and the floor on which the user is standing
			arr.diff[i] = abs ( arr.pos[i] - flnos ) ;
		}

		// sort array
		int t1, t2, t3 ;
		for ( i = 0; i < 5; i++ )
		{
			for ( j = 0; j < 4; j++ )
			{
				if ( arr.diff[i] < arr.diff[j] )
				{

					t1 = arr.lfno[i] ;
					t2 = arr.pos[i] ;
					t3 = arr.diff[i] ;
					arr.lfno[i] = arr.lfno[j] ;
					arr.pos[i] = arr.pos[j] ;
					arr.diff[i] = arr.diff[j] ;
					arr.lfno[j] = t1 ;
					arr.pos[j] = t2 ;
					arr.diff[j] = t3 ;
				}
			}
		}

		// check for the lift that can be alloted
		// depending on the direction
		int k ;
		for ( i = 0, k = 0; i < 5; i++ )
		{
			k = arr.lfno[i] ;

			if ( ( d == 'u' ) && (
				 ( l[k].getfloorno( ) < flnos ) ||
				 ( l[k].getfloorno( ) == 0 ) ||
				 ( l[k].getfloorno( ) == flnos ) ) )
			{
				lno = k ;
				break ;
			}

			if ( ( d == 'd' ) && (
				 ( l[k].getfloorno( ) > flnos ) ||
				 ( l[k].getfloorno( ) == 0 ) ||
				 ( l[k].getfloorno( ) == flnos ) ) )
			{
				lno = k ;
				break ;
			}
		}

		// if none of the lift has been alloted
		j = 30 ;
		if ( lno == -1 )
		{
			for ( i = 0; i < 5; i++ )
			{
				if ( j > arr.diff[i] )
				{
					j = arr.diff[i] ;
					lno = i ;
				}
			}
		}
	}

	cout << endl ;
	cout << "The lift available to you would be : " ;
	cout << lno << endl ;

	l[lno].setfloor ( flnot ) ;
	cout << endl ;
}

// the main menu
int showmenu( )
{
	int c ;
	cout << " -------------------- Lift Program -------------------- " << endl ;
	cout << " There are 5 lifts available for your service. " << endl ;
	cout << " Select 1 if you want to use a lift. " << endl ;
	cout << " Selecting 2 would show, for each of the 5 lifts, " << endl ;
	cout << " the floor no. on which the lift is currently standing. " << endl ;
	cout << " Select 3 to quit the program " << endl ;
	cout << " ------------------------------------------------------ " << endl ;
	cout << " 1. Do you wish to use lift?" << endl ;
	cout << " 2. Show status of lift" << endl ;
	cout << " 3. Exit" << endl ;
	cout << " ------------------------------------------------------ " << endl ;

	cin >> c ;

	return c ;
}

void validate ( int *fs, int *ft, char *d )
{
	int flnos, flnot ;
	char dir ;
	int flag ;
	unsigned char chr ;

	flnos = flnot = -1 ;
	flag = 0 ;

	while ( flnos < 0 || flnos > 29 )
	{
		cout << "Enter the floor no. where you are standing : " ;
		 cin >> flnos ;

		if  ( flnos < 0 || flnos > 29 )
		{
			cout << endl ;
			cout << "Incorrect floor no.! Enter floor no. in a range of 0 - 29 " << endl ;
			cout << endl ;
			getch( ) ;
		}
	}

	while ( flag == 0 )
	{
		dir = 'j' ;
		while ( tolower ( dir ) != 'u' && tolower ( dir ) != 'd' )
		{
			cout << "Do you wish to go up or down (up/down) : " ;
			 cin >> dir ;
			cout << endl ;

			if ( dir != 'u' && dir != 'd' )
				cout << "Incorrect direction! Enter again" << endl ;
		}

		if ( flnos == 0 && dir == 'd' )
		{
			cout << endl ;
			cout << "You are already standing on ground floor." << endl ;
			cout << "Cannot go further down." << endl ;
			getch( ) ;
			flag = 0 ;
		}
		else
			flag = 1 ;
	}
	flag = 0 ;

	while ( flag == 0 )
	{
		cout << endl ;
		cout << "Enter the floor no. where you want to go : " ;
		 cin >> flnot ;

		if ( ( flnos == 0 && flnot == 0 ) ||
			 ( flnot < 0 || flnot > 29 ) ||
			 ( flnos == flnot ) ||
			 ( ( flnos != 0 ) && ( dir == 'd' && ( flnos - flnot < 0 ) ) ) ||
			 ( ( flnos != 0 ) && ( dir == 'u' && ( flnot < flnos ) ) ) )
		{
			cout << endl ;
			cout << "Incorrect floor no. or trying to move to the same " << endl ;
			cout << "floor where you are standing, or either the " << endl ;
			cout << " direction given is incorrect or the floor number " << endl ;
			cout << " is incorrect. Try again" << endl ;
			flag = 0 ;
		}
		else
			flag = 1 ;
	}

	*fs = flnos ;
	*d =  dir ;
	*ft = flnot ;
}

void main( )
{
	int ch ; 	   // stores the no. entered as a choice for the menu
	int flnos ;    // to store floor no. where the user stands
	int flnot ;    // to store the target floor no.
	char dir ;     // to store the direction
	char chr[ 20 ] ;     // a temporary variable

	void validate ( int *, int *, char * ) ;

	flnos = flnot = -1 ;

	liftd lf ;

	while ( 1 )
	{
		// display main menu
		ch = showmenu( ) ;

		// switch-case for menu options to be handled
		switch ( ch )
		{
			case 1 :

					// actual program logic
                    cout << "Allot lift: " << endl ;
					validate ( &flnos, &flnot, &dir ) ;
					lf.allotlift ( flnos, flnot, dir ) ;
					break ;

			case 2 :

					// getstaus
                    cout << "Current status of lifts: " << endl ;
					lf.showstatus( ) ;
					break ;

			case 3 :

					// exit program
					exit ( 0 ) ;
					break ;

			default :

					// wrong choice
					cout << "Incorrect choice! try again!" << endl ;
		}
		cout << endl << endl ;
		cout << "Press key to continue..." ;
		cin >> chr ;
	}
}