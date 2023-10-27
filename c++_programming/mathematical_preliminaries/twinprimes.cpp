#include <iostream>
#include <vector>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    std::vector<int> twinPrimes;

    for (int i = 2; i <= 100 - 2; ++i) {
        if (isPrime(i) && isPrime(i + 2)) {
            twinPrimes.push_back(i);
        }
    }

    std::cout << "Twin Primes up to 100:" << std::endl;
    for (int prime : twinPrimes) {
        std::cout << "(" << prime << ", " << prime + 2 << ") ";
    }
    std::cout << std::endl;

    return 0;
}
