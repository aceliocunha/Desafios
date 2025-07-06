#include <iostream>
#include <iomanip>
int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double A, B;
    std::cin >> A >> B;
    double media_harmonica = (2.0 * A * B) / (A + B);

    std::cout << std::fixed << std::setprecision(6) << media_harmonica << std::endl;

    return 0;
}
