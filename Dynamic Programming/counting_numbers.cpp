#include <bits/stdc++.h>

#define int long long

using namespace std;
int dp[20][10][2][2];

int solve(string& num, int n, int prev, int i, bool lead, int tight) {
  if (i == n) return 1;
  if (prev != -1 && dp[i][prev][lead][tight] != -1)
    return dp[i][prev][lead][tight];

  int r = tight == 1 ? num[i] - '0' : 9, ans = 0;
  for (int j = 0; j <= r; j++) {
    if (j == prev && j) continue;
    if (j == prev && !j && !lead) continue;
    ans += solve(num, n, j, i + 1, lead & (!j), tight & (j == r));
  }
  return dp[i][prev][lead][tight] = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int ia, ib;
  cin >> ia >> ib;
  string a = to_string(ia - 1), b = to_string(ib);

  int na = a.size(), nb = b.size();
  memset(dp, -1, sizeof(dp));
  int ans = solve(b, nb, -1, 0, 1, 1);
  memset(dp, -1, sizeof(dp));
  ans -= solve(a, na, -1, 0, 1, 1);

  cout << ans << endl;

  return 0;
}