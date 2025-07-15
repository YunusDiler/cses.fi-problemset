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
  vector<string> v(n);
  for (auto& s : v) cin >> s;
  vector<vector<int>> good(n, vector<int>(n));
  good[0][0] = 1;
  vector<char> ans = {v[0][0]};
  for (int i = 1; i < 2 * n - 1; i++) {
    char thegoodone = 'Z';
    int x = min(i, n - 1), y = max(0LL, i - x);
    while (x >= 0 && y < n) {
      if (x > 0 && good[y][x - 1]) thegoodone = min(thegoodone, v[y][x]);
      else if (y > 0 && good[y - 1][x]) thegoodone = min(thegoodone, v[y][x]);
      x--;
      y++;
    }
    x = min(i, n - 1), y = max(0LL, i - x);
    while (x >= 0 && y < n) {
      if (v[y][x] == thegoodone && ((x > 0 && good[y][x - 1]) || (y > 0 && good[y - 1][x]))) good[y][x] = 1;
      x--;
      y++;
    }
    ans.push_back(thegoodone);
  }
  for (auto& c : ans) cout << c;
  
  return 0;
}