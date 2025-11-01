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

struct LCA {
  vector<int> height, euler, first, segtree;
  vector<bool> visited;
  int n;

  LCA(vector<vector<int>>& adj, int root = 0) {
    n = adj.size();
    height.resize(n);
    first.resize(n);
    euler.reserve(n * 2);
    visited.assign(n, false);
    dfs(adj, root);
    int m = euler.size();
    segtree.resize(m * 4);
    build(1, 0, m - 1);
  }

  void dfs(vector<vector<int>>& adj, int node, int h = 0) {
    visited[node] = true;
    height[node] = h;
    first[node] = euler.size();
    euler.push_back(node);
    for (auto to : adj[node]) {
      if (!visited[to]) {
        dfs(adj, to, h + 1);
        euler.push_back(node);
      }
    }
  }

  void build(int node, int b, int e) {
    if (b == e) {
      segtree[node] = euler[b];
    } else {
      int mid = (b + e) / 2;
      build(node << 1, b, mid);
      build(node << 1 | 1, mid + 1, e);
      int l = segtree[node << 1], r = segtree[node << 1 | 1];
      segtree[node] = (height[l] < height[r]) ? l : r;
    }
  }

  int query(int node, int b, int e, int L, int R) {
    if (b > R || e < L) return -1;
    if (b >= L && e <= R) return segtree[node];
    int mid = (b + e) >> 1;

    int left = query(node << 1, b, mid, L, R);
    int right = query(node << 1 | 1, mid + 1, e, L, R);
    if (left == -1) return right;
    if (right == -1) return left;
    return height[left] < height[right] ? left : right;
  }

  int lca(int u, int v) {
    int left = first[u], right = first[v];
    if (left > right) swap(left, right);
    return query(1, 0, euler.size() - 1, left, right);
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
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

  LCA lca(adj);

  vector<int> add(n);

  while (q--) {
    int a, b; cin >> a >> b;
    a--; b--;
    if (a == b) {add[a]++; continue;}
    int c = lca.lca(a, b);
    if (a != c) bit.range_add(tin[c], tin[a], 1);
    if (b != c) bit.range_add(tin[c], tin[b], 1);
    if (a != c && b != c) add[c]--;
  }

  for (int i = 0; i < n; i++) {
    int ans = bit.point_query(tin[i]) - bit.point_query(tout[i]);
    cout << ans + add[i] << ' ';
  }

  return 0;
}