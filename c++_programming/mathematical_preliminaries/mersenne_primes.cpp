#include <iostream>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
        i += 6;
    }
    return true;
}

int main() {
    std::cout << "Mersenne primes up to 2^100 - 1 are: " << std::endl;
    
    for (int n = 2; n <= 10000; n++) {
        long long mersenne = pow(2, n) - 1;
        if (mersenne > 10000) break;  // this condition is needed because we want Mersenne primes till 100 only.
        
        if (isPrime(mersenne)) {
            std::cout << mersenne << " ";
        }
    }

    return 0;
}
