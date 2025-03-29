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
  int l = 1, r = n * n, bound = n * n / 2;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    int less = 0, much = 0;
    
    for (int i = 1; i <= n; i++) {
      less += min(n, mid / i);
      much += n - min(n, (mid - 1) / i); 
    }

    if (less > bound && much > bound) {cout << mid; return 0;}
    else if (less > much) r = mid - 1;
    else l = mid + 1;

  }
  
  return 0;
}