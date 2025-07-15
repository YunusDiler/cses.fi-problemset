#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  int ans = 0, sum = 0;
  for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.end());
  for (auto x : v) {
    sum += x.first;
    ans += x.second - sum;
  }
  cout << ans;
}