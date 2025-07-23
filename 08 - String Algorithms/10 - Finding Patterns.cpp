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
  
  string s; cin >> s;
  s.push_back('$');
  int n = s.size();
  vector<int> v(n);
  iota(v.begin(), v.end(), 0);
  sort(v.begin(), v.end(), [&](int& a, int& b){return s[a] < s[b];});
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
      if (eq[v[i]] != eq[v[i - 1]] || eq[(v[i] + it) % n] != eq[(v[i - 1] + it) % n]) e++;
      neq[v[i]] = e;
    }
    eq = neq;
    if (e == n - 1) break;
  }

  auto Query = [&](string& x) -> bool {
    int l = 0, r = n - 1, mid;
    while (l <= r) {
      mid = l + (r - l) / 2;
      int i = 0;
      while (i < (int) x.size() && i + v[mid] < n && s[v[mid] + i] == x[i]) i++;
      if (i == (int) x.size()) return true;
      if (v[mid] + i == n || s[v[mid] + i] < x[i]) l = mid + 1;
      else r = mid - 1;
    }
    return false;
  };

  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    cout << (Query(s) ? "YES" : "NO") << endl;
  }
  
  return 0;
}