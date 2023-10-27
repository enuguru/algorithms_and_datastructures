#include <iostream>
#include <vector>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Factorial primes up to 10,000 are: " << std::endl;

    long long factorial = 1;  // starting from 0! which is 1

    for (int n = 1; ; n++) {
        if (n != 0) {
            factorial *= n;
        }

        // Check for factorial overflows
        if (factorial + 1 > 10000 && factorial - 1 > 10000) break;

        if (factorial - 1 < 10000 && isPrime(factorial - 1)) {
            std::cout << factorial - 1 << " ";
        }

        if (factorial + 1 < 10000 && isPrime(factorial + 1)) {
            std::cout << factorial + 1 << " ";
        }
    }

    return 0;
}
