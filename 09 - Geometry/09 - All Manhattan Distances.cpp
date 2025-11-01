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
  vector<pair<int, int>> v(n);
  for (auto& [x, y] : v) cin >> x >> y;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  
  __int128 ans = 0; // what kind of monstrosity is this!!!!!
  sort(v.begin(), v.end());
  unsigned int sum = 0;
  for (int i = 1; i < n; i++) {
    sum += (v[i].first - v[i - 1].first) * i;
    ans += sum;
  }
  sum = 0;
  sort(v.begin(), v.end(), [&](pair<int, int>& a, pair<int, int>& b){return a.second < b.second;});
  for (int i = 1; i < n; i++) {
    sum += (v[i].second - v[i - 1].second) * i;
    ans += sum;
  }
  
  

  vector<int> res;
  while (ans) {
    res.push_back(ans % 10);
    ans /= 10;
  }
  reverse(res.begin(), res.end());
  for (auto x : res) cout << x;
  
  return 0;
}