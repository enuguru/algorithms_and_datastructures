#include <iostream>
#include <vector>
#include <cmath>

// Function to calculate the mean of a vector of numbers
double mean(const std::vector<double>& data) {
    double sum = 0.0;
    for (const double& num : data) {
        sum += num;
    }
    return sum / data.size();
}

// Function to calculate the Pearson correlation coefficient
double correlationCoefficient(const std::vector<double>& x, const std::vector<double>& y) {
    if (x.size() != y.size() || x.size() == 0) {
        return 0.0; // Correlation coefficient is undefined for different-sized or empty sets
    }

    double meanX = mean(x);
    double meanY = mean(y);
    double numerator = 0.0;
    double denominatorX = 0.0;
    double denominatorY = 0.0;

    for (size_t i = 0; i < x.size(); ++i) {
        numerator += (x[i] - meanX) * (y[i] - meanY);
        denominatorX += std::pow(x[i] - meanX, 2);
        denominatorY += std::pow(y[i] - meanY, 2);
    }

    if (denominatorX == 0.0 || denominatorY == 0.0) {
        return 0.0; // Correlation coefficient is undefined if the denominator is zero
    }

    return numerator / (std::sqrt(denominatorX) * std::sqrt(denominatorY));
}

int main() {
    // Example data for sets x and y
    std::vector<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> y = {2.0, 3.0, 5.0, 4.0, 6.0};

    double correlation = correlationCoefficient(x, y);

    std::cout << "Correlation Coefficient: " << correlation << std::endl;

    return 0;
}
