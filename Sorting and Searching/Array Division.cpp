#include <bits/stdc++.h>

#define int long long

using namespace std;

int n, k;
vector<int> v;

bool solve(int limit) {
  int sum = 0;
  int count = 1;
  for (int i = 0; i < n; i++) {
    if (v[i] > limit)
      return false;
    else if (sum + v[i] > limit) {
      sum = v[i];
      count++;
    } else
      sum += v[i];
  }

  return count <= k;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  v.resize(n, 0);
  for (int i = 0; i < n; i++) cin >> v[i];

  int l = 1, r = 2e15, ans = LLONG_MAX;

  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (solve(mid)) {
      r = mid - 1;
      ans = min(ans, mid);
    } else
      l = mid + 1;
  }

  cout << ans;

  return 0;
}