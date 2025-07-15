#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;

class DSU {
 public:
  vector<int> p, s;
  int n, g, mx;
 
  DSU(int _n) : n(_n) {
    p.resize(n);
    s.resize(n, 1);
    g = _n;
    mx = 1;
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
  vector<set<int>> adj(N);
  vector<int> degree(N);
  DSU dsu(N);
  for (int i = 0; i < M; i++) {
    int from, to; cin >> from >> to;
    from--; to--;
    adj[from].insert(to);
    adj[to].insert(from);
    degree[from]++; degree[to]++;
    dsu.unite(from, to);
  }

  for (int i = 0; i < N; i++) {
    if (degree[i] % 2 == 1) {
      cout << "IMPOSSIBLE";
      return 0;
    }
    if (dsu.get(0) != dsu.get(i) && dsu.s[dsu.get(i)] != 1) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  }

  vector<vector<vector<int>>> paths(N);
  queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int start = q.front();
    q.pop();
    if (!degree[start]) continue;
    int next = *adj[start].begin();
    degree[start]--;
    adj[start].erase(next);
    degree[next]--;
    adj[next].erase(start);
    vector<int> v;
    while (next != start) {
      v.push_back(next);
      int temp = next;
      next = *adj[temp].begin();
      degree[temp]--;
      adj[temp].erase(next);
      degree[next]--;
      adj[next].erase(temp);
      if (degree[temp]) q.push(temp);
    }
    v.push_back(start);
    paths[start].push_back(v);
    if (degree[start]) q.push(start); 
  }
  
  vector<int> vis(N);
  auto Print = [&](auto&& self, int start) -> void {
    for (auto& v : paths[start]) {
      for (auto& i : v) {
        cout << i + 1 << ' ';
        if (!vis[i]) {
          vis[i] = 1;
          self(self, i);
        }
      }
    }
  };
  
  vis[0] = 1;
  cout << 1 << ' ';
  Print(Print, 0);

  return 0;
}