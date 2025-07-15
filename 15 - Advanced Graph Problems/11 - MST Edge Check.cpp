#include <bits/stdc++.h>
 
#define int long long
#define endl '\n'
 
using namespace std;
 
const int MOD = 1e9 + 7;
const int INF = 1e18;
 
class DSU {
 public:
  vector<int> p;
  int n;
 
  DSU(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
 
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
 
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n, m; cin >> n >> m;
  vector<array<int, 4>> edges(m);
  for (int i = 0; i < m; i++) {
    int from, to, w; cin >> from >> to >> w;
    edges[i] = {w, from, to, i};
  }
  sort(edges.begin(), edges.end());
  DSU dsu(n + 1);
  vector<int> v(n + 1, INF);
  vector<int> ok(m);
  for (int j = 0; j < m; j++) {
    auto& [w, from, to, i] = edges[j];
    int k = j;
    for (; k < m; k++) {
      if (edges[k][0] != w) break;
    }
    for (int it = j; it < k; it++) {
      auto& [a, b, c, d] = edges[it];
      if (dsu.get(b) == dsu.get(c) && v[b] < w && v[c] < a) continue;
      ok[d] = 1;
    }
    for (int it = j; it < k; it++) {
      auto& [a, b, c, d] = edges[it];
      dsu.unite(b, c);
      v[b] = min(v[b], a);
      v[c] = min(v[c], a);
    } 
    j = k - 1;
  }
  
  for (auto& i : ok) cout << (i ? "YES" : "NO") << endl;  
  
  return 0;
}