#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = numeric_limits<ll>::max()/2;

struct Edge {
    int to;
    ll w;
};
struct Graph {
    int n;
    std::vector<std::vector<Edge>> adj;
    explicit Graph(int n_nodes) : n(n_nodes), adj(n_nodes) {}
    void add_edge(int u, int v, ll w) {
        adj[u].push_back({v, w /*, -1*/});
    }
};
std::vector<ll> DK(const Graph& g, int s) {
    std::vector<ll> dist(g.n, INF);
    using P = std::pair<ll, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) {
            continue;
        }
        for (const auto& e : g.adj[u]) {
            if (dist[e.to] > dist[u] + e.w) {
                dist[e.to] = dist[u] + e.w;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    return dist;
}

int main() {

    Graph g(5);
    g.add_edge(0, 1, 2);
    g.add_edge(1, 2, 3);
    g.add_edge(0, 3, 6);
    g.add_edge(3, 4, 1);
    g.add_edge(4, 2, 1);
    vector<ll> dist = DK(g, 0);
    cout << dist[2] << "\n";
    return 0;
}