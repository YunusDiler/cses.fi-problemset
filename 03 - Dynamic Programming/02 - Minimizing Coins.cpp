#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> v;
vector<bool> vis(1000031);
vector<int> val(1000069);
int coin(int target) {
  if (target < 0) return INT_MAX;
  if (!target) return 0;
  if (vis[target]) return val[target];
  int mi = INT_MAX;
  for (auto& it : v) {
    if (target - it < 0) continue;
    mi = min(mi, coin(target - it) + 1);
  }
  vis[target] = true;
  val[target] = mi;
  return mi;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, target;
  cin >> n >> target;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  int ans = coin(target);
  if (ans == INT_MAX)
    cout << -1;
  else
    cout << ans;

  return 0;
}