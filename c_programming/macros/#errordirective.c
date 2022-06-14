

#include<stdio.h>  
#include <math.h>
//#define __MATH_H 10
#ifndef __MATH_H  
#error First include then compile  
#else  

int main()
{  
    float a;  
    a=sqrt(7);  
    printf("%f",a);  
    return 0;
}  
#endif
