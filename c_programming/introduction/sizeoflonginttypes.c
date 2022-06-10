
#include<stdio.h>

int main() 
{
    long longType;
    signed long signedlongType;
    unsigned long unsignedlongType;
    long int longintType;
    signed long int signedlongintType;
    unsigned long int unsignedlongintType;
    long long longlongType;
    signed long long signedlonglongType;
    unsigned long long unsignedlonglongType;
    long long int longlongintType;
    signed long long int signedlonglongintType;
    unsigned long long int unsignedlonglongintType;

    // sizeof evaluates the size of a variable
    printf("Size of long : %zu bytes\n", sizeof(longType));
    printf("Size of signed long : %zu bytes\n", sizeof(signedlongType));
    printf("Size of unsigned long: %zu bytes\n", sizeof(unsignedlongType));
    printf("Size of long int: %zu bytes\n", sizeof(longintType));
    printf("Size of signed long int: %zu bytes\n", sizeof(signedlongintType));
    printf("Size of unsigned long int: %zu bytes\n", sizeof(unsignedlongintType));
    printf("Size of long long: %zu bytes\n", sizeof(longlongType));
    printf("Size of signed long long : %zu bytes\n", sizeof(signedlonglongType));
    printf("Size of unsigned long long : %zu bytes\n", sizeof(unsignedlonglongType));
    printf("Size of long long int: %zu bytes\n", sizeof(longlongType));
    printf("Size of signed long long int: %zu bytes\n", sizeof(signedlonglongintType));
    printf("Size of unsigned long long int: %zu bytes\n", sizeof(unsignedlonglongintType));
    
    return 0;
}
