#include <iostream>
#include <vector>
#include <numeric> 
std::vector<bool> visited;
std::vector<std::vector<int>> adj;

void dfs(int u) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}
int connected_components(int N) {

    visited.assign(N + 1, false); 
    
    int count = 0;

    for (int u = 1; u <= N; ++u) {
        if (!visited[u]) { 
            count++; 
            dfs(u);
        }
    }
    return count;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    adj.assign(N + 1, std::vector<int>());
    for (int i = 0; i < M; ++i) {
        int U, V;
        std::cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }
    int num_components = connected_components(N);
    std::cout << num_components << std::endl;
    return 0;
}
