#include<bits/stdc++.h>
using namespace std;



struct dados{double x{}, y{};};

vector<dados> dataset(size_t N, double sigma = 1.0) {

    vector<dados> data;
    data.reserve(N);
    mt19937_64 rng{random_device{}()};
    std::uniform_real_distribution<double> dist_x{0.0, 10.0};
    normal_distribution<double> noise{0.0, sigma};


    for (size_t i = 0; i<N; ++i) {
        double x = dist_x(rng);
        double y=3.0*x + 5.0 + noise(rng);
        data.push_back({x, y});
    }
    return data;


}

pair<double, double> f_linear(const vector<dados>& D) {
    const auto n = static_cast<double>(D.size());
    double sum_x = 0, sum_y = 0, sum_xx = 0, sum_xy = 0;
    for (auto [x, y]: D) {
        sum_x += x;
        sum_y += y;
        sum_xx += x*x;
        sum_xy += x*y;}
    const double denom = n*sum_xx - sum_x*sum_x;
    const double alpha = (n*sum_xx - sum_x*sum_y)/denom;
    const double b = (sum_y*sum_xx - sum_x*sum_xy)/denom;
    return {alpha, b};
}


int main() {

    constexpr::size_t N = 100;
    auto data = dataset(N, 1.0);
    auto [m, b] = f_linear(data);

    cout<<fixed<<setprecision(4);
    cout<<"Coeficiente angular (m): "<<m<<"\n";
    cout<<"Valor de (b):          "<<b<<"\n";

    double x_test;
    cin>>x_test;
    cout<<"Prever valor de x_test:    "<<m*x_test + b<<"\n";
    return 0;
}
