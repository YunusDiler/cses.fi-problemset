#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;
const int MAXN = 1e5 + 1;

vector<vector<int>> adj(MAXN);
vector<int> color(MAXN);
vector<int> parent(MAXN);
int cycle_start = 0, cycle_end = 0;

void dfs(int u) {
  if (cycle_end) return;
  color[u] = 1;
  for (auto v : adj[u]) {
    if (cycle_end) return;
    if (color[v] == 0) {
      parent[v] = u;
      dfs(v);
    }
    else if (color[v] == 1) {
      //cycle
      cycle_end = u;
      cycle_start = v;
      return;
    }
  }
  color[u] = 2;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M; cin >> N >> M;
    for (int i = 0; i < M; i++) {
      int a, b; cin >> a >> b;
      adj[a].push_back(b);
    }

    for (int i = 1; i <= N; i++) {
      if (!color[i]) dfs(i);
      if (cycle_end) break;
    }

    if (cycle_end == 0) {cout << "IMPOSSIBLE"; return 0;}

    vector<int> ans = {cycle_start};
    while (cycle_end != cycle_start) {
      ans.push_back(cycle_end);
      cycle_end = parent[cycle_end];
    }
    ans.push_back(cycle_start);
    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (auto i : ans) cout << i << ' ';
    
    return 0;
}