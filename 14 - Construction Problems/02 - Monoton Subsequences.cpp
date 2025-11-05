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
  
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> ans;
    bool flag = 0;
    for (int i = k; i; i--) {
      int cnt = 0;
      for (int j = i; j <= n; j += k) {
        cnt++;
        ans.push_back(j);
      }
      if (cnt > k) flag = 1;
    }
    if (flag) {cout << "IMPOSSIBLE" << endl; continue;}
    for (auto& i : ans) cout << i << ' ';
    cout << endl;
  }
  
  return 0;
}