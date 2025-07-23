#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;

vector<int> suffix_array(string& s) {
  s.push_back('$');
  int n = s.size();
  vector<int> v(n);
  iota(v.begin(), v.end(), 0);
  sort(v.begin(), v.end(), [&](int& a, int& b) { return s[a] < s[b]; });
  vector<int> eq(n);

  int e = 0;
  for (int i = 1; i < n; i++) {
    if (s[v[i]] != s[v[i - 1]]) e++;
    eq[v[i]] = e;
  }

  auto Sort = [&](int it) {
    vector<int> v2(n), cnt(e + 1, 0);
    for (int i = 0; i < n; i++) v2[i] = (v[i] - it + n) % n;
    for (int i = 0; i < n; i++) cnt[eq[v2[i]]]++;
    for (int i = 1; i <= e; i++) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--) v[--cnt[eq[v2[i]]]] = v2[i];
  };

  for (int it = 1; it < n; it <<= 1) {
    Sort(it);
    e = 0;
    vector<int> neq(n);
    for (int i = 1; i < n; i++) {
      if (eq[v[i]] != eq[v[i - 1]] ||
          eq[(v[i] + it) % n] != eq[(v[i - 1] + it) % n])
        e++;
      neq[v[i]] = e;
    }
    eq = neq;
    if (e == n - 1) break;
  }
  return v;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s; cin >> s;
  auto v = suffix_array(s);
  int n = s.size();
  vector<int> lcp(n - 1);
  vector<int> pos(n);
  for (int i = 0; i < n; i++) pos[v[i]] = i;
  
  int it = 0;
  for (int i = 0; i < n - 1; i++) {
    int j = v[pos[i] - 1];
    while (it + j < n && it + i < n && s[it + j] == s[it + i]) it++;
    lcp[pos[i] - 1] = it;
    if (it) --it;
    if (i < n - 2) lcp[pos[i + 1] - 1] = it;
  }

  
  int ans = 0;
  for (int i = 1; i < n; i++) {
    ans += n - v[i] - 1 - lcp[i - 1];
  }
  cout << ans;


  return 0;
}