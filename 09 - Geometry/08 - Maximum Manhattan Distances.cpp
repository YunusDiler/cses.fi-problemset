#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 31
#endif

const int MOD = 1e9 + 7;
const int INF = 1e18;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n; cin >> n;
  int x, y;

  /*
    dx = x1 - x2, dy = y1 - y2. but manhattan distance is not dx + dy.
    It can be in 4 different signs. we can reduce it to 2 by taking abs.
    |dx + dy| and |dx - dy|, answer is maximum of these 2.
    after that I do u = x + y, v = x - y transform.
    then let the magic happen.
  */

  int u1 = -INF, u2 = INF;
  int v1 = -INF, v2 = INF;

  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    u1 = max(u1, x + y);
    u2 = min(u2, x + y);
    v1 = max(v1, x - y);
    v2 = min(v2, x - y);
    int ans = max(u1 - u2, v1 - v2);
    cout << ans << endl;
  }

  return 0;
}

/*
  Define u = x + y and v = x - y.
  For two points p1=(x1,y1), p2=(x2,y2) let dx = x1-x2, dy = y1-y2. Then:
  |u1-u2| = |(x1+y1) - (x2+y2)| = |dx + dy|
  |v1-v2| = |(x1-y1) - (x2-y2)| = |dx - dy|
  Identity: |dx| + |dy| = max(|dx+dy|, |dx-dy|).
  (If dx and dy have the same sign, |dx+dy| = |dx|+|dy|; otherwise |dx-dy| = |dx|+|dy|.)
  Consequence for the problem

  Manhattan distance between any two points = max(|u1-u2|, |v1-v2|).

*/