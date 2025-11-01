#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 31
#endif

const int MOD = 1e9 + 7;
const int INF = 1e18;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n; cin >> n;
  vector<int> v(n), ans(n, 1);
  for (auto& i : v) cin >> i;
  
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<set<int>> s(n);
  for (int i = 0; i < n; i++) s[i].insert(v[i]);

  auto dfs = [&](auto&& self, int node, int parent) -> void {
    for (auto& to : adj[node]) {
      if (to == parent) continue;
      self(self, to, node);
      if (s[node].size() < s[to].size()) swap(s[node], s[to]);
      for (auto& i : s[to]) s[node].insert(i);
      ans[node] = s[node].size();
    }
  };

  dfs(dfs, 0, -1);

  for (auto& i : ans) cout << i << ' ';
  
  return 0;
}