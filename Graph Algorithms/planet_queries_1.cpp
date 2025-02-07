#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;
const int MAXN = 2e5 + 31;

int path[MAXN][31];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, Q; cin >> N >> Q;
  for (int i = 1; i <= N; i++) {
    cin >> path[i][0];
  }

  for (int i = 1; i < 31; i++) {
    for (int planet = 1; planet <= N; planet++) {
      path[planet][i] = path[path[planet][i - 1]][i - 1];
    }
  }

  while (Q--) {
    int x, k; cin >> x >> k;
    for (int i = 0; i < 31; i++) {
      if ((1 << i) & k) x = path[x][i];
    }
    cout << x << '\n';
  }

  return 0;
}