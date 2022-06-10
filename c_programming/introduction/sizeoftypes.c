
#include<stdio.h>

int main() 
{
    int intType;
    signed signedType;
    unsigned unsignedType;
    signed int signedintType;
    unsigned int unsignedintType;
    short shortType;
    short int shortintType;
    short signed int shortsignedintType;
    short signed shortsignedType;
    short unsigned int shortunsignedintType;
    short unsigned shortunsignedType;
    long int longintType;
    long long int longlongintType;
    float floatType;
    double doubleType;
    long double longdoubleType;
    char charType;

    // sizeof evaluates the size of a variable
    printf("Size of int: %zu bytes\n", sizeof(intType));
    printf("Size of signed : %zu bytes\n", sizeof(signedType));
    printf("Size of unsigned : %zu bytes\n", sizeof(unsignedType));
    printf("Size of signed int: %zu bytes\n", sizeof(signedintType));
    printf("Size of unsigned int: %zu bytes\n", sizeof(unsignedintType));
    printf("Size of short: %zu bytes\n", sizeof(shortType));
    printf("Size of short int: %zu bytes\n", sizeof(shortintType));
    printf("Size of short signed : %zu bytes\n", sizeof(shortsignedType));
    printf("Size of short signed int: %zu bytes\n", sizeof(shortsignedintType));
    printf("Size of short unsigned int: %zu bytes\n", sizeof(shortunsignedintType));
    printf("Size of short unsigned : %zu bytes\n", sizeof(shortunsignedType));
    printf("Size of long int: %zu bytes\n", sizeof(longintType));
    printf("Size of long long int: %zu bytes\n", sizeof(longlongintType));
    printf("Size of float: %zu bytes\n", sizeof(floatType));
    printf("Size of double: %zu bytes\n", sizeof(doubleType));
    printf("Size of long double: %zu bytes\n", sizeof(longdoubleType));
    printf("Size of char: %zu byte\n", sizeof(charType));
    
    return 0;
}
