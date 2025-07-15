#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const int MOD = 1e9 + 7;

int32_t main() {
    need_for_speed
    
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> edges(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].push_back({b, c});
    }

    vector<bool> visited(n + 1);
    vector<int> dist(n + 1, LLONG_MAX);
    vector<int> count(n + 1);
    vector<int> min_flight(n + 1);
    vector<int> max_flight(n + 1);

    priority_queue<pair<int, int>> pq;

    pq.push({0, 1});
    dist[1] = 0;
    count[1] = min_flight[1] = max_flight[1] = 1;  

    while (!pq.empty()) {
        auto [cost, from] = pq.top();
        pq.pop();
        if (visited[from]) continue;
        visited[from] = true;

        for (auto [to, price] : edges[from]) {
            if (visited[to]) continue;
            if (dist[to] > dist[from] + price) {
                dist[to] = dist[from] + price;
                count[to] = count[from];
                min_flight[to] = min_flight[from] + 1;
                max_flight[to] = max_flight[from] + 1;
                pq.push({-dist[to], to});
            }
            else if (dist[to] == dist[from] + price) {
                count[to] = (count[to] + count[from]) % MOD; 
                min_flight[to] = min(min_flight[from] + 1, min_flight[to]);
                max_flight[to] = max(max_flight[from] + 1, max_flight[to]);
            }
        }
    }

    cout << dist[n] << ' ' << count[n] << ' ' << min_flight[n] - 1 << ' ' << max_flight[n] - 1;
    
    return 0;
}