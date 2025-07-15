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

  auto dfs = [&](auto&& self, int from, int parent, int dist) -> void {
    if (dist > maxdist) {
      maxdist = dist;
      farthestnode = from;
    }
    for (auto& to : adj[from]) {
      if (to != parent) {
        self(self, to, from, dist + 1);
      }
    }
  };

  dfs(dfs, 0, -1, 0);
  dfs(dfs, farthestnode, -1, 0);
  cout << maxdist;
  
  
  return 0;
}