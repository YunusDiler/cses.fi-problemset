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
  vector<int> a(n), b(m);
  for (auto& i : a) cin >> i;
  for (auto& i : b) cin >> i;
  
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  vector<vector<int>> par(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x = dp[i - 1][j - 1] + (a[i - 1] == b[j - 1]), y = dp[i - 1][j], z = dp[i][j - 1];
      if (x > max(y, z)) {
        dp[i][j] = x;
        par[i][j] = 2;
      }
      else if (y > z) {
        dp[i][j] = y;
        par[i][j] = 1;
      }
      else {
        dp[i][j] = z;
        par[i][j] = 0;
      }
    }
  }
  cout << dp[n][m] << endl;
  vector<int> ans;
  while (dp[n][m]) {
    if (a[n - 1] == b[m - 1] && par[n][m] == 2) ans.push_back(a[n - 1]);
    if (par[n][m] == 2) {n--; m--;}
    else if (par[n][m] == 1) n--;
    else m--;
  }

  reverse(ans.begin(), ans.end());
  for (auto& i : ans) cout << i << ' ';
  
  return 0;
}