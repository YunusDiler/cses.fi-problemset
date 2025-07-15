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

  int n, m;
  cin >> n >> m;
  if (n * m % 2 == 1) {
    cout << 0;
    return 0;
  }
  vector<int> cnt(1 << n);
  for (int mask = 0; mask < (1 << n); ++mask) {
    vector<int> x(n + 1, 0);
    x[0] = 1;
    for (int b = 1; b <= n; ++b) {
      if ((mask >> (b - 1)) & 1) x[b] = x[b - 1];
      else if (b > 1 && ((mask >> (b - 2)) & 1) == 0) x[b] = x[b - 2];
    }
    cnt[mask] = x[n];
  }

  vector<vector<int>> dp(m + 1, vector<int>(1 << n, 0));
  dp[0][0] = 1;

  for (int col = 0; col < m; ++col) {
    for (int cur = 0; cur < (1 << n); ++cur) {
      if (!dp[col][cur]) continue;
      for (int nxt = 0; nxt < (1 << n); ++nxt) {
        if (cur & nxt) continue;
        int add = dp[col][cur] * cnt[cur | nxt] % MOD;
        dp[col + 1][nxt] = (dp[col + 1][nxt] + add) % MOD;
      }
    }
  }

  cout << dp[m][0] << endl;

  return 0;
}