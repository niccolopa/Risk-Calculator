#include <iostream>
#include <vector>

int main() {
    // 1. Define hystorical returns (static typing requires declaring the type 'double')
    std::vector<double> daily_returns = {0.015, -0.002, 0.008, -0.011, 0.005};

    // 2. Calculate the sum
    double sum = 0.0;
    for (const double& ret : daily_returns) {
        sum += ret;
    }

    //3. Calculate the expected return (mean)
    double expected_return = sum / daily_returns.size();

    // 4. Output the expected return
    std::cout << "Expected Return: " << expected_return << "\n";
}
