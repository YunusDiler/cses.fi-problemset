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
  vector<vector<int>> grid(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      set<int> s;
      for (int l = j - 1; l >= 0; l--) s.insert(grid[i][l]);
      for (int u = i - 1; u >= 0; u--) s.insert(grid[u][j]);
      int cur = 0;
      for (int it : s) if (it == cur) cur++;
      grid[i][j] = cur;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << grid[i][j] << ' ';
    }
    cout << endl;
  }
  
  return 0;
}