#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 200000

typedef struct {
    int key;
    int value;
} HashMap;

HashMap map[MAX_SIZE];
int mapSize = 0;

bool contains(int key) {
    for (int i = 0; i < mapSize; i++) {
        if (map[i].key == key) return true;
    }
    return false;
}

int get(int key) {
    for (int i = 0; i < mapSize; i++) {
        if (map[i].key == key) return map[i].value;
    }
    return 0;
}

void put(int key, int value) {
    for (int i = 0; i < mapSize; i++) {
        if (map[i].key == key) {
            map[i].value = value;
            return;
        }
    }
    map[mapSize].key = key;
    map[mapSize].value = value;
    mapSize++;
}

int countValidPairs(int numbers[], int n, int k) {
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (!contains(numbers[i])) {
            put(numbers[i], 1);
        } else {
            put(numbers[i], get(numbers[i]) + 1);
        }
    }

    for (int i = 0; i < n; i++) {
        if (k == 0) {
            if (get(numbers[i]) > 1) {
                count++;
                put(numbers[i], 0);  // Make sure we count this number only once
            }
        } else {
            if (contains(numbers[i] + k)) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int n, k;
    int numbers[MAX_SIZE];
    
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    printf("Enter k: ");
    scanf("%d", &k);

    int result = countValidPairs(numbers, n, k);
    printf("Number of valid (a, b) pairs with difference k: %d\n", result);

    return 0;
}
