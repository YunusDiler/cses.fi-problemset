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
  
  int n, k; cin >> n >> k;
  vector<int> v(n);
  for (auto& i : v) cin >> i;
  
  vector<int> dp_old(n + 1), dp_new(n + 1);
  
  vector<int> pref(n + 1);
  for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + v[i - 1];

  auto sq = [&](int l, int r) {
    return (pref[r] - pref[l - 1]) * (pref[r] - pref[l - 1]);
  };

  auto solve = [&](auto&& self, int l, int r, int lb, int rb) -> void {
    if (l > r) return;
    int m = l + (r - l) / 2;
    int val = INF, index = -1;
    for (int i = lb; i <= min(m, rb); i++) {
      if (val > dp_old[i] + sq(i + 1, m)) {
        val = dp_old[i] + sq(i + 1, m);
        index = i;
      }
    }
    dp_new[m] = val;
    self(self, l, m - 1, lb, index);
    self(self, m + 1, r, index, rb);
    return;
  };

  for (int i = 1; i <= n; i++) {
    dp_old[i] = sq(1, i);
  }

  for (int i = 2; i <= k; i++) {
    solve(solve, 1, n, 1, n);
    dp_old = dp_new;
  }
  cout << dp_old[n];

  return 0;
}