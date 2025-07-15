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
    if (n < 3) {cout << n + 1 << endl; continue;}
    n++;
    if (n % 2 == 0) n++;
    auto Check = [&](int x) -> bool {
      int k = 1;
      if (x % 3 == 0) return false;
      for (int i = 5; i * i <= x; i += (2 + 2 * k)) {
        k ^= 1;
        if (x % i == 0) return false;
      }
      return true;
    };

    if (n % 6 == 3) n += 2;
    int a = n % 6 == 1;
    while (!Check(n)) {
      n += 2 + 2 * a;
      a ^= 1;
    } 
    cout << n << endl;
  }
  
  
  
  return 0;
}