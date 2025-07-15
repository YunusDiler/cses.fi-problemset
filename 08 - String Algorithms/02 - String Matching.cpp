#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> prefix_function(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s, f;
  cin >> s >> f;

  auto pi = prefix_function(f + ' ' + s);

  int ans = 0;

  for (int i = f.size(); i <= f.size() + s.size(); i++) {
    if (pi[i] == f.size()) ans++;
  }

  cout << ans;

  return 0;
}