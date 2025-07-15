#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> v;

int n, target;

// what I learned, 10^8 passes in O(n) solution
int coin(int target) {
  vector<int> dp(target + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= target; j++) {
      if (j - v[i] >= 0) {
        dp[j] += dp[j - v[i]];
        dp[j] %= 1000000007;
      }
    }
  }
  return dp[target];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> target;
  v.resize(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end(), greater<int>());
  cout << coin(target);

  return 0;
}
