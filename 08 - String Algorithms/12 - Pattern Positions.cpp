#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;

#define lch (i << 1)
#define rch (i << 1 | 1)

struct Info {
  int sum;
  int mn;
  int mx;

  Info() : sum(0), mn(INF), mx(-INF) {}
  Info(int x) : sum(x), mn(x), mx(x) {}

  Info unite(const Info& b) {
    Info res;
    res.sum = sum + b.sum;
    res.mn = min(mn, b.mn);
    res.mx = max(mx, b.mx);
    return res;
  }

  friend ostream& operator<<(ostream& os, const Info& info) {
    os << "sum: " << info.sum << ", min: " << info.mn << ", max: " << info.mx;
    return os;
  }
};

struct SimpleSegmentTree {

  int n;
  vector<Info> info;
  SimpleSegmentTree(vector<Info>& a) : n(1 << (32 - __builtin_clz(a.size() - 1))) {
    info.resize(n << 1);
    for (int i = 0; i < a.size(); ++i) {
      info[i + n] = a[i];
    }
    for (int i = n - 1; i > 0; --i) {
      info[i] = info[lch].unite(info[rch]);
    }
  }

  void apply(Info& a, int val) {
    a.sum = val;
    a.mn = val;
    a.mx = val;
  }

  void modify(int i, int val) {
    i += n;
    apply(info[i], val);
    i >>= 1;
    while (i >= 1) {
      info[i] = info[lch].unite(info[rch]);
      i >>= 1;
    }
  }

  Info query(int l, int r) {
    l += n; 
    r += n;
    Info res; 
    while (l <= r) {
      if (l & 1) {
        res = res.unite(info[l++]);
      }
      if (~r & 1) {
        res = res.unite(info[r--]);
      } 
      l >>= 1, r >>= 1;
    }
    return res;
  }

  int bs(int ql, int qr, int x, int i = 1, int nl = 0, int nr = -1) {
    if (nr == -1) nr = n - 1;
    if (nr < ql || nl > qr || info[i].mx < x) {
      return -1;
    }
    if (nl == nr) {
      return nr;
    } 
    int m = (nl + nr) >> 1;
    int res = bs(ql, qr, x, lch, nl, m);
    if (res != -1) {
      return res;
    }
    return bs(ql, qr, x, rch, m + 1, nr);
  }
};

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

  vector<Info> info(n);
  SimpleSegmentTree st(info);
  for (int i = 0; i < n; i++) {
    st.modify(i, v[i]);
  }

  auto Query = [&](string& x) -> int {
    int beg = 0, end = n - 1, mid;
    for (int i = 0; i < (int)x.size(); i++) {
      int l = beg, r = end;
      while (l <= r) {
        mid = l + (r - l) / 2;
        int c = (v[mid] + i < n) ? s[v[mid] + i] : -1;
        if (c < x[i]) l = mid + 1;
        else r = mid - 1;
      }
      beg = l;
      l = beg; r = end;
      while (l <= r) {
        mid = l + (r - l) / 2;
        int c = (v[mid] + i < n) ? s[v[mid] + i] : -1;
        if (c <= x[i]) l = mid + 1;
        else r = mid - 1;
      }
      end = l - 1;
      if (beg > end) return -1;
    }
    if (end - beg + 1 <= 0) return -1;
    return st.query(beg, end).mn + 1;
  };

  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    cout << Query(s) << endl;
  }
  
  return 0;
}