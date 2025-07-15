#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;
const int MAXN = 1e5 + 31;

vector<int> visited(MAXN);
vector<bool> pushed(MAXN);
vector<vector<int>> adj(MAXN);
vector<int> order;
int color = 0;
bool flag = false;

void dfs(int node) {
  visited[node] = color;
  for (auto child : adj[node]) {
    if (flag) return;
    if (visited[child] == color && !pushed[child]) flag = true;

    if (!visited[child]) dfs(child);
  }
  pushed[node] = true;
  order.push_back(node);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M; cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int from, to; cin >> from >> to;
    adj[from].push_back(to);
  }

  for (int i = 1; i <= N; i++) {
    if (!visited[i]) {
      color++;
      dfs(i);
    }
  }

  if (flag) { cout << "IMPOSSIBLE"; return 0; }

  reverse(order.begin(), order.end());
  for (auto i : order) cout << i << ' ';

  return 0;
}