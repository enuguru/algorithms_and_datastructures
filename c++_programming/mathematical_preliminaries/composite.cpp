#include <iostream>

bool isComposite(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return true; // n is a composite number because it's divisible by i
        }
    }
    return false;
}

int main() {
    std::cout << "Composite numbers up to 100 are: " << std::endl;
    for (int i = 2; i <= 100; i++) {
        if (isComposite(i)) {
            std::cout << i << " ";
        }
    }
    return 0;
}
