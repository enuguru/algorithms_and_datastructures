#include <stdio.h>

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    int count = 0; // To store the number of 1 bits
    int positions[32]; // To store the positions of 1 bits
    int i;

    for (i = 0; i < 32; i++) {
        if ((n & (1 << i)) != 0) {
            positions[count] = i + 1; // Positions are indexed from 1
            count++;
        }
    }

    printf("Number of 1 bits: %d\n", count);
    printf("Positions of 1 bits in ascending order: ");
    for (i = 0; i < count; i++) {
        printf("%d ", positions[i]);
    }

    return 0;
}
