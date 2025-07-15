#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int n;
vector<vector<int>> adj(200005);
vector<int> sz(200005);

void dfs(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int centroid(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        if (sz[v] > n / 2) return centroid(v, u);
    }
    return u;
}

int32_t main() {
    need_for_speed
    
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    int c = centroid(1, 0);
    cout << c;
    
    return 0;
}