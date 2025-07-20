#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin>>n;

    vector<int>num(n);
    for (int i = 0; i < n; i++){
        cin>>num[i];
    }
    vector<int>partial_sum(n + 1, 0);
    for (int i = 0; i < n; i++){
        partial_sum[i + 1] = partial_sum[i] + num[i]; 
    }

    int q; 
    cin>>q;
    for (int i = 0; i < q; i++){
        int l, r;
        cin>>l>>r;

        int sum = partial_sum[r + 1] - partial_sum[l];
        cout<<sum<<"\n";
    }
    return 0;

}


/*

5
1 2 3 4 5
3
0 2
1 3
2 4

saida:
6
9
12
*/