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
    int n; cin >> n;
    int a = 0;
    while (n--) {
      int x; cin >> x;
      a ^= x % 4;
    }
    if (a) cout << "first\n";
    else cout << "second\n";
  }
    
  return 0;
}