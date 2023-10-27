#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

// Function to calculate the mean of a vector of numbers
double mean(const std::vector<double>& data) {
    double sum = 0.0;
    for (const double& num : data) {
        sum += num;
    }
    return sum / data.size();
}

// Function to calculate the median of a vector of numbers
double median(const std::vector<double>& data) {
    std::vector<double> sortedData = data;
    std::sort(sortedData.begin(), sortedData.end());
    size_t size = sortedData.size();
    if (size % 2 == 0) {
        return (sortedData[size / 2 - 1] + sortedData[size / 2]) / 2.0;
    } else {
        return sortedData[size / 2];
    }
}

// Function to calculate the mode of a vector of numbers
std::vector<double> mode(const std::vector<double>& data) {
    std::map<double, int> frequency;
    for (const double& num : data) {
        frequency[num]++;
    }

    int maxFrequency = 0;
    std::vector<double> modes;
    for (const auto& pair : frequency) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            modes.clear();
            modes.push_back(pair.first);
        } else if (pair.second == maxFrequency) {
            modes.push_back(pair.first);
        }
    }

    return modes;
}

// Function to calculate the variance of a vector of numbers
double variance(const std::vector<double>& data) {
    double meanValue = mean(data);
    double sumOfSquares = 0.0;
    for (const double& num : data) {
        sumOfSquares += std::pow(num - meanValue, 2);
    }
    return sumOfSquares / data.size();
}

// Function to calculate the standard deviation of a vector of numbers
double standardDeviation(const std::vector<double>& data) {
    return std::sqrt(variance(data));
}

int main() {
    std::vector<double> data;
    int n;

    std::cout << "Enter the number of data points: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Please enter a positive number of data points." << std::endl;
        return 1;
    }

    std::cout << "Enter the data points, one at a time:" << std::endl;
    for (int i = 0; i < n; ++i) {
        double num;
        std::cin >> num;
        data.push_back(num);
    }

    double meanValue = mean(data);
    double medianValue = median(data);
    std::vector<double> modes = mode(data);
    double varianceValue = variance(data);
    double stdDeviation = standardDeviation(data);

    std::cout << "Descriptive Statistics:" << std::endl;
    std::cout << "Mean: " << meanValue << std::endl;
    std::cout << "Median: " << medianValue << std::endl;
    
    if (!modes.empty()) {
        std::cout << "Mode(s): ";
        for (size_t i = 0; i < modes.size(); ++i) {
            std::cout << modes[i];
            if (i < modes.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "No mode found." << std::endl;
    }

    std::cout << "Variance: " << varianceValue << std::endl;
    std::cout << "Standard Deviation: " << stdDeviation << std::endl;

    return 0;
}
