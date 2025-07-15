#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M; cin >> N >> M;
  vector<vector<int>> adj(N + 1);
  for (int i = 0; i < M; i++) {
    int from, to; cin >> from >> to;
    adj[from].push_back(to);
  }

  vector<int> dist(N + 1);
  vector<int> path(N + 1);
  vector<bool> visited(N + 1);
  dist[N] = 1;

  auto dfs = [&](auto&& self, int from) -> void {
    visited[from] = 1;
    int d = 0, child = 0;
    for (auto to : adj[from]) {
      if (!visited[to]) self(self, to);
      if (dist[to] > d) {
        d = dist[to];
        child = to;
      }
    }
    if (d and d >= dist[from]) {
      dist[from] = d + 1;
      path[from] = child; 
    }
  };

  dfs(dfs, 1);
  
  if (!dist[1]) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  cout << dist[1] << endl;
  int node = 1;
  while (node != N) {
    cout << node << ' ';
    node = path[node];
  }
  cout << N;

  return 0;
}