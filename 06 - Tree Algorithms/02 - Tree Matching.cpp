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
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> used(n);
  int ans = 0;

  auto Dfs = [&](auto&& self, int from, int parent) -> void {
    for (auto& to : adj[from]) {
      if (to == parent) continue;
      self(self, to, from);
    }
    if (!used[from] && parent != -1 && !used[parent]) {
      used[from] = used[parent] = 1;
      ans++;
    }
    return;
  };

  Dfs(Dfs, 0, -1);

  cout << ans;
  
  return 0;
}