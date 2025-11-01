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
  
  int n, k; cin >> n >> k;
  vector<string> grid(n);
  for (auto& i : grid) cin >> i;

  vector<int> hash(k);
  mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
  for (int i = 0; i < k; i++) {
    hash[i] = rng() % MOD;
  }

  vector<vector<int>> v(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      v[i][j] = hash[grid[i][j] - 'A'];
    }
  }
  
  vector<vector<int>> pref(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      pref[i][j] = pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1] + v[i - 1][j - 1];
    }
  }
  auto Check = [&](int i, int j, int s, int val) -> bool {
    return ((pref[i][j] - pref[i - s][j] - pref[i][j - s] + pref[i - s][j - s]) - (s * s * val)) == 0;
  };


  vector<int> ans(k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int l = 1, r = min(i, j);
      int mx = 1;
      while (l <= r) {
        int mid = (l + r) / 2;
        bool b = Check(i, j, mid, v[i - 1][j - 1]);
        if (b) {
          mx = mid;
          l = mid + 1;
        }
        else r = mid - 1;
      }
      ans[grid[i - 1][j - 1] - 'A'] += mx;
    }
  }

  for (auto& i : ans) cout << i << endl;
  
  return 0;
}