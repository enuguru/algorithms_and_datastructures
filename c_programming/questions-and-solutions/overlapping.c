#include <stdio.h>
#include <stdbool.h>

bool isOverlapping(int start1, int end1, int start2, int end2) {
    return !(end1 < start2 || end2 < start1);
}

int main() {
    int textLength = 10;
    int starting[] = {1, 1, 6, 7};
    int ending[] = {5, 3, 8, 10};
    int n = sizeof(starting) / sizeof(starting[0]);

    printf("The following combinations can be chosen:\n");

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if the substrings are identical, if yes, skip this pair
            if (starting[i] == starting[j] && ending[i] == ending[j]) {
                continue;
            }
            
            // Check if the substrings are overlapping
            if (!isOverlapping(starting[i], ending[i], starting[j], ending[j])) {
                printf("%d and %d\n", i + 1, j + 1); // i + 1 and j + 1 since we're considering 1-based indexing in the output
            }
        }
    }

    return 0;
}
