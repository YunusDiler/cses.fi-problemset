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
  int a, b, c; cin >> v[0] >> a >> b >> c;
  for (int i = 1; i < n; i++) {
    v[i] = (a * v[i - 1] + b) % c;
  }
  int sum = 0;
  for (int i = 0; i < k; i++) sum += v[i];
  int ans = sum;
  for (int i = k; i < n; i++) {
    sum += v[i] - v[i - k];
    ans ^= sum;
  }
 
  cout << ans;
  
  return 0;
}