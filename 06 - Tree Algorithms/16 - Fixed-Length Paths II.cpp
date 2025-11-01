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
  
  int n, k1, k2; cin >> n >> k1 >> k2;
  vector<vector<int>> adj(n);
  int ans = 0;
  for (int i = 1; i < n; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  auto idx = [&](deque<int>& d, int i) -> int {
    if (i < 0) return d[0];
    if (i >= d.size()) return 0;
    return d[i];
  };

  auto Merge = [&](deque<int>& a, deque<int>& b) -> void {
    if (b.size() > a.size()) swap(a, b);
    for (int i = 0; i < (int)b.size(); i++) {
      ans += 1ll * (idx(b, i) - idx(b, i + 1)) * (idx(a, k1 - i) - idx(a, k2 - i + 1));
    }
    for (int i = 0; i < (int)b.size(); i++) {
      a[i] += b[i];
    }
  };

  auto Dfs = [&](auto&& self, int from, int parent) -> deque<int> {
    deque<int> d = {1};
    for (auto& to : adj[from]) {
      if (to == parent) continue;
      auto cd = self(self, to, from);
      cd.push_front(cd.front());
      Merge(d, cd);
    }
    return d;
  };
  
  Dfs(Dfs, 0, -1);
  cout << ans;
  return 0;
}