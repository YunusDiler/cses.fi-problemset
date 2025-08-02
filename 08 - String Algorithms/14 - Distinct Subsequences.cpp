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
  
  string s; cin >> s;
 
  vector<int> add(26);
  int ans = 0;
  for (auto& c : s) {
    int x = c - 'a';
    int next = (ans * 2 + 1 - add[x] + MOD) % MOD;
    add[x] = (add[x] + next - ans + MOD) % MOD;
    ans = next;
  }
 
  cout << ans;
  
  return 0;
}