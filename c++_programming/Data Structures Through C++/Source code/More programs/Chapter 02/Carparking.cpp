// Vehicle parking program

#include <iostream.h>
#include <conio.h>

// the base class vehicle for both car/scooter
class vehicle
{
	protected :

		static int parkinfo[4][10] ;  // a 2-D array to store number of vehicle parked
		int num, row, col ;	              // to store vehicle number, and its
										  // row-col position in an array
		static int vehcount ;	     	  // to store total count of vehicles

	public :

		static void display( ) ;
		static int getvcount( ) ;
} ;

// initialize static data member
int vehicle :: parkinfo[4][10] = {
									   0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,
									   0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,
									   0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,
									   0, 0, 0, 0, 0, 0, 0, 0, 0, 0
									 } ;
int vehicle :: vehcount = 0 ;

// this function displays the list of vehicles parked
void vehicle :: display( )
{
    cout << "Cars ->" << endl ;
    for ( int r = 0 ; r < 4 ; r++ )
    {
        if ( r == 2 )
			cout << "Scooters ->" << endl ;

		for ( int  c = 0 ; c < 10 ; c++ )
           cout << parkinfo[r][c] << "  " ;
		cout << endl ;
	}
}

// returns the total number of vehicles
int vehicle :: getvcount( )
{
	return vehcount ;
}

// car class to hold data of objects of car
class car : public vehicle
{
	private :

		static int carcount ;	// stores total count of cars

	public :

		car( ) ;
		car ( int n, int r, int c ) ;
		void changecol( ) ;
		void add( ) ;
		void del( ) ;
		static void getfreerowcol( int *arr ) ;
		static void getrcbyinfo ( int info, int *arr ) ;
		static int getcarcount( ) ;

		void show( ) ;
} ;

// initialize static data member
int car :: carcount = 0 ;

// zero-argument constructor
car :: car( )
{
}

// a three-argument constructor
car :: car ( int n, int r, int c )
{
	num = n ;
	row = r ;
	col = c ;
}

// decrements the col. number by one
// this fun. is called when the data is
// shifted one place to left
void car :: changecol( )
{
	col = col - 1 ;
}

// adds a data of car in an array
void car :: add( )
{
	carcount++ ;
	vehcount++ ;
	parkinfo[row][col] = num ;
}

// deletes the data of the specified 
// car from the array, if found
void car :: del( )
{
	for (  int c = col ; c < 9 ; c++ )
			parkinfo[row][c] = parkinfo[row][c + 1] ;
	parkinfo[row][c] = 0 ;
	carcount-- ;
	vehcount-- ;
}

// get the row-col position for the vehicle to be parked
void car :: getfreerowcol( int *arr )
{
	int found = 0 ;
	for ( int i = 0 ; i < 2 ; i++ )
	{
		for ( int j = 0 ; j < 10 ; j++ )
		{
			if ( parkinfo[i][j] == 0 )
			{
				arr[0] = i ;
				arr[1] = j ;
				found = 1 ;
				break ;
			}
		}
		if ( found == 1 )
			break ;
	}

	if ( i == 2 )
	{
    	arr[0] = -1 ;
		arr[1] = -1 ;
    }
}

// get the row-col position for the car with specified car number
void car :: getrcbyinfo ( int info, int *arr )
{
	int found = 0 ;
	for ( int r = 0 ; r < 2 ; r++ )
	{
		for ( int  c = 0 ; c < 10 ; c++ )
		{
			if ( parkinfo[r][c] == info )
			{
				arr[0] = r ;
				arr[1] = c ;
				found = 1 ;
				break ;
			}
		}
		if ( found == 1 )
			break ;
	}
	if ( r == 2 )
	{
		arr[0] = -1 ;
		arr[1] = -1 ;
	}
}

// returns the total number of cars
int car :: getcarcount( )
{
	return carcount ;
}

// a scooter class to hold objects of scooters
class scooter : public vehicle
{
	private :

		static int scootcount ;

	public :

		scooter( ) ;
		scooter ( int n, int r, int c ) ;
		void changecol( ) ;
		void add( ) ;
		void del( ) ;
		static void getfreerowcol ( int *arr ) ;
		static void getrcbyinfo ( int info, int *arr ) ;
		static int getscootcount( ) ;
} ;

// initialises static data member
int scooter :: scootcount = 0 ;

// zero-argument constructor
scooter :: scooter( )
{
}

// three-argument constructor
scooter :: scooter ( int n, int r, int c )
{
	num = n ;
	row = r ;
	col = c ;
}

// decrements the col. number by one
// this fun. is called when the data is
// shifted one place to left
void scooter :: changecol( )
{
	col = col - 1 ;
}

// adds data of scooter in an array
void scooter :: add( )
{
	parkinfo[row][col] = num ;
	scootcount++ ;
	vehcount++ ;
}

// removes data of scooter
void scooter :: del( )
{
	for (  int c = col ; c < 9 ; c++ )
		parkinfo[row][c] = parkinfo[row][c + 1] ;
	parkinfo[row][c] = 0 ;
	scootcount-- ;
	vehcount-- ;
}

// get the row-col position free where a scooter can be parked
void scooter :: getfreerowcol( int *arr )
{
	int found = 0 ;
	for ( int r = 2 ; r < 4 ; r++ )
	{
		for ( int c = 0 ; c < 10 ; c++ )
		{
			if ( parkinfo[r][c] == 0 )
			{
				arr[0] = r ;
				arr[1] = c ;
				found = 1 ;
				break ;
			}
		}
		if ( found == 1 )
			break ;
	}
}

// get row-col position where given scooter has been parked
void scooter :: getrcbyinfo ( int info, int *arr )
{
	int found = 0 ;
	for ( int r = 2 ; r < 4 ; r++ )
	{
		for ( int c = 0 ; c < 10 ; c++ )
		{
			if ( parkinfo[r][c] == info )
			{
				arr[0] = r ;
				arr[1] = c ;
				found = 1 ;
				break ;
			}
		}
		if ( found == 1 )
			break ;
	}
	if ( r == 4 )
	{
		arr[0] = -1 ;
		arr[1] = -1 ;
	}
}

// returns total  number of scooters parked
int scooter :: getscootcount( )
{
	return scootcount ;
}

void main( )
{
	int choice ;
	int type ;
	int number, row = 0, col = 0 ;
	int tarr[2] ;
	int finish = 1 ;
    char k ;

	// creates a 2-D array of car and scooter class
	car *c[2][10] ;
	scooter *sc[2][10] ;

    clrscr( ) ;

	// displays menu and calls corresponding functions
	while ( finish )
	{
        clrscr( ) ;

		cout << endl ;
		cout << "Car Parking" << endl ;
		cout << "1. Arrival of a vehicle" << endl ;
		cout << "2. Total no. of vehicles parked" << endl ;
		cout << "3. Total no. of cars parked" << endl ;
		cout << "4. Total no. of scooters parked" << endl ;
		cout << "5. Display order in which vehicles are parked" << endl ;
		cout << "6. Departure of vehicle" << endl ;
		cout << "7. Exit" << endl ;
		cin >> choice ;

		switch ( choice )
		{
			case  1 :

                clrscr( ) ;
				cout << endl ;
				cout << "Add :" << endl ;

                type = 0 ;

                // check for vehicle type
                while ( type != 1 && type != 2 )
                {
					cout << "Enter vehicle type (1 for Car / 2 for Scooter ): " << endl ;
                    cin >> type ;
	                if ( type != 1 && type != 2 )
						cout << "\nInvalid vehicle type." << endl ;
                }

				cout << "Enter vehicle number: " ;
				cin >> number ;

				// add cars' data
				if ( type == 1 )
				{
					car :: getfreerowcol( tarr ) ;
					if ( tarr[0] != -1 && tarr[1] != -1 )
					{
						row = tarr[0] ;
						col = tarr[1] ;
						c[row][col] = new car ( number, row, col ) ;
						c[row][col] -> add( ) ;
					}
					else
						cout << "\nNo parking slot free to park a car" << endl ;
				}
				else
				{
					// add scooters' data
					if ( type == 2 )
					{
						scooter :: getfreerowcol( tarr ) ;
						if ( tarr[0] != -1 && tarr[1] != -1 )
						{
							row = tarr[0] ;
							col = tarr[1] ;
							sc[row - 2][col] = new scooter ( number, row, col ) ;
							sc[row - 2][col] -> add( ) ;
						}
						else
							cout << "\nNo parking slot free to park a scooter" << endl ;
					}
					else
					{
						cout << "Invalid type" << endl ;
						break ;
					}
				}

                cout << "\nPress any key to continue..." ;
                cin >> k ;
				break ;

			case  2 :

                clrscr( ) ;
				cout << "Total vehicles parked : " << vehicle :: getvcount( ) << endl ;

                cout << "\nPress any key to continue..." ;
                cin >> k ;

				break ;

			case  3 :

                clrscr( ) ;
				cout << "Total cars parked : " << car :: getcarcount( ) << endl ;

                cout << "\nPress any key to continue..." ;
                cin >> k ;

				break ;

			case  4 :

                clrscr( ) ;
				cout << "Total scooters parked : " << scooter :: getscootcount( ) << endl ;

                cout << "\nPress any key to continue..." ;
                cin >> k ;

				break ;

			case  5 :

                clrscr( ) ;
				cout << "Display" << endl ;
				vehicle :: display( ) ;

                cout << "\nPress any key to continue..." ;
                cin >> k ;
				break ;

			case  6 :

                clrscr( ) ;
				cout << "Departure" << endl ;

                type = 0 ;

                // check for vehicle type
                while ( type != 1 && type != 2 )
                {
					cout << "Enter vehicle type (1 for Car / 2 for Scooter ) : " << endl ;
                    cin >> type ;
	                if ( type != 1 && type != 2 )
						cout << "\nInvalid vehicle type." << endl ;
                }
				cout << "Enter number: "  ;
				 cin >> number ;

				// if a car is about to move
				if ( type == 1 )
				{
					car :: getrcbyinfo ( number, tarr ) ;
					if ( tarr[0] != -1 && tarr[1] != -1 )
					{
						row = tarr [0] ;
						col = tarr [1] ;
						c[row][col] -> del( ) ;
						for ( int i = col ; i < 9 ; i++ )
						{
							c[row][i] = c[row][i + 1] ;
							c[row][i] -> changecol( ) ;
						}
						c[row][i] = new car ( 0, 0, 0 ) ;
					}
					else
                		cout << "\nInvalid car number, or a car with such number has not been parked here." << endl ;				}
				else
				{
					// if a scooter is about to move
					if ( type == 2 )
					{
						scooter :: getrcbyinfo ( number, tarr ) ;
						if ( tarr[0] != -1 && tarr[1] != -1 )
						{
							row = tarr[0] - 2 ;
							if ( ! ( row < 0 ) )
							{
								col = tarr[1] ;
								sc[row][col] -> del( ) ;
								for ( int i = col ; i < 9 ; i++ )
								{
									sc[row][i] = sc[row][i + 1] ;
									sc[row][i] -> changecol( ) ;
								}
								sc[row][i] = new scooter ( 0, 0, 0 ) ;
							}
						}
						else
						  cout << "\nInvalid scooter number, or a scooter with such number has not been parked here." << endl ;
					}
				}

                cout << "\nPress any key to continue..." ;
                cin >> k ;

				break ;

			case  7 :

                clrscr( ) ;
				finish = 0 ;
				break ;

		}
	}
}
