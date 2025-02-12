#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;
const int MAXN = 2e5 + 31;

int path[MAXN][20];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q; cin >> n >> q;
  vector<int> v(n);
  for (auto& i : v) {cin >> i; i--;}

  for (int i = 0; i < n; i++) path[i][0] = v[i];
  
  for (int i = 1; i < 20; i++) {
    for (int planet = 0; planet < n; planet++) {
      path[planet][i] = path[path[planet][i - 1]][i - 1];
    }
  }

  vector<int> dist(n, -1), cycle_st(n), cycle_sz(n);

  auto dfs = [&](auto&& self, int start) -> void {
    int step = 1;
    int little_boi = v[start];
    int big_boi = v[v[start]];

    while (little_boi != big_boi && dist[little_boi] == -1) {
      little_boi = v[little_boi];
      big_boi = v[v[big_boi]];
      step++;
    }

    if (dist[little_boi] != -1) {
      while (start != little_boi) {
        dist[start] = step + dist[little_boi];
        cycle_st[start] = cycle_st[little_boi];
        cycle_sz[start] = cycle_sz[little_boi];
        start = v[start];
        step--;
      }
      return;
    }

    little_boi = start;
    while (little_boi != big_boi) {
      little_boi = v[little_boi];
      big_boi = v[big_boi];
    }

    int len = 1;
    cycle_st[big_boi] = big_boi;
    big_boi = v[little_boi];
    while (little_boi != big_boi) {
      cycle_st[big_boi] = big_boi;
      big_boi = v[big_boi];
      len++;
    }

    int sz = len;
    cycle_sz[big_boi] = sz;
    dist[big_boi] = 0;
    big_boi = v[big_boi];
    while (little_boi != big_boi) {
      dist[big_boi] = --len;
      cycle_sz[big_boi] = sz;
      big_boi = v[big_boi];
    }

    step = 0;
    little_boi = start;
    while (little_boi != big_boi) {
      little_boi = v[little_boi];
      step++;
    }

    little_boi = start;
    while (little_boi != big_boi) {
      cycle_st[little_boi] = big_boi;
      cycle_sz[little_boi] = sz;
      dist[little_boi] = step--;
      little_boi = v[little_boi];
    }

    return;
  };

  for (int i = 0; i < n; i++) {
    if (dist[i] == -1) dfs(dfs, i);
  }


  auto kstep = [&](int x, int k) -> int {
    for (int i = 0; i < 20; i++) {
      if ((1 << i) & k) x = path[x][i];
    }
    return x;
  };

  while (q--) {
    int a, b; cin >> a >> b;
    a--; b--;
    int ta = a, tb = b;

    if (cycle_st[a] == cycle_st[b]) {
      if (dist[a] >= dist[b]) {
        ta = kstep(ta, dist[a] - dist[b]);
        cout << (ta == b ? (dist[a] - dist[b]) : -1) << endl;
        continue;
      }
    }
    else if (cycle_st[a] == a && cycle_st[b] == b) {
      ta = kstep(ta, dist[a]);
      tb = kstep(tb, dist[b]);

      if (ta == tb) {
        cout << (dist[a] >= dist[b] ? dist[a] - dist[b] : cycle_sz[a] + dist[a] - dist[b]) << endl;
        continue;
      }
    }
    else if (cycle_st[a] != a && cycle_st[b] == b) {
      ta = kstep(ta, dist[a]);
      tb = kstep(tb, dist[b]);

      if (ta == tb) {
        cout << (dist[cycle_st[a]] >= dist[b] ? dist[a] - dist[b] : dist[a] + cycle_sz[b] - dist[b]) << endl;
        continue;
      }
    }
    
    cout << -1 << endl;
  }

  return 0;
}