#include <stdio.h>

// Function to compute the GCD of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to print coprime numbers for each number from 1 to n
void printCoprimes(int n) {
    for (int i = 1; i <= n; i++) {
        printf("Coprimes of %d: ", i);
        for (int j = 1; j <= n; j++) {
            if (gcd(i, j) == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    printCoprimes(10);
    return 0;
}
