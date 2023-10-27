#include <iostream>
#include <cmath>

// Function to calculate the number of digits in a number
int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        ++count;
    }
    return count;
}

// Function to check if a number is an Armstrong number
bool isArmstrong(int num) {
    int originalNum = num;
    int n = countDigits(num);
    int sum = 0;

    while (num != 0) {
        int digit = num % 10;
        sum += std::pow(digit, n);
        num /= 10;
    }

    return sum == originalNum;
}

int main() {
    std::cout << "Armstrong numbers in the range from 1 to 10,000:" << std::endl;

    for (int i = 1; i <= 10000; ++i) {
        if (isArmstrong(i)) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
