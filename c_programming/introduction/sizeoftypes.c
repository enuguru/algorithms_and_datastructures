#include<stdio.h>
int main() {
    int intType;
    long int longintType;
    long long int longlongintType;
    float floatType;
    double doubleType;
    long double longdoubleType;
    char charType;

    // sizeof evaluates the size of a variable
    printf("Size of int: %zu bytes\n", sizeof(intType));
    printf("Size of long int: %zu bytes\n", sizeof(longintType));
    printf("Size of long long int: %zu bytes\n", sizeof(longlongintType));
    printf("Size of float: %zu bytes\n", sizeof(floatType));
    printf("Size of double: %zu bytes\n", sizeof(doubleType));
    printf("Size of long double: %zu bytes\n", sizeof(longdoubleType));
    printf("Size of char: %zu byte\n", sizeof(charType));
    
    return 0;
}
