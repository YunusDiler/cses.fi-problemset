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
  
  int n, m; cin >> n >> m;
  vector<string> v(n);
  for (auto& s : v) cin >> s;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int c = 'A'; c <= 'D'; c++) {
        if (v[i][j] == c || (i > 0 && v[i - 1][j] == c) || (j > 0 && v[i][j - 1] == c)) continue;
        v[i][j] = c;
        break;
      }
    }
  }

  for (auto& s : v) cout << s << endl;

  return 0;
}