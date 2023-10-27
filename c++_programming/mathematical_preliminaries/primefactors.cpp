#include <iostream>

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

void printPrimeFactors(int n) {
    std::cout << "Prime factors of " << n << ": ";
    
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i) && n % i == 0) {
            while (n % i == 0) {
                std::cout << i << " ";
                n /= i;
            }
        }
    }
    
    std::cout << std::endl;
}

int main() {
    for (int num = 1; num <= 100; ++num) {
        printPrimeFactors(num);
    }

    return 0;
}
