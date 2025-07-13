#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string nomeVendedor;
    double salarioFixo;
    double totalVendas;
    const double PERCENTUAL_COMISSAO = 0.15;
    cin >> nomeVendedor;
    cin >> salarioFixo;
    cin >> totalVendas;
    
    double comissao = PERCENTUAL_COMISSAO * totalVendas;
    double totalAReceber = salarioFixo + comissao;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "TOTAL = R$ " << totalAReceber << "\n";
    
    return 0;
}