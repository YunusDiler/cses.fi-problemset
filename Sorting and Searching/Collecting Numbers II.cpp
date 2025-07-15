#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, q, ans = 0;
  cin >> n >> q;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }

  vector<int> index(n + 2);
  index[n + 1] = 2 * n;
  for (int i = 1; i <= n; i++) {
    if (!index[v[i] - 1]) {
      ans++;
    }
    index[v[i]] = i;
  }

  while (q--) {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);

    if (v[x] + 1 == v[y]) {
      ans++;
      if (x < index[v[x] - 1] && index[v[x] - 1] < y) ans--;
      if (x < index[v[y] + 1] && index[v[y] + 1] < y) ans--;
    } else if (v[x] - 1 == v[y]) {
      ans--;
      if (x < index[v[y] - 1] && index[v[y] - 1] < y) ans++;
      if (x < index[v[x] + 1] && index[v[x] + 1] < y) ans++;
    } else {
      if (x < index[v[x] - 1] && index[v[x] - 1] < y) ans--;
      if (x < index[v[y] + 1] && index[v[y] + 1] < y) ans--;
      if (x < index[v[y] - 1] && index[v[y] - 1] < y) ans++;
      if (x < index[v[x] + 1] && index[v[x] + 1] < y) ans++;
    }

    index[v[x]] = y;
    index[v[y]] = x;

    swap(v[x], v[y]);

    cout << ans << endl;
  }

  return 0;
}
