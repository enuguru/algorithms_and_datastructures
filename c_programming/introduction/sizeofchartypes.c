
#include<stdio.h>

int main() 
{
    char charType;
    signed char signedcharType;
    unsigned char unsignedcharType;

    // sizeof evaluates the size of a variable
    printf("Size of char: %zu byte\n", sizeof(charType));
    printf("Size of signed char: %zu byte\n", sizeof(signedcharType));
    printf("Size of unsigned char: %zu byte\n", sizeof(unsignedcharType));
    
    return 0;
}
