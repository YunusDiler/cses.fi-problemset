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
  vector<int> v(n);
  for (auto& i : v) {cin >> i; i--;}
  
  vector<int> ans(n);

  auto dfs = [&](auto&& self, int start) -> void {
    int step = 1;
    int little_boi = v[start];
    int big_boi = v[v[start]];

    while (little_boi != big_boi && !ans[little_boi]) {
      little_boi = v[little_boi];
      big_boi = v[v[big_boi]];
      step++;
    }

    if (ans[little_boi]) {
      while (start != little_boi) {
        ans[start] = step + ans[little_boi];
        start = v[start];
        step--;
      }
      return;
    }

    int len = 1;
    little_boi = start;
    while (little_boi != big_boi) {
      little_boi = v[little_boi];
      big_boi = v[big_boi];
    }
    big_boi = v[little_boi];
    while (little_boi != big_boi) {
      big_boi = v[big_boi];
      len++;
    }

    ans[big_boi] = len;
    big_boi = v[big_boi];
    while (little_boi != big_boi) {
      ans[big_boi] = len;
      big_boi = v[big_boi];
    }

    step = 0;
    little_boi = start;
    while (little_boi != big_boi) {
      little_boi = v[little_boi];
      step++;
    }

    little_boi = start;
    while (little_boi != big_boi) {
      ans[little_boi] = step + ans[big_boi];
      little_boi = v[little_boi];
      step--;
    }

    return;
  };

  for (int i = 0; i < n; i++) {
    if (!ans[i]) dfs(dfs, i);
  }

  for (auto i : ans) cout << i << ' ';

  return 0;
}