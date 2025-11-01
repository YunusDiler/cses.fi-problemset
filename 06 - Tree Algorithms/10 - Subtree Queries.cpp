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

struct BIT {
  int n;
  std::vector<int> bit;

  BIT(int size) : n(size), bit(size + 1, 0) {}

  void add(int idx, int val) {
    for (; idx <= n; idx += idx & -idx) bit[idx] += val;
  }

  void range_add(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
  }

  int point_query(int idx) {
    int res = 0;
    for (; idx > 0; idx -= idx & -idx) res += bit[idx];
    return res;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  for (auto& i : v) cin >> i;
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> tin(n), tout(n);
  int timer = 1;
  auto Dfs = [&](auto&& self, int from, int parent) -> void {
    tin[from] = timer++;
    for (auto& to : adj[from]) {
      if (to == parent) continue;
      self(self, to, from);
    }
    tout[from] = timer++;
  };

  Dfs(Dfs, 0, -1);
  
  BIT bit(2 * n);
  
  for (int i = 0; i < n; i++) {
    bit.add(tin[i], v[i]);
  }

  while (q--) {
    int t, s; cin >> t >> s;
    s--;
    if (t == 1) {
      int x; cin >> x;
      int dif = x - v[s];
      v[s] = x;
      bit.add(tin[s], dif);
    }
    else {
      int ans = bit.point_query(tout[s]) - bit.point_query(tin[s] - 1);
      cout << ans << endl;
    }
  }

  return 0;
}