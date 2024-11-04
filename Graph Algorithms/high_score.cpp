#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
       int from, to, cost; cin >> from >> to >> cost;
       adj[from].push_back({to, cost});
    }
    
    vector<int> dist(n + 1, LLONG_MIN);
    vector<int> visit_count(n + 1);
    vector<bool> in_queue(n + 1);
    vector<int> parent(n + 1, -1);
    vector<bool> is_cycle(n + 1);
    queue<int> q;

    dist[1] = 0;
    q.push(1);
    in_queue[1] = true;

    while(!q.empty()) {
        int from = q.front();
        q.pop();
        in_queue[from] = false;

        for (auto [to, cost] : adj[from]) {
            if (visit_count[to] > n) {
                is_cycle[to] = true;
                for (auto [next, t] : adj[to]) {
                    is_cycle[next] = true;
                }
                continue;
            }

            if (dist[to] < dist[from] + cost) {
                dist[to] = dist[from] + cost;
                parent[to] = from;
                if (!in_queue[to]) q.push(to);
                visit_count[to]++;
            }
        }
    }

    for (int i = n; ~i; i = parent[i]) {
        if (is_cycle[i]) {
            cout << -1;
            return 0;
        }
    }
    cout << dist[n];
    
    return 0;
}