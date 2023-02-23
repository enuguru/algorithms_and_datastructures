
#include <stdio.h>

void foo() {
    static int x = 5; // assigns value of 5 only once
    x++;
    printf("%d\n", x);
}

int main() {
    foo(); // x = 6
    foo(); // x = 7
    return 0;
}
