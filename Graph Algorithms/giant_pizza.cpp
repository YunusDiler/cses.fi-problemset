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

  int N, M; cin >> M >> N;
  vector<vector<int>> adj(2 * N + 1), rev(2 * N + 1);

  for (int i = 0; i < M; i++) {
    char f, s; 
    int from, to;
    cin >> f >> from >> s >> to;
    adj[2 * from - (f == '+')].push_back(2 * to - (s == '-')); // ~from -> to
    rev[2 * to - (s == '-')].push_back(2 * from - (f == '+')); // to -> ~from
    
    adj[2 * to - (s == '+')].push_back(2 * from - (f == '-')); // ~to -> from
    rev[2 * from - (f == '-')].push_back(2 * to - (s == '+')); // from -> ~to
  }

  vector<bool> visited(2 * N + 1);
  vector<int> order;

  auto dfs1 = [&](auto&& self, int from) -> void {
    visited[from] = 1;
    for (auto& to : adj[from]) {
      if (!visited[to]) self(self, to);
    }
    order.push_back(from);
  };

  vector<int> scc(2 * N + 1);

  auto dfs2 = [&](auto&& self, int from, int counter) -> void {
    scc[from] = counter;
    for (auto& to : rev[from]) {
      if (!scc[to]) self(self, to, counter);
    }
    return;
  };

  for (int i = 1; i <= 2 * N; i++) {
    if (!visited[i]) dfs1(dfs1, i);
  }

  int counter = 1;
  for (int i = 2 * N - 1; i >= 0; i--) {
    if (!scc[order[i]]) dfs2(dfs2, order[i], counter++);
    
  }

  vector<char> ans(N + 1);
  bool flag = false;

  
  for (int i = 1; i <= N && !flag; i++) {
    if (scc[2 * i] == scc[2 * i - 1]) flag = true;
    
    ans[i] = (scc[2 * i - 1] < scc[2 * i] ? '+' : '-');
  }


  if (flag) cout << "IMPOSSIBLE";
  else for (int i = 1; i <= N; i++) cout << ans[i] << ' ';

  return 0;
}