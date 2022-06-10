
#include<stdio.h>

int main() 
{
    int intType;
    signed signedType;
    unsigned unsignedType;
    signed int signedintType;
    unsigned int unsignedintType;

    // sizeof evaluates the size of a variable
    printf("Size of int: %zu bytes\n", sizeof(intType));
    printf("Size of signed : %zu bytes\n", sizeof(signedType));
    printf("Size of unsigned : %zu bytes\n", sizeof(unsignedType));
    printf("Size of signed int: %zu bytes\n", sizeof(signedintType));
    printf("Size of unsigned int: %zu bytes\n", sizeof(unsignedintType));
    
    return 0;
}
