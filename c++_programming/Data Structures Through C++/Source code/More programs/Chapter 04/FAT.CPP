// program to read fat

#include <iostream.h>
#include <string.h>
#include <conio.h>
#include <dos.h>
#include <bios.h>
#include <stdlib.h>

struct boot
{
	unsigned char jump[3] ;
	char OEMname[8] ;
	short int bps ;
	unsigned char spc ;
	short int reservedsec ;
	unsigned char fatcopies ;
	short int maxdirentries ;
	short int totalsec ;
	unsigned char mediadesc ;
	short int secperfat ;
	short int secpertrack ;
	short int noofsides ;
	long int hidden ;
	long int hugesec ;
	unsigned char drivenumber ;
	unsigned char reserved ;
	unsigned char bootsignature ;
	long int volumeid ;
	char volumelabel[11] ;
	char filesystype[8] ;
	unsigned char unused[450] ;
} ;

struct boot bs ;
char filetypestr[8] ;

void getfat_12 ( unsigned char *pfat )
{
	int value ;
	int *fatentry ;
	int i, k ;

	for ( k = 2 ; k < 18 ; k++ )
	{
		i = k * 3 / 2 ;

		fatentry =  ( int* ) ( pfat + i ) ;

		if ( ( k % 2 ) == 0 )
			value = ( *fatentry & 0x0fff ) ;
		else
			value = ( *fatentry >> 4 ) ;

		cout << "%03x   " << value ;
		if ( k % 9 == 0 )
			cout << "\n" ;
	}
}

void read_fat_info ( long fat_num )
{
	int j, i ;

	unsigned char *p ;

	if ( strncmp ( "FAT12", filetypestr, 5 ) == 0 )
	{
        p = new unsigned char ;
		absread ( 0, 1, fat_num, p ) ;
		getfat_12 ( p ) ;
	}

	if ( strncmp ( "FAT16", filetypestr, 5 ) == 0 )
	{
		short int *pfat ;
		p = new unsigned char ;
		absread ( 2, 1, fat_num, p ) ;
		pfat = ( short int* ) p ;

		for ( j = 0 ; j < 2 ; j++ )
		{
			cout << "\n   " << j * 8 ;
			for ( i = 0 ; i < 8 ; i++ )
			{
				cout << "%04x  " << *pfat++ ;
			}
		}
	}
}

void fat_info( )
{
	long int first_fat, second_fat ;

	first_fat = bs.reservedsec ;
	second_fat = bs.reservedsec + bs.secperfat ;

	cout << "\n%s Fat Information" << filetypestr ;
	cout << "\n-------------------------------" ;

	cout << "\nFirst FAT Information\n" ;

	read_fat_info ( first_fat ) ;

	cout << "\n\nSecond FAT Information\n" ;

	read_fat_info ( second_fat ) ;
	cout << "\n-------------------------------\n" ;
}

main( )
{
	char choice ;

	clrscr( ) ;

	cout << "A. Drive A" ;
	cout << "\nC. Drive C" ;
	cout << "\n0. Exit" ;

	cout << "\nEnter the drive (A/C): " ;
	cin >> choice ;

	if ( absread ( choice - 65, 1, 0, &bs ) == -1 )
	{
		cout << "Error reading sector" ;
		exit ( 0 ) ;
	}
	else
	{
		strcpy ( filetypestr, bs.filesystype ) ;
		filetypestr[6] = '\0' ;
	}

	fat_info( ) ;
}
