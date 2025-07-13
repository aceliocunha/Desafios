#include<bits/stdc++.h>
using namespace std;


int soma(auto x, auto y) {

    return x + y;

}


int main() {

    int a, b;
    cin>>a>>b;
    vector<int> vec={1,2,3,4,5};
    cout<<soma(a, b)<<"\n""\n";

    for (auto i : vec) {
        cout<<(soma(a, b))*i<<"\n";
    }
    return 0;

}