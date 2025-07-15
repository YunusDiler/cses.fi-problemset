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
  vector<int> s;
  for (int i = 0; i < (1 << n); i++) {
    int x = 0;
    for (int j = (1 << (n - 1)), c = 0; j > 0; j >>= 1, c++) {
      if (i & j) x ^= v[c];
    }
    s.push_back(x);
  }
  sort(s.begin(), s.end());

  for (auto& i : s) cout << i << ' ';
  
  
  
  return 0;
}