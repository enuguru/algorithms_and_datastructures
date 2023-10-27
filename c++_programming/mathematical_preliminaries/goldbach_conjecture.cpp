#include <iostream>
#include <vector>

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

void goldbachConjecture(int evenNum) {
    if (evenNum <= 2 || evenNum % 2 != 0) {
        std::cout << "Goldbach's Conjecture is not applicable for this number." << std::endl;
        return;
    }

    for (int i = 2; i <= evenNum / 2; ++i) {
        if (isPrime(i) && isPrime(evenNum - i)) {
            std::cout << evenNum << " = " << i << " + " << evenNum - i << std::endl;
        }
    }
}

int main() {
    int evenNum;

    std::cout << "Enter an even integer greater than 2: ";
    std::cin >> evenNum;

    goldbachConjecture(evenNum);

    return 0;
}
