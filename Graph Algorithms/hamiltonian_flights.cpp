#include <bits/stdc++.h>
 
#define int long long
#define endl '\n'
 
using namespace std;
 
const int MOD = 1e9 + 7;
const int INF = 1e18;
const int N = 20;
const int MAXN = 1 << 20; 
 
int dp[N][MAXN], mat[N][N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int from, to; cin >> from >> to;
    from--; to--;
    mat[from][to]++;
  }

  dp[0][1] = 1;
  for (int i = 1; i < MAXN - 1; i++) {
    if (!(i & 1)) continue;

    for (int from = 0; from < N; from++) {
      if (!dp[from][i]) continue;

      for (int to = 0; to < N; to++) {
        int mask = (1 << to) ^ i;
        if (mask > i) {
          dp[to][mask] = (dp[to][mask] + dp[from][i] * mat[from][to]) % MOD;
        }
      }
    }
  }
 
  cout << dp[n - 1][(1 << n) - 1] << endl;
  
  return 0;
}