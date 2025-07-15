#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, t;
  cin >> n >> t;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];

  int ans = LLONG_MAX;

  int l = 1, r = 1e18 + 1;
  while (l <= r) {
    int mid = (l + r) / 2, count = 0;
    for (auto i : v) {
      count += mid / i;
      if (count >= t) {
        ans = min(ans, mid);
        r = mid - 1;
        break;
      }
    }
    if (count < t)
      l = mid + 1;
    else {
      ans = min(ans, mid);
      r = mid - 1;
    }
  }

  cout << ans;

  return 0;
}