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

  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  for (auto& i : v) cin >> i;

  int N = 1 << n;
  vector<int> rides(N, INF);
  vector<int> weight(N, x);
  rides[0] = 1;
  weight[0] = 0;

  for (int i = 0; i < N; i++) {
    for (int p = 0; p < n; p++) {
      if ((1 << p) & i) continue;

      int num = i | (1 << p);
      if (rides[num] >= rides[i]) {
        int a = rides[i];
        int b = weight[i] + v[p];

        if (b > x) {
          b = v[p];
          a++;
        }

        if (a < rides[num]) {
          rides[num] = a;
          weight[num] = b;
        }

        if (a == rides[num]) weight[num] = min(b, weight[num]);
      }
    }
  }

  cout << rides[N - 1];

  return 0;
}