#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 31
#endif

const int MOD = 1e9 + 7;
const int INF = 1e18;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n; cin >> n;
  vector<int> v(n);
  for (auto& i : v) cin >> i;
  
  vector<int> pref(n + 1);
  for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + v[i - 1];

  vector<vector<int>> dp(n + 1, vector<int>(n + 1)), opt(n + 1, vector<int>(n + 1));

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j + i <= n; j++) {
      if (i < 2) {
        dp[j][j + i] = 0;
        opt[j][j + i] = j;
        continue;
      }
      dp[j][j + i] = INF;
      for (int k = opt[j][j + i - 1]; k <= opt[j + 1][j + i]; k++) {
        int val = dp[j][k] + dp[k][i + j] + pref[j + i] - pref[j];
        if (val < dp[j][j + i]) {
          dp[j][j + i] = val;
          opt[j][j + i] = k;
        }
      }
    }
  }

  cout << dp[0][n];
  
  return 0;
}