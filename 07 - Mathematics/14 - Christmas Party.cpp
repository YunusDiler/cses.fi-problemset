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
  
  
  // f(n) = n! - sum(k = 1 -> n - 1, C(n, k) * f(k)) - 1
  // f(n) = (n - 1) * (f(n - 1) + f(n - 2))

  vector<int> f(1e6 + 1);
  f[0] = 1;
  for (int i = 2; i <= 1e6; i++) {
    f[i] = (i - 1) * (f[i - 1] + f[i - 2]) % MOD;
  }
  
  int n; cin >> n; 
  cout << f[n];
  
  return 0;
}