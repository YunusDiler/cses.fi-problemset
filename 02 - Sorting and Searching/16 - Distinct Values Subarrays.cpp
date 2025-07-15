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
  
  int ans = 0, last = 0;
  map<int, int> mp;

  for (int i = 0; i < n; i++) {
    last = max(last, mp[v[i]]);
    ans += i - last + 1;
    mp[v[i]] = i + 1;
  }

  cout << ans;
  
  return 0;
}