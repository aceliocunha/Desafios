#include <iostream> 
#include <vector>
#include <cmath> 
#include <iomanip> 
#include <numeric> 

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N; 
    std::cin >> N;

    std::vector<double> x(N); 
    for (int i = 0; i < N; ++i) {
        std::cin >> x[i];
    }
    double sum = 0.0;
    for (int i = 0; i < N; ++i) {
        sum += x[i];
    }
    double mean = sum / N;
    double sum_of_squared_differences = 0.0;
    for (int i = 0; i < N; ++i) {
        double difference = x[i] - mean;
        sum_of_squared_differences += std::pow(difference, 2);
    }
    double sample_std_dev;
    if (N > 1) {
        sample_std_dev = std::sqrt(sum_of_squared_differences / (N - 1));
    } else {
        sample_std_dev = 0.0;
    }
    
    double standard_error_of_mean;
    if (N > 0) {
        standard_error_of_mean = sample_std_dev / std::sqrt(N);
    } else {
        standard_error_of_mean = 0.0;
    }
    
    std::cout << std::fixed << std::setprecision(6) << sample_std_dev << std::endl;
    std::cout << std::fixed << std::setprecision(6) << standard_error_of_mean << std::endl;

    return 0;
}
