#include <iostream>

bool isPerfect(int num) {
    int sum = 1; // Start with 1 as a divisor since every number is divisible by 1
    
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) {
                sum += num / i;
            }
        }
    }
    
    return sum == num;
}

int main() {
    std::cout << "Perfect numbers from 2 to 10,000 are:" << std::endl;
    
    for (int i = 2; i <= 10000; ++i) {
        if (isPerfect(i)) {
            std::cout << i << " ";
        }
    }
    
    std::cout << std::endl;
    
    return 0;
}
