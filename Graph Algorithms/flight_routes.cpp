#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int INF = 1e18;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
       int u, v, w; cin >> u >> v >> w;
       adj[u].push_back({v, w});
    }
    
    vector<int> visit_count(n + 1, 10);
    vector<vector<int>> dist(n + 1, vector<int>(11, INF));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    while (visit_count[n]) {
        auto [w, from] = pq.top();
        pq.pop();

        if (visit_count[from] <= 0) continue;
        dist[from][10 - visit_count[from]] = w;

        for (auto [to, cost] : adj[from]) {
            if (w + cost < dist[to][10 - visit_count[to]]) pq.push({w + cost, to});
        }
        
        --visit_count[from];
    }

    for (int i = 0; i < k; i++) {
        cout << dist[n][i] << ' ';
    }
    
    return 0;
}