#include <stdio.h>
#include <math.h>       // Needed for INFINITY, HUGE_VAL, HUGE_VALF & HUGE_VALL
                        // constants (or macros)
#if !defined(__STDC__)
#   define __STDC__ 0
#endif

#if !defined(__STDC_VERSION__) 
#   define __STDC_VERSION__ 0
#endif


int main()
{
    if (!__STDC__ && !__STDC_VERSION__) printf("The C compiler does not comply with the C89 or later standard!\nIt likely complies with the 1978 K&R C standard (informally known as C78).\n");
    else if (__STDC_VERSION__ >= 201710L) printf("The C compiler complies with the C17 standard.\n");
    else if (__STDC_VERSION__ >= 201112L) printf("The C compiler complies with the C11 standard.\n");
    else if (__STDC_VERSION__ >= 199901L) printf("The C compiler complies with the C99 standard.\n");
    else if (__STDC_VERSION__ >= 199409L) printf("The C compiler complies with the amended C90 standard (also known as C95).\n");
    else if (__STDC__) printf("The C compiler complies with the ANSI C89 / ISO C90 standard.\n");
   
    puts("");
    if (__STDC__) printf("\"__STDC__\": %ld\n", __STDC_VERSION__);
    if (__STDC_VERSION__) printf("\"__STDC_VERSION__\": %ld\n\n", __STDC_VERSION__);
    
    puts("");
    if (__STDC_VERSION__ >= 199901L) printf(" INFINITY (added in C99): %f\n", INFINITY );    // Also works with %lf and %Lf
    if (__STDC_VERSION__ >= 199901L) printf("-INFINITY (added in C99): %f\n", -INFINITY );   // Also works with %lf and %Lf
    
    puts("");
    if (__STDC_VERSION__ >= 199901L) printf(" HUGE_VALF (added in C99): %f\n", HUGE_VALF );
    if (__STDC_VERSION__ >= 199901L) printf("-HUGE_VALF (added in C99): %f\n", -HUGE_VALF );
    
    puts("");
    if (__STDC__) printf(" HUGE_VAL (added in C89 (ANSI) which is the same as C90 (ISO)): %lf\n", HUGE_VAL );
    if (__STDC__) printf("-HUGE_VAL (added in C89 (ANSI) which is the same as C90 (ISO)): %lf\n", -HUGE_VAL );

    puts("");
    if (__STDC_VERSION__ >= 199901L) printf(" HUGE_VALL (added in C99): %Lf\n", HUGE_VALL );
    if (__STDC_VERSION__ >= 199901L) printf("-HUGE_VALL (added in C99): %Lf\n", -HUGE_VALL );

    return 0;
}