#include <iostream> 
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a1;
    int q;
    int N;
    std::cin >> a1 >> q >> N;
    long long aN;
    if (N == 1) {
        aN = a1;
    }
    else if (q == 0) {
        aN = 0;
    }
    else if (q == 1) {
        aN = a1;
    }
    else {
        long long power_q_N_minus_1 = 1;
        for (int i = 0; i < N - 1; ++i) {
            power_q_N_minus_1 *= q;
        }
        aN = a1 * power_q_N_minus_1;
    }
    std::cout << aN << std::endl;
    return 0;
}
