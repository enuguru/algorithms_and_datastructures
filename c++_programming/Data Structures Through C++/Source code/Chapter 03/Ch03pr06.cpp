// Program Ch03pr06
// Program string class

#include <iostream.h>
#include <string.h>
#include <conio.h>

class string
{
	private :

    	char *str ;

    public :

    	string( ) ;
        string ( char *s ) ;
        string ( string& s ) ;
        int length( ) ;
        char operator [] ( int index ) ;
		void operator = ( string s ) ;
		string operator + ( string s ) ;
		void operator += ( string s ) ;
		int operator == ( string s ) ;
		int operator < ( string s ) ;
		int operator > ( string s ) ;
        string mid ( int spos, int n ) ;
        string left ( int n ) ;
        string right ( int n ) ;
        string upper( ) ;
        string lower( ) ;
        string reverse( ) ;
		int replace ( char oldch, char *newch ) ;
		void show( ) ;
        ~string( ) ;
} ;

// initialises the data
string :: string( )
{
	str = NULL ;
}

// initialises the data
string :: string ( char *s )
{
    int l = strlen ( s ) ;
    str = new char [l + 1] ;
	strcpy ( str, s ) ;
}

// copy constructor
string :: string ( string& s )
{
    int l = strlen ( s.str ) ;
    str = new char [l + 1] ;
	strcpy ( str, s.str ) ;
}

// returns the length of string
int string :: length( )
{
	int l = 0 ;
    char *s = str ;
    while ( *s )
    {
        l++ ;
    	s++ ;
    }
    return l ;
}

// gets a char at given position
char string :: operator[] ( int index )
{
	return str[index] ;
}

// assigns strings
void string :: operator = ( string s )
{
	int l = s.length( ) ;
	delete str ;
	str = new char[l + 1] ;
	strcpy ( str, s.str ) ;
}

// concatenates two strings
string string :: operator + ( string s )
{
	int l1 = strlen ( str ) ;
    int l2 = strlen ( s.str ) ;
    int l = l1 + l2 + 1 ;

    char *t = new char [l + 1] ;

    strcpy ( t, str ) ;
    strcat ( t, s.str ) ;

    return t ;
}

// concatenates two strings
void string :: operator += ( string s )
{
	int l1 = strlen ( str ) ;
    int l2 = strlen ( s.str ) ;
    int l = l1 + l2 + 1 ;

    char *t = new char [l + 1] ;

    strcpy ( t, str ) ;
    strcat ( t, s.str ) ;

    delete str ;
    str = new char [l + 1] ;
	strcpy ( str , t ) ;
}

// checks if two strings are equal
int string :: operator == ( string s )
{
	if ( strcmp ( str, s.str ) == 0 )
		return 1 ;
	else
		return 0 ;
}

// compares two strings
int string :: operator < ( string s )
{
	if ( strcmp ( str, s.str ) < 0 )
		return 1 ;
	else
		return 0 ;
}

// compares two strings
int string :: operator > ( string s )
{
  	if ( strcmp ( str, s.str ) > 0 )
		return 1 ;
	else
		return 0 ;
}

// extracts the character at given position
string string :: mid ( int spos, int n )
{
	char *s = str + spos ;
    char *t = new char[n + 1] ;
	int i = 0 ;

	while ( i < n )
    {
    	t[i] = *s ;
        s++ ;
        i++ ;
    }
    t[i] = '\0' ;

    return t ;
}

// extracts leftmost n characters from the string
string string :: left ( int n )
{
	char *t = new char[n + 1] ;
	char *s = str ;
    int i = 0 ;

	while ( i < n )
    {
    	t[i] = *s ;
        s++ ;
        i++ ;
    }
    t[i] = '\0' ;

    return t ;
}

// extracts rightmost n characters from the string
string string :: right ( int n )
{
	char *t = new char[n + 1] ;
    int l = length( ) ;
	char *s = str + ( l - n ) ;
    int i = 0 ;

	while ( i < n && *s )
    {
    	t[i] = *s ;
        s++ ;
        i++ ;
    }
    t[i] = '\0' ;

    return t ;
}

// converts string to uppercase
string string :: upper( )
{
	char *s = str ;
	int l = length( ) ;
	char *t = new char [l + 1] ;
    int i = 0 ;

    while ( *s )
    {
    	if ( *s >= 97 && *s <= 123 )
			t[i] = *s - 32 ;
        else
        	t[i] = *s ;
		s++ ;
        i++ ;
	}
	t[i] = '\0' ;

    return t ;
}

// converts string to lowercase
string string :: lower( )
{
	char *s = str ;
	int l = length( ) ;
	char *t = new char [l + 1] ;
    int i = 0 ;

    while ( *s )
    {
    	if ( *s >= 65 && *s <= 91 )
			t[i] = *s + 32 ;
        else
        	t[i] = *s ;
		s++ ;
        i++ ;
	}
	t[i] = '\0' ;

    return t ;
}

// reverses a string
string string :: reverse( )
{
	int l = length( ) ;
	char *s = str + l - 1 ;
	char *t = new char[l + 1] ;
	int i = 0 ;

	while ( l > 0 )
	{
		t[i] = *s ;
		s-- ;
		l-- ;
		i++ ;
	}
	t[i] = '\0' ;

	return t ;
}

// replaces the occurence of char with new char(s)
int string :: replace ( char oldch, char *newch )
{
	int i = 0 ;
	int l1 = 0 ;
	char *s = newch ;
	int c = 0 ;

	while ( *s )
	{
		l1++ ;
		s++ ;
	}

	int l2 = length( ) ;
	int l = l1 + l2 + 1 ;
	char *t = new char[l+1] ;
	s = str ;

	while ( *s )
	{
		if ( *s == oldch && c == 0 )
		{
			while ( *newch )
			{
				if ( c == 0 )
				{
					*s = *newch ;
					t[i] = *s ;
					s++ ;
				}
				else
					t[i] = *newch ;
				newch++ ;
				i++ ;
				c++ ;
			}
		}
		t[i] = *s ;
		i++ ;
		s++ ;
	}
	t[i] = '\0' ;

	delete str ;
	str = new char[l+1] ;
	strcpy ( str, t ) ;

	return c ;
}

// displays the string
void string :: show( )
{
	cout << str << endl ;
}

// deallocates memeory
string :: ~string( )
{
	delete str ;
}

void main( )
{
    // create new object and display the string
	string s1 ( "Hello" ) ;
    cout << "\nString s1: " ;
    s1.show( ) ;

    // get the length of string in s1
    int l = s1.length( ) ;
    cout << "\nThe length of string s1: " << l << endl ;

    // check for the first occurence of a character
    char ch ;
    cout << "\nEnter character to search: " ;
    cin >> ch ;
    for ( int i = 0 ; i < l ; i++ )
    {
    	if ( s1[i] == ch )
        {
        	cout << "The first occurence of char " << ch << " is found at " << "index no. " << i << endl ;
            break ;
        }
    }


    // create new object and display the string
    string s2 = "Hello World" ;
    cout << "\nString s2: " ;
    s2.show( ) ;

    // assign s1 to new object s3
    string s3 = s1 ;
    cout << "\ns3 = s1: " ;
    s3.show( ) ;

    // adds s1 and s2
	s3 = s1 + s2 ;
    cout << "\ns3 = s1 + s2: " ;
    s3.show( ) ;

    // create new objects s4 and s5 and display strings
    string s4 ( "Hello" ) ;
    cout << "\nString s4: " ;
	s4.show( ) ;
    string s5 ( "Nagpur" ) ;
	cout << "\nString s5: " ;
	s5.show( ) ;

    // adds s5 to s4
    s4 += s5 ;
    cout << "\ns4 += s5: " ;
    s4.show( ) ;

    // compares two strings s1 and s2
    if ( s1 == s2 )
    	cout << "\nStrings s1 and s2 are identical" << endl ;
    if ( s1 < s2 )
    	cout << "\nString s1 is smaller than string s2" << endl ;
    if ( s1 > s2 )
    	cout << "\nString s1 is bigger than string s2" << endl ;

    // creates new object and display string
    string s6 = "Four hundred thirty two" ;
    cout << "\nString s6: " ;
    s6.show( ) ;

	// extract characters at given position
    string s7 = s6.mid ( 5, 7 ) ;
    cout << "\nString s7: " ;
    s7.show( ) ;

    // extract leftmost n characters
	string s8 = s6.left ( 4 ) ;
    cout << "\nString s8: " ;
    s8.show( ) ;

    // extract rightmost n characters
    string s9 = s6.right ( 3 ) ;
    cout << "\nString s9: " ;
    s9.show( ) ;

    // convert string to uppercase
    string s10 = s9.upper( ) ;
    cout << "\nString s10: " ;
    s10.show( ) ;

    // convert string to lowercase
    string s11 = s9.lower( ) ;
    cout << "\nString s11: " ;
    s11.show( ) ;

    // reverse the given string
	string s12 = s11.reverse( ) ;
	cout << "\nString s12: " ;
    s12.show( ) ;

    // replace first occurence of one char with new one
	int r = s1.replace ( 'H' , "M" ) ;
	cout << "\nString s1: " ;
	s1.show( ) ;

    // replace an occurence of one char with group of chars
	r = s1.replace ( 'l', "ooo" ) ;
	cout << "\nString s1: " ;
	s1.show( ) ;
}