#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;

class dsu {
  public:
   vector<int> p;
   vector<int> s;
   int n;
 
   dsu(int _n) : n(_n) {
     p.resize(n);
     s.resize(n, 1);
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
       s[y] += s[x];
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
  dsu d(n);
  while (m--) {
    int x, y; cin >> x >> y;
    x--; y--;
    d.unite(x, y);
  }
  vector<int> g;
  for (int i = 0; i < n; i++) {
    if (i == d.get(i)) g.push_back(d.s[i]);
  }
  vector<int> cnt(n + 1);
  for (auto i : g) cnt[i]++;
  for (int i = 1; i < n; i++) {
    if (cnt[i] > 2) {
      int x = (cnt[i] - 1) / 2;
      cnt[i] -= 2 * x;
      cnt[i * 2] += x;
    }
  }
  bitset<100001> posi;
	posi[0] = 1;
  for (int i = 1; i <= n; i++) {
    while(cnt[i]--) {
      posi |= posi << i;
    }
  }
  for (int i = 1; i <= n; ++i) cout << posi[i];
  return 0;
}

