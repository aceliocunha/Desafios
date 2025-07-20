#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin>>n; vector<int> v(n);
    for (int& x : v){cin>>x;}
    vector<int> ps(n + 1);
    ps[0] = 0;
    for (int i = 0; i < n; i++)
        ps[i + 1] = ps[i] + v[i];
    int a, b ; while (cin>>a>>b)
        cout<<ps[b] - ps[a]<<"\n";
    return 0;
}
