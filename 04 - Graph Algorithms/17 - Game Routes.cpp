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

  int N, M; cin >> N >> M;
  vector<vector<int>> adj(N + 1);
  vector<int> indegree(N + 1);
  for (int i = 0; i < M; i++) {
    int from, to; cin >> from >> to;
    adj[from].push_back(to);
    indegree[to]++;
  }

  vector<bool> visited(N + 1);
  queue<int> q;
  q.push(1);
  visited[1] = true;
  while (!q.empty()) {
    int from = q.front();
    q.pop();
    for (auto to : adj[from]) {
      if (!visited[to]) q.push(to);
      visited[to] = true;
    }
  }

  for (int i = 1; i <= N; i++) {
    if (!visited[i]) {
      for (auto to : adj[i]) indegree[to]--;
    }
  }


  vector<int> count(N + 1);
  count[1] = 1;

  q.push(1);

  while (!q.empty()) {
    int from = q.front();
    q.pop();

    for (auto to : adj[from]) {
      count[to] = (count[to] + count[from]) % MOD;
      indegree[to]--;
      if (indegree[to] == 0) q.push(to);
    }
  }

  cout << count[N];
  
  return 0;
}