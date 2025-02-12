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
  vector<vector<int>> adj(N + 1), rev(N + 1);
  for (int i = 0; i < M; i++) {
    int from, to; cin >> from >> to;
    adj[from].push_back(to);
    rev[to].push_back(from);
  }


  vector<bool> visited(N + 1);
  vector<bool> reached(N + 1);
  
  auto inv_dfs = [&](auto&& self, int from) -> void {
    visited[from] = 1;
    for (auto& to : rev[from]) {
      if (!visited[to]) self(self, to);
    }
    return;
  };
  
  auto dfs = [&](auto&& self, int from) -> void {
    reached[from] = 1;
    for (auto& to : adj[from]) {
      if (!reached[to]) self(self, to);
    }
    return;
  };

  inv_dfs(inv_dfs, 1);
  dfs(dfs, 1);

  for (int i = 2; i <= N; i++) {
    if (!visited[i]) {
      cout << "NO\n" << i << ' ' << 1;
      return 0;
    }
    
    if (!reached[i]) {
      cout << "NO\n" << 1 << ' ' << i;
      return 0;
    }
  }

  cout << "YES";

  return 0;
}