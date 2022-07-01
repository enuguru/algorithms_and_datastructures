#include <iostream.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>

const int MAX = 3 ;
const int ARRIVE = 0 ;
const int DEPART = 1 ;

struct plane
{
	int id ;
	int tm ;
} ;

class queue
{
	private :

		int count ;
		int front ;
		int rear ;
		plane p[MAX] ;

	public :

		queue( ) ;
		void addqueue ( plane item ) ;
		plane delqueue( ) ;
		int size( ) ;
		int empty( ) ;
		int full( ) ;
} ;

// initialises data members
queue :: queue( )
{
	count = 0 ;
	front = 0 ;
	rear = -1 ;
}

// adds
void queue :: addqueue ( plane item )
{
	if ( count >= MAX )
	{
		cout << "Queue is full" << endl ;
		return ;
	}
	count++ ;

	rear = ( rear + 1 ) % MAX ;
	p[rear] = item ;
}

plane queue :: delqueue( )
{
	plane p1 ;

	if ( count <= 0 )
	{
		cout << endl << "Queue is empty" << endl ;
		p1.id = 0 ;
		p1.tm = 0 ;
	}
	else
	{
		count-- ;
		p1 = p[front] ;
		front = ( front + 1 ) % MAX ;
	}
	return p1 ;
}

int queue :: size( )
{
	return count ;
}

int queue :: empty( )
{
	return ( count <= 0 ) ;
}

int queue :: full( )
{
	return ( count >= MAX ) ;
}

class airport
{
	private :

		queue landing ;
		queue takeoff ;
		queue *pl ;
		queue *pt ;
		int idletime ;
		int landwait, takeoffwait ;
		int nland, nplanes, nrefuse, ntakeoff ;
		plane pln ;

	public :

		airport( ) ;
		void start ( int *endtime, double *expectarrive, double *expectdepart ) ;
		void newplane ( int curtime, int action ) ;
		void refuse ( int action ) ;
		void land ( plane pl, int curtime ) ;
		void fly ( plane pl, int curtime ) ;
		void idle ( int curtime ) ;
		void conclude ( int endtime ) ;
		int randomnumber( double expectedvalue ) ;
		void addqueue ( char type ) ;
		plane delqueue ( char type ) ;
		int size ( char type ) ;
		int full ( char type ) ;
		int empty ( char type ) ;
		void myrandomize ( void ) ;
} ;

airport :: airport( )
{
	pl = &landing ;
	pt = &takeoff ;
	nplanes = nland = ntakeoff = nrefuse = 0 ;
	landwait = takeoffwait = idletime = 0 ;
}

void airport :: start ( int *endtime, double *expectarrive, double *expectdepart )
{
	int flag = 0 ;
	char wish ;
	cout << endl ;
	cout << "Program that simulates an airport with only one runway." << endl ;
	cout << "One plane can land or depart in each unit of time." << endl ;
	cout << "Up to " << MAX << " planes can be waiting to land or take off at any time." << endl ;
	cout << "How many units of time will the simulation run?" ;
	cin >> *endtime ;
	myrandomize( ) ;
	do
	{
		cout << endl ;
		cout << "Expected number of arrivals per unit time? " ;
		 cin >> *expectarrive ;
		cout << endl ;
		cout << "Expected number of departures per unit time? " ;
		 cin >> *expectdepart ;
		if ( *expectarrive < 0.0 || *expectdepart < 0.0 )
		{
			cout << "These numbers must be nonnegative." << endl ;
			flag = 0 ;
		}
		else
		{
			if ( *expectarrive + *expectdepart > 1.0 )
			{
				cout << "The airport will become saturated. Read new numbers? " ;
				cin >> wish ;
				if ( tolower ( wish ) == 'y' )
					flag = 0 ;
				else
					flag = 1 ;
			}
			else
				flag = 1 ;
		}
	} while ( flag == 0 ) ;
}

void airport :: newplane ( int curtime, int action )
{
	nplanes++ ;
	pln.id = nplanes ;
	pln.tm = curtime ;

	switch ( action )
	{
		case ARRIVE :
			cout << endl ;
			cout << "Plane " << nplanes << " ready to land." << endl ;
			break ;

		case DEPART :
			cout << endl ;
			cout << "Plane " << nplanes << " ready to take off." << endl ;
			break ;
	}
}

void airport :: refuse ( int action )
{
	switch ( action )
	{
		case ARRIVE :

			 cout << "    plane  " << pln.id << " directed to another airport." << endl ;
			 break ;

		case DEPART :

			 cout << "    plane  " << pln.id << " told to try later." << endl ;
			 break ;
	}
	nrefuse++ ;
}

void airport :: land ( plane pl, int curtime )
{
	int wait ;

	wait = curtime - pl.tm ;
	cout << curtime << " : Plane " << pl.id << " landed " ;
	cout << "in queue " << wait << " units " << endl ;
	nland++ ;
	landwait += wait ;
}

void airport :: fly ( plane pl, int curtime )
{
	int wait ;

	wait = curtime - pl.tm ;
	cout << curtime << " : Plane " << pl.id << " took off " ;
	cout << "in queue " << wait << " units " << endl ;
	ntakeoff++ ;
	takeoffwait += wait ;
}

void airport :: idle ( int curtime )
{
	cout << curtime << " : Runway is idle." << endl ;
	idletime++ ;
}

void airport :: conclude ( int endtime )
{
	cout << "Simulation has concluded after " << endtime << " units." << endl ;
	cout << "Total number of planes processed : " << nplanes << endl ;
	cout << "  Number of planes landed : " << nland << endl ;
	cout << "  Number of planes taken off : " << ntakeoff << endl ;
	cout << "  Number of planes refused use : " << nrefuse << endl ;
	cout << "  Number left ready to land : " << size ( 'l' ) << endl ;
	cout << "  Number left ready to take off : " << size ( 't' ) << endl ;

	if ( endtime > 0 )
		cout << "  Percentage of time runway idle : " << ( ( double ) idletime / endtime ) * 100.0 << endl ;

	if ( nland > 0 )
		cout << "  Average wait time to land : " << ( ( double ) landwait / nland ) << endl ;

	if ( ntakeoff > 0 )
		cout << "  Average wait time to take off : " << ( ( double ) takeoffwait / ntakeoff ) << endl ;
}

int airport :: randomnumber ( double expectedvalue )
{
	int n = 0 ;
	double em ;
	double x ;

	em = exp ( -expectedvalue ) ;
	x = rand( ) / ( double ) INT_MAX ;
	while ( x > em )
	{
		n++ ;
		x *= rand( ) / ( double ) INT_MAX ;
	}
	return n ;
}

void airport :: addqueue ( char type )
{
	switch ( tolower( type ) )
	{
		case 'l' :
			  pl -> addqueue ( pln ) ;
			  break ;

		case 't' :
			  pt -> addqueue ( pln ) ;
			  break ;
	}
}

plane airport :: delqueue ( char type )
{
	plane p1 ;
	switch ( tolower ( type ) )
	{
		case 'l' :
			  p1 = pl -> delqueue( ) ;
			  break ;

		case 't' :
			  p1 = pt -> delqueue( ) ;
			  break ;
	}
	return p1 ;
}

int airport :: size ( char type )
{
	switch ( tolower ( type ) )
	{
		case 'l' :
			  return ( pl -> size ( ) ) ;
			  break ;

		case 't' :
			  return ( pt -> size ( ) ) ;
			  break ;
	}
	return 0 ;
}

int airport :: full ( char type )
{
	switch ( tolower ( type ) )
	{
		case 'l' :
			  return ( pl -> full( ) ) ;
			  break ;

		case 't' :
			  return ( pt -> full( ) ) ;
			  break ;
	}
	return 0 ;
}

int airport :: empty ( char type )
{
	switch ( tolower ( type ) )
	{
		case 'l' :
			  return ( pl -> empty( ) ) ;
			  break ;

		case 't' :
			  return ( pt -> empty( ) ) ;
			  break ;
	}
	return 0 ;
}

void airport :: myrandomize ( void )
{
	srand ( ( unsigned int ) ( time ( NULL ) % 10000 ) ) ;
}

void main( )
{
	airport a ;
	int curtime, endtime ;
	int pri ;
	double expectarrive, expectdepart ;
	plane temp ;

	a.start ( &endtime, &expectarrive, &expectdepart ) ;
	for ( curtime = 1 ; curtime <= endtime ; curtime++ )
	{
		pri = a.randomnumber ( expectarrive ) ;

		for ( int i = 1 ; i <= pri ; i++ )
		{
			a.newplane ( curtime, ARRIVE ) ;
			if ( a.full ( 'l' ) )
				 a.refuse ( ARRIVE ) ;
			else
				a.addqueue( 'l' ) ;
		}

		pri = a.randomnumber ( expectdepart ) ;
		for ( i = 1 ; i <= pri ; i++ )
		{
			a.newplane ( curtime, DEPART ) ;
			if ( a.full ( 't' ) )
			   a.refuse ( DEPART ) ;
			else
			   a.addqueue ( 't' ) ;
		}

		if (  ! ( a.empty ( 'l' ) ) )
		{
			temp = a.delqueue ( 'l' ) ;
			a.land ( temp, curtime ) ;
		}
		else
		{
			if ( ! ( a.empty ( 't' ) ) )
			{
				temp = a.delqueue ( 't' ) ;
				a.fly ( temp, curtime ) ;
			}
			else
				a.idle ( curtime ) ;
		}
	}
	a.conclude ( endtime ) ;
}