
#include<stdio.h>

int main() 
{
    short shortType;
    short int shortintType;
    short signed int shortsignedintType;
    short signed shortsignedType;
    short unsigned int shortunsignedintType;
    short unsigned shortunsignedType;

    // sizeof evaluates the size of a variable
    printf("Size of short: %zu bytes\n", sizeof(shortType));
    printf("Size of short int: %zu bytes\n", sizeof(shortintType));
    printf("Size of short signed int: %zu bytes\n", sizeof(shortsignedintType));
    printf("Size of short signed : %zu bytes\n", sizeof(shortsignedType));
    printf("Size of short unsigned int: %zu bytes\n", sizeof(shortunsignedintType));
    printf("Size of short unsigned : %zu bytes\n", sizeof(shortunsignedType));
    
    return 0;
}
