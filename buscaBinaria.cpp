#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cout<<"Digite o tamanho do vetor: ";
    cin>>n;

    vector<int> v(n);
    cout<<"Digite os elementos do vetor: ""\n";
    for (int i = 0; i < n; ++i)
        cin>>v[i];
    sort(v.begin(), v.end());
    cout<<"Digite o valor a ser buscado: ";
    cin>>x;

    int esq =0, dir = n - 1;
    bool val = false;
    while (esq <= dir) {
        int meio = (esq + dir)/2;
        if (v[meio] == x) {
            cout<<"Valor encontrado na posicao: "<<meio<<"\n";
            val = true;
            break;
        }
        if (v[meio] < x)
            esq = meio + 1;
        else
            dir = meio - 1;
    }
    if (!val)
        cout<<"Valor não encontrado.";


    return 0;
}