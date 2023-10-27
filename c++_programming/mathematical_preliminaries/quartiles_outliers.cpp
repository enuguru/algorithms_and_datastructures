#include <iostream>
#include <vector>
#include <algorithm>

// Function to calculate the first quartile (Q1) of a sorted vector
double firstQuartile(const std::vector<double>& sortedData) {
    int n = sortedData.size();
    int index = n / 4; // Index for Q1
    if (n % 4 == 0) {
        return (sortedData[index - 1] + sortedData[index]) / 2.0;
    } else {
        return sortedData[index];
    }
}

int main() {
    std::vector<double> data = {12.5, 13.2, 14.1, 14.2, 15.3, 15.7, 16.0, 16.2, 16.9, 17.5};

    // Sort the data
    std::sort(data.begin(), data.end());

    int n = data.size();

    // Calculate quartiles
    double minimum = data[0];
    double maximum = data[n - 1];
    double median = n % 2 == 0 ? (data[n / 2 - 1] + data[n / 2]) / 2.0 : data[n / 2];
    double q1 = firstQuartile(data);
    double q3 = firstQuartile(std::vector<double>(data.begin() + n / 2, data.end()));

    // Calculate the interquartile range (IQR)
    double iqr = q3 - q1;

    // Define the lower and upper bounds for outliers
    double lowerBound = q1 - 1.5 * iqr;
    double upperBound = q3 + 1.5 * iqr;

    std::cout << "Minimum: " << minimum << std::endl;
    std::cout << "Maximum: " << maximum << std::endl;
    std::cout << "First Quartile (Q1): " << q1 << std::endl;
    std::cout << "Second Quartile (Median, Q2): " << median << std::endl;
    std::cout << "Third Quartile (Q3): " << q3 << std::endl;
    std::cout << "Interquartile Range (IQR): " << iqr << std::endl;

    // Find and display outliers
    std::cout << "Outliers (if any): ";
    for (const double& value : data) {
        if (value < lowerBound || value > upperBound) {
            std::cout << value << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
