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
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    mp[x]++;
  }
  int ans = 0;
  for (auto [i, j] : mp) {
    ans = (ans + ans * j + j) % MOD; 
  }
  cout << ans;
  
  return 0;
}