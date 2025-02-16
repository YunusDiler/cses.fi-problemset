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
  vector<int> coins(N + 1);
  vector<vector<int>> adj(N + 1), rev(N + 1);

  for (int i = 1; i <= N; i++) {
    cin >> coins[i];
  }
  for (int i = 0; i < M; i++) {
    int from, to; cin >> from >> to;
    adj[from].push_back(to);
    rev[to].push_back(from);
  }

  vector<bool> visited(N + 1);
  vector<int> order;

  auto dfs1 = [&](auto&& self, int from) -> void {
    visited[from] = 1;
    for (auto& to : adj[from]) {
      if (!visited[to]) self(self, to);
    }
    order.push_back(from);
  };

  vector<int> scc(N + 1);

  auto dfs2 = [&](auto&& self, int from, int component) -> void {
    scc[from] = component;
    for (auto& to : rev[from]) {
      if (!scc[to]) self(self, to, component);
    }
    return;
  };

  for (int i = 1; i <= N; i++) {
    if (!visited[i]) dfs1(dfs1, i);
  }

  int component = 1;
  for (int i = N - 1; i >= 0; i--) {
    if (!scc[order[i]]) dfs2(dfs2, order[i], component++);
  }

  vector<int> sum(component);
  for (int i = 1; i <= N; i++) {
    sum[scc[i]] += coins[i];
  }

  vector<vector<int>> cadj(component);
  for (int i = 1; i <= N; i++) {
    for (auto& to : adj[i]) {
      if (scc[i] != scc[to]) cadj[scc[i]].push_back(scc[to]);
    }
  }

  vector<int> ans(component);

  auto dfs3 = [&](auto&& self, int from) -> void {
    ans[from] += sum[from];
    int x = 0;
    for (auto& to : cadj[from]) {
      if (!ans[to]) self(self, to);
      x = max(x, ans[to]);
    }
    ans[from] += x;
    return;
  };

  for (int i = 1; i < component; i++) {
    if (!ans[i]) dfs3(dfs3, i);
  }

  cout << *max_element(ans.begin(), ans.end());


  return 0;
}