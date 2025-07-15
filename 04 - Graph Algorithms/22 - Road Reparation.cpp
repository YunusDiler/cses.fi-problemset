#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
       int u, v, w; cin >> u >> v >> w;
       adj[--u].push_back({--v, w});
       adj[v].push_back({u, w});
    }
    
    int ans = 0;
    vector<bool> visited(n);
    vector<pair<int, int>> edge(n, {LLONG_MAX, -1});
    edge[0].first = 0;
    
    set<pair<int, int>> s;
    s.insert({0, 0});

    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            cout << "IMPOSSIBLE";
            return 0;
        }

        int v = s.begin()->second;
        visited[v] = true;
        ans += s.begin()->first;
        s.erase(s.begin());

        for (auto [to, w] : adj[v]) {
            if (!visited[to] && w < edge[to].first) {
                s.erase({edge[to].first, to});
                edge[to] = {w, v};
                s.insert({w, to});
            }
        }
    }

    cout << ans << endl;

    return 0;
}