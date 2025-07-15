#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;

mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n; cin >> n;
  vector<int> a(n), b(n);
  for (auto& i : a) cin >> i;
  for (auto& i : b) cin >> i;
  
  vector<int> c(n);
  iota(c.begin(), c.end(), 1);

  for (int i = 0; i < 100; i++) {
    shuffle(c.begin(), c.end(), rng);
    bool ok = true;
    for (int j = 0; j < n; j++) {
      if (a[j] == c[j] || b[j] == c[j]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      for (auto& j : c) {
        cout << j << ' ';
      }
      return 0;
    }
  }
  
  cout << "IMPOSSIBLE" << endl;
  
  return 0;
}