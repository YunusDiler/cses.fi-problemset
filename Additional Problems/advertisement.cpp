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
  
  int n; cin >> n;
  vector<int> v(n);
  for (auto& i : v) cin >> i;
  v.push_back(0);
  stack<pair<int, int>> s;
  s.push({v[0], 0});
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int last = i;
    while (s.size() && s.top().first >= v[i]) {
      ans = max(ans, (i - s.top().second) * s.top().first);
      last = s.top().second;
      s.pop();
    }
    s.push({v[i], last});
  }
  cout << ans;
  
  return 0;
}