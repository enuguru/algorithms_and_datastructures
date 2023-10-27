#include <iostream>

int collatz(int n) {
    int steps = 0;

    while (n != 1) {
        std::cout << n << " ";
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        steps++;
    }

    std::cout << "1" << std::endl;
    return steps;
}

int main() {
    int n;

    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    int steps = collatz(n);

    std::cout << "Total steps taken to reach 1: " << steps << std::endl;

    return 0;
}
