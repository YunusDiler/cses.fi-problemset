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

  vector<int> f(20);
  f[0] = 1;
  for (int i = 1; i < 20; i++) f[i] = i * f[i - 1];

  auto Kth = [&](int n, int k) -> void {
    vector<int> p(n);    
    iota(p.begin(), p.end(), 1);
    for (int i = 0; i < n - 1; i++) {
      int x = (k - 1) / f[n - i - 1];
      k -= x * f[n - i - 1];
      cout << p[x] << ' ';
      p.erase(lower_bound(p.begin(), p.end(), p[x]));
    }
    cout << p[0] << endl;
  };

  auto BuPermutasyonKacinciPermutasyon = [&](int n, vector<int> v) -> void {
    int ans = 1;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    for (int i = 0; i < n - 1; i++) {
      ans += f[n - i - 1] * (lower_bound(p.begin(), p.end(), v[i]) - p.begin());
      p.erase(lower_bound(p.begin(), p.end(), v[i]));
    }
    cout << ans << endl;
  };

  int t; cin >> t;
  while (t--)
  {
    int type; cin >> type;
    if (type == 1) {
      int n, k; cin >> n >> k;
      Kth(n, k);
    }
    else {
      int n; cin >> n;
      vector<int> v(n);
      for (auto& i : v) cin >> i;
      BuPermutasyonKacinciPermutasyon(n, v);
    }
  }

  return 0;
}