#include <bits/stdc++.h>
using namespace std;
constexpr int MAXB = 9;
constexpr int INF  = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, T;
    if (!(cin >> n >> k >> T)) return 0;
    vector<int> qtd(n + 1);
    for (int i = 1;i<=n;++i) cin>> qtd[i];
    vector<int> posAmigo; posAmigo.reserve(k);
    for (int i = 1; i <= n; ++i) {
        int tipo; cin >> tipo;
        if (tipo == 1) posAmigo.push_back(i);
    }
    const int Cmax = k*MAXB;
    vector<vector<int>> dp(k + 1,vector<int>(Cmax + 1,INF)),nxt = dp;
    dp[0][0] = 0;
    for (int a = 1; a <= n; ++a){
        int maxC = min(a*MAXB, Cmax);
        nxt.assign(k + 1, vector<int>(maxC + 1, INF));
        for (int b = 0; b <= min(k, a); ++b){
            for (int c = 0; c <= maxC; ++c)
                nxt[b][c]=dp[b][c];
        }
        for (int b = 1; b <= min(k, a); ++b) {
            int pos = posAmigo[b - 1];
            int dist = abs(a - pos);
            for (int c = qtd[a];c<=maxC; ++c) {
                int prev = dp[b - 1][c - qtd[a]];
                if (prev == INF) continue;
                int val = prev + dist;
                if (val <= T && val < nxt[b][c])
                    nxt[b][c] = val;
            }
        }
        dp.swap(nxt);
    }
    for (int c = Cmax; c >= 0; --c)
        if (dp[k][c] <= T) {
            cout << c << '\n';
            return 0;
        }
    cout << 0 << '\n';
    return 0;
}
