
#include <stdio.h>

/*
Binutils 2.24 gives an error and refuses to link.
https://stackoverflow.com/questions/27667277/why-does-borland-compile-with-multiple-definitions-of-same-object-in-different-c
*/
/*int i = 0;*/

/* Works in GCC as an extension: https://stackoverflow.com/a/3692486/895245 */
/*int i;*/

/* OK: extern. Will use the one in main. */
extern int i;

/* OK: only visible to this file. */
int si = 0;
//int si;

void a() {
    i++;
    si++;
    puts("a()");
    printf("i = %d\n", i);
    printf("si = %d\n", si);
    puts("");
}
