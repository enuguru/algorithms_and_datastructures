
#include<stdio.h>

int main() 
{
    float floatType;
    double doubleType;
    long double longdoubleType;

    // sizeof evaluates the size of a variable
    printf("Size of float: %zu bytes\n", sizeof(floatType));
    printf("Size of double: %zu bytes\n", sizeof(doubleType));
    printf("Size of long double: %zu bytes\n", sizeof(longdoubleType));
    
    return 0;
}
