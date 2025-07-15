#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const long long INF = 1e18;

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
    
    vector<long long> dist(n + 1, INF);
    vector<int> visit_count(n + 1);
    vector<bool> in_queue(n + 1);
    vector<int> parent(n + 1, -1);
    vector<bool> is_cycle(n + 1);
    vector<bool> vis(n + 1);
    queue<int> q;
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            q.push(i);
            dist[i] = 0;
            in_queue[i] = true;
        }

        while(!q.empty()) {
            int from = q.front();
            q.pop();
            in_queue[from] = false;
            vis[from] = true;

            for (auto [to, cost] : adj[from]) {
                if (visit_count[to] > n) {
                    is_cycle[to] = true;
                    continue;
                }

                if (dist[from] != INF && dist[to] > dist[from] + cost) {
                    dist[to] = dist[from] + cost;
                    parent[to] = from;
                    if (!in_queue[to]) {
                        q.push(to);
                        in_queue[to] = true;
                    }
                    visit_count[to]++;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (is_cycle[i]) {
            cout << "YES" << endl;
            vector<int> cycle;
            int k = i;
            k = parent[k];
            

            int start = k;
            cycle.push_back(start);
            k = parent[start];
            while (k != start) {
                cycle.push_back(k);
                k = parent[k];
            }
            cycle.push_back(start);
            reverse(cycle.begin(), cycle.end());
            for (auto node : cycle) {
                cout << node << ' ';
            }
            cout << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
