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

  // a(0) = 0, a(2n) = a(n) + a(n - 1) + n, a(2n + 1) = 2a(n) + n + 1
  int n; cin >> n;
  int sum = 0;

  for (int i = 1; i < 60; i++) {
    int pow = 1LL << i;
    int mod = n % pow;
    sum += max(0LL, mod - (pow / 2 - 1));
    sum += (n - mod) / 2;
  }

  cout << sum;


  return 0;
}