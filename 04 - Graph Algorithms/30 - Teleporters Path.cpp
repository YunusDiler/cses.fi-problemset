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
  
  int n, m; cin >> n >> m;
  vector<set<int>> g(n + 1);
  vector<int> ans, deg(n + 1);
  for (int i = 1; i <= m; i++) {
    int from, to; cin >> from >> to;
    g[from].insert(to);
    deg[from]++;
    deg[to]--;
  }

  if (deg[1] != 1 || deg[n] != -1) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  for (int i = 2; i < n; i++) {
    if (deg[i]) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  }

  auto Cycle = [&](auto&& self, int from) -> void {
    while (!g[from].empty()) {
      int to = *g[from].begin();
      g[from].erase(to);
      self(self, to);
    }
    ans.push_back(from);
  };

  Cycle(Cycle, 1);
  if (ans.size() != m + 1) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  reverse(ans.begin(), ans.end());
  for (auto& i : ans) cout << i << ' ';
    
  return 0;
}