#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, ans = 0;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }

  vector<int> index(n + 1);
  for (int i = 1; i <= n; i++) {
    if (!index[v[i] - 1]) {
      ans++;
    }
    index[v[i]] = i;
  }

  cout << ans;

  return 0;
}