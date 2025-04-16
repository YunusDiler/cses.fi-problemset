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
  int x = 1;
  
  if (k == n * (n - 1) / 2) cout << n << ' ';

  while (k >= n - x && k) {
    k -= n - x;
    x++;
  }

  for (int i = 0; i < n - x; i++) {
    if (i == k) {
      cout << x << ' ';
    }
    cout << i + x + 1 << ' ';
  }

  for (int i = x - 1; i >= 1; i--) cout << i << ' ';
  
  return 0;
}