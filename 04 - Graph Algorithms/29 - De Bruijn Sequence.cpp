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
  int N = 1 << n;
  vector<int> v(n, 0);
  vector<vector<int>> pref(n, vector<int>(N));
  for (int i = 0; i < n; i++) pref[i][0] = 1;
  
  auto Check = [&](int x, int s) -> bool {
    for (int i = n; i > n - s; i--) {
      if (pref[i - 1][x] >= (1 << (n - i))) return 0;
      x &= ~(1 << (i - 1)); 
    }
    return 1;
  };

  auto Fill = [&](int x) -> void {
    for (int i = n; i > 0; i--) {
      pref[i - 1][x]++;
      x >>= 1;
    }
  };

  int x = 0, lim = n + N - 1;
  for (int i = n; i < lim; i++) {
    x &= ~(1 << (n - 1));
    x <<= 1;
    if (!Check(x, min(lim - i, n))) {
      x |= 1;
    }
    v.push_back(x & 1);
    Fill(x);
  }

  for (auto i : v) cout << i;
  
  return 0;
}