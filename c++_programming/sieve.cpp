#include <iostream>
#include <vector>

void SieveOfEratosthenes(int n) {
    std::vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false; // 0 and 1 are not primes
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false; // mark multiples of p as non-prime
            }
        }
    }
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            std::cout << p << " ";
        }
    }
}

int main() {
    int n = 100;
    SieveOfEratosthenes(n);
    return 0;
}
