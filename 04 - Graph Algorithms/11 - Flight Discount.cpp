#include <bits/stdc++.h>
 
#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 
int32_t main() {
    need_for_speed
    
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    { 
       int u, v, c; cin >> u >> v >> c;
       adj[u].push_back({v, c});
    }
    
    vector<vector<int>> dist(2, vector<int>(n + 1, LLONG_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    
    pq.push({0, 1, 0});
    while (!pq.empty())
    {
        auto [w, from, b] = pq.top();
        pq.pop();
 
        if (dist[b][from] <= w) continue;
        dist[b][from] = w;
 
        for (auto [to, cost] : adj[from]) {
            if (!b) {
                if (w + cost / 2 < dist[1][to]) {
                    pq.push({w + cost / 2, to, 1});
                }
            }
            if (dist[b][to] > w + cost) {
                pq.push({w + cost, to, b});
            }
        }
    }
 
    cout << dist[1][n] << endl;
    
    return 0;
}