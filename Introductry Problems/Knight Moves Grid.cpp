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
  vector<vector<int>> grid(n, vector<int>(n, INF));
  int t = 1;
  queue<pair<int, int>> q;

  auto Fill = [&](int x, int y) -> void {
    if (x > 1 && y > 0 && grid[x - 2][y - 1] == INF) {grid[x - 2][y - 1] = t; q.push(make_pair(x - 2, y - 1));}
    if (x > 1 && y < n - 1 && grid[x - 2][y + 1] == INF) {grid[x - 2][y + 1] = t; q.push(make_pair(x - 2, y + 1));}
    if (x > 0 && y > 1 && grid[x - 1][y - 2] == INF) {grid[x - 1][y - 2] = t; q.push(make_pair(x - 1, y - 2));}
    if (x > 0 && y < n - 2 && grid[x - 1][y + 2] == INF) {grid[x - 1][y + 2] = t; q.push(make_pair(x - 1, y + 2));}
    if (x < n - 1 && y > 1 && grid[x + 1][y - 2] == INF) {grid[x + 1][y - 2] = t; q.push(make_pair(x + 1, y - 2));}
    if (x < n - 1 && y < n - 2 && grid[x + 1][y + 2] == INF) {grid[x + 1][y + 2] = t; q.push(make_pair(x + 1, y + 2));}
    if (x < n - 2 && y > 0 && grid[x + 2][y - 1] == INF) {grid[x + 2][y - 1] = t; q.push(make_pair(x + 2, y - 1));}
    if (x < n - 2 && y < n - 1 && grid[x + 2][y + 1] == INF) {grid[x + 2][y + 1] = t; q.push(make_pair(x + 2, y + 1));}
  };

  grid[0][0] = 0;
  q.push(make_pair(0, 0));
  while (!q.empty()) {
    int count = q.size();
    while (count--) {
      auto [x, y] = q.front();
      q.pop();
      Fill(x, y);
    }
    t++;
  }

  for (auto& v : grid) {
    for (auto& i : v) cout << i << ' ';
    cout << endl;
  }
  
  return 0;
}