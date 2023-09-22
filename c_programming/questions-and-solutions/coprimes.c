#include <stdio.h>
#include <stdlib.h>

// Function to compute the GCD of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Function to count coprimes for each number in array A
void countCoprimes(int A[], int n, int B[]) {
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 1; j <= A[i]; j++) {
            if (gcd(A[i], j) == 1) {
                count++;
            }
        }
        B[i] = count;
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *A = (int *)malloc(n * sizeof(int));
    int *B = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    countCoprimes(A, n, B);

    printf("Output array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    free(A);
    free(B);
    return 0;
}
