#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::vector<double> daily_returns = {0.015, -0.002, 0.008, -0.011, 0.005};

    // 1. Expected return
    double sum = 0.0;
    for (const double& ret : daily_returns) {
        sum += ret;
    }
    double mean = sum / daily_returns.size();

    // 2. variance
    double squared_diff_sum = 0.0;
    for (double ret : daily_returns) {
        squared_diff_sum += std::pow(ret - mean, 2);
    }
    double variance = squared_diff_sum / (daily_returns.size() - 1);

    // 3. standard deviation
    double std_dev = std::sqrt(variance);

    // 4. Output the results
    std::cout << "Expected Return: " << mean << "\n";
    std::cout << "Variance: " << variance << "\n";
    std::cout << "Standard Deviation: " << std_dev << "\n";
}
