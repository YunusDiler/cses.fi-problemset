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
  
  int t; cin >> t;
  while (t--)
  {
    int n, a, b; cin >> n >> a >> b;
    if (a + b == 1 || a + b > n || (min(a, b) == 0 && max(a, b) != 0)) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) cout << i << ' ';
    cout << endl;
    int draw = n - a - b;
    for (int i = 1; i <= draw; i++) cout << i << ' ';
    for (int i = 1; i <= b; i++) cout << n - b + i << ' ';
    for (int i = draw + 1; i <= n - b; i++) cout << i << ' ';
    cout << endl;

  }
  
  
  
  return 0;
}