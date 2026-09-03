#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

double calculate_mean(const std::vector<double>& asset) {
        double sum = 0.0;
        for (double value : asset) {
            sum += value;
        }
        return sum / asset.size();
    }

double calculate_variance(const std::vector<double>& asset, double mean) {
        double squared_diff_sum = 0.0;
        for (double value : asset) {
            double difference = value - mean;
            squared_diff_sum += difference * difference;
        }
        return squared_diff_sum / (asset.size() - 1);
    }

int main() {
    std::vector<double> asset_a = {0.015, -0.002, 0.008, -0.011, 0.005};
    std::vector<double> asset_b = {0.010, -0.005, 0.012, -0.008, 0.003};

    //1. Expected return for asset_a and asset_b
    double mean_a = calculate_mean(asset_a);
    double mean_b = calculate_mean(asset_b);
    

    //2. variance for asset_a and asset_b
    double variance_a = calculate_variance(asset_a, mean_a);
    double variance_b = calculate_variance(asset_b, mean_b);

    // 3. standard deviation for asset_a and asset_b
    double std_dev_a = std::sqrt(variance_a);
    double std_dev_b = std::sqrt(variance_b);

    //4. covariance between asset_a and asset_b
    double covariance_sum = 0.0;
    for (size_t i = 0; i < asset_a.size(); ++i) {
        covariance_sum += (asset_a[i] - mean_a) * (asset_b[i] - mean_b);
    }
    if (asset_a.size() != asset_b.size()) {
        std::cerr << "Error: Asset vectors must be of the same size to calculate covariance.\n";
        return 1;
    }
    double covariance = covariance_sum / (asset_a.size() - 1);

    //5. correlation coefficient between asset_a and asset_b
    double correlation_coefficient = covariance / (std_dev_a * std_dev_b);
    if (std_dev_a == 0 || std_dev_b == 0) {
        std::cerr << "Standard deviation is zero, correlation coefficient is undefined.\n";
        return 1;
    }

    //6. calculate the 95% Value at Risk (VaR) for asset_a and asset_b
    std::sort(asset_a.begin(), asset_a.end());
    std::sort(asset_b.begin(), asset_b.end());
    size_t index_a = static_cast<size_t>(0.05 * asset_a.size());
    size_t index_b = static_cast<size_t>(0.05 * asset_b.size());
    double var_a = -asset_a[index_a];
    double var_b = -asset_b[index_b];

    //7. Output the results
    std::cout << std::fixed; // Set fixed-point notation for floating-point output
    std::cout.precision(4); // Set precision to 4 decimal places
    std::cout << "Expected Return (Asset A): " << mean_a << "\n";
    std::cout << "Expected Return (Asset B): " << mean_b << "\n";
    std::cout << "Variance (Asset A): " << variance_a << "\n";
    std::cout << "Variance (Asset B): " << variance_b << "\n";
    std::cout << "Standard Deviation (Asset A): " << std_dev_a << "\n";
    std::cout << "Standard Deviation (Asset B): " << std_dev_b << "\n";
    std::cout << "Covariance: " << covariance << "\n";
    std::cout << "Correlation Coefficient: " << correlation_coefficient << "\n";
    std::cout << "95% Value at Risk (VaR) (Asset A): " << var_a << "\n";
    std::cout << "95% Value at Risk (VaR) (Asset B): " << var_b << "\n";

    return 0;
}