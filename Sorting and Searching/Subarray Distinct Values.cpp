#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;

  map<int, int> mp;
  map<int, int> pos;

  int ans = 0, pivot = 0;
  for (int i = 1; i <= n; i++) {
    int val;
    cin >> val;

    if (!pos[val] && mp.size() == k) {
      auto it = mp.begin();
      pivot = it->first;
      pos.erase(it->second);
      mp.erase(it);
      mp[i] = val;
      pos[val] = i;
    } else {
      if (pos[val]) mp.erase(pos[val]);
      mp[i] = val;
      pos[val] = i;
    }
    ans += i - pivot;
  }

  cout << ans;

  return 0;
}