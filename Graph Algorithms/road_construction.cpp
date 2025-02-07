#include <bits/stdc++.h>

using namespace std;

class dsu {
 public:
  vector<int> p;
  vector<int> s;
  int n, mx, g;

  dsu(int _n) : n(_n) {
    p.resize(n);
    s.resize(n, 1);
    iota(p.begin(), p.end(), 0);
    mx = 1, g = n;
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      s[y] += s[x];
      mx = max(mx, s[y]);
      g--;
      return true;
    }
    return false;
  }
};


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M; cin >> N >> M;
  dsu d(N);

  while (M--) {
    int a, b; cin >> a >> b;
    a--; b--;
    d.unite(a, b);
    cout << d.g << ' ' << d.mx << '\n';
  }


  return 0;
}