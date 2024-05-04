
#include<stdio.h>

int main() 
{
    short int shortintType;
    unsigned short int unsignedshortintType;
    int intType;
    unsigned int unsignedintType;
    long int longintType;
    unsigned long int unsignedlongintType;
    long long int longlongintType;
    unsigned long long int unsignedlonglongintType;
    char charType;
    unsigned char unsignedcharType;
    float floatType;
    double doubleType;
    long double longdoubleType;

    // sizeof evaluates the size of a variable
    printf("Size of short int: %zu bytes\n", sizeof(shortintType));
    printf("Size of unsigned short int: %zu bytes\n", sizeof(unsignedshortintType));
    printf("Size of int: %zu bytes\n", sizeof(intType));
    printf("Size of unsigned int: %zu bytes\n", sizeof(unsignedintType));
    printf("Size of long int: %zu bytes\n", sizeof(longintType));
    printf("Size of unsigned long int: %zu bytes\n", sizeof(unsignedlongintType));
    printf("Size of long long int: %zu bytes\n", sizeof(longlongintType));
    printf("Size of unsigned long long int: %zu bytes\n", sizeof(unsignedlonglongintType));
    printf("Size of char: %zu byte\n", sizeof(charType));
    printf("Size of unsigned char: %zu bytes\n", sizeof(unsignedcharType));
    printf("Size of float: %zu bytes\n", sizeof(floatType));
    printf("Size of double: %zu bytes\n", sizeof(doubleType));
    printf("Size of long double: %zu bytes\n", sizeof(longdoubleType));
}
    
