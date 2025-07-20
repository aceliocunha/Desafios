#include <bits/stdc++.h>

using namespace std;


int main() {

    int m;
    cout<<"Tamanho do vetor ";
    cin>>m;
    vector<double> v(m);
    cout<<"Digite os elementos do vetor "<<"\n";
    for (int i = 0; i<m; ++i)
        cin>>v[i];
    sort(v.begin(), v.end());

    auto [min_v, max_v] = minmax_element(v.begin(), v.end());

    cout<<"Mínimo de v = "<<*min_v<<"\n";
    cout<<"Máximo de v = "<<*max_v<<"\n";

    return 0;

}