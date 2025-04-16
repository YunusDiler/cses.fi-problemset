#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

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

  int farthestnode = -1;
  int maxdist = -1;
  vector<bool> vis(n);
  vector<int> parent(n);
  vector<int> ans(n);

  auto dfs = [&](auto&& self, int from, int p, int dist) -> void {
    parent[from] = p;
    ans[from] = dist;
    if (dist > maxdist) {
      maxdist = dist;
      farthestnode = from;
    }
    for (auto& to : adj[from]) {
      if (to != p && !vis[to]) {
        self(self, to, from, dist + 1);
      }
    }
  };

  dfs(dfs, 0, -1, 0);
  maxdist = -1;
  dfs(dfs, farthestnode, -1, 0);
  int radius = maxdist;

  vector<int> path;
  while (parent[farthestnode] != -1) {
    path.push_back(farthestnode);
    farthestnode = parent[farthestnode];
  }
  path.push_back(farthestnode);

  for (auto i : path) vis[i] = 1;

  for (int i = radius / 2; i >= 0; i--) {
    maxdist = -1;
    dfs(dfs, path[i], -1, radius - i);
  }
  for (int i = radius / 2 + 1; i <= radius; i++) {
    maxdist = -1;
    dfs(dfs, path[i], -1, i);
  }

  for (auto i : ans) cout << i << ' ';

  
  return 0;
}