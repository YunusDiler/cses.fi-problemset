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
const int MAX = 2e5;

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
  int last = n;
  vector<int> v = {n}, a(n);
  iota(a.begin(), a.end(), 1);
  auto b = a;
  while (last > 1) {
    for (int i = 1;; i++) {
      if (spf[i + last] == i + last) {
        last = i - 1;
        v.push_back(last);
        break;
      }
    }
  }
  reverse(v.begin(), v.end());
  for (int i = 1; i < (int)v.size(); i++) {
    reverse(b.begin() + v[i - 1], b.begin() + v[i]);
  }
  for (auto& i : a) cout << i << ' ';
  cout << endl;
  for (auto& i : b) cout << i << ' ';
  cout << endl;

  
  return 0;
}