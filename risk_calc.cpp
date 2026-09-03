#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    std::vector<double> asset_a = {0.015, -0.002, 0.008, -0.011, 0.005};
    std::vector<double> asset_b = {0.010, -0.005, 0.012, -0.008, 0.003};

    // 1.0 Expected return for asset_a
    double sum_a = 0.0;
    for (const double& ret : asset_a) {
        sum_a += ret;
    }
    double mean_a = sum_a / asset_a.size();

    //1.1 Expected return for asset_b
    double sum_b = 0.0;
    for (const double& ret : asset_b) {
        sum_b += ret;
    }
    double mean_b = sum_b / asset_b.size();

    // 2.0 variance for asset_a
    double squared_diff_sum_a = 0.0;
    for (double ret : asset_a) {
        squared_diff_sum_a += std::pow(ret - mean_a, 2);
    }
    double variance_a = squared_diff_sum_a / (asset_a.size() - 1);

    // 2.1 variance for asset_b
    double squared_diff_sum_b = 0.0;
    for (double ret : asset_b) {
        squared_diff_sum_b += std::pow(ret - mean_b, 2);
    }
    double variance_b = squared_diff_sum_b / (asset_b.size() - 1);

    // 3. standard deviation for asset_a and asset_b
    double std_dev_a = std::sqrt(variance_a);
    double std_dev_b = std::sqrt(variance_b);

    //4. covariance between asset_a and asset_b
    double covariance_sum = 0.0;
    for (size_t i = 0; i < asset_a.size(); ++i) {
        covariance_sum += (asset_a[i] - mean_a) * (asset_b[i] - mean_b);
    }
    double covariance = covariance_sum / (asset_a.size() - 1);

    //5. correlation coefficient between asset_a and asset_b
    double correlation_coefficient = covariance / (std_dev_a * std_dev_b);

    //6. calculate the 95% Value at Risk (VaR) for asset_a and asset_b
    std::sort(asset_a.begin(), asset_a.end());
    std::sort(asset_b.begin(), asset_b.end());
    size_t index_a = static_cast<size_t>(0.05 * asset_a.size());
    size_t index_b = static_cast<size_t>(0.05 * asset_b.size());
    double var_a = asset_a[index_a];
    double var_b = asset_b[index_b];

    //7. Output the results
    std::cout << std::fixed; // Set fixed-point notation for floating-point output
    std::cout.precision(8); // Set precision to 8 decimal places
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