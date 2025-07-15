#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;
const int MAX = 2e5 + 31;

vector<int> spf(MAX);
vector<int> primes;

void sieve() {
  for (int i = 2; i < MAX; ++i) {
    if (spf[i]) continue;
    spf[i] = i;
    primes.emplace_back(i);
    for (int j = i * i; j < MAX; j += i) if (!spf[j]) spf[j] = i;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  sieve();

  int n; cin >> n;
  vector<int> v(n);
  for (auto& i : v) cin >> i;

  vector<int> lcm(MAX);

  auto Add = [&](int x) -> void {
    int c = 0, s = spf[x];
    while (x != 1) {
      x /= spf[x];
      c++;
      if (s != spf[x]) {
        lcm[s] = max(lcm[s], c);
        c = 0;
        s = spf[x];
      }
    }
  };

  vector<bool> vis(n + 1);

  auto Dfs = [&](auto&& self, int x) -> int {
    if (vis[x]) return 0;
    vis[x] = 1;
    return self(self, v[x - 1]) + 1;
  };

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) Add(Dfs(Dfs, i));
  }

  int ans = 1;
  for (int i = 2; i <= n; i++) {
    while (lcm[i]--) ans = ans * i % MOD;
  }

  cout << ans;
  
  return 0;
}