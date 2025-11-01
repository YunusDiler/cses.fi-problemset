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

struct Tag {
  int put = -1;
  Tag() : put(-1) {}

  void apply(Info& a, int nl, int nr) {
    if (put != -1) {
      a.sum = (nr - nl + 1) * put;
      a.mn = a.mx = put;
    }
  }
};

struct LazySegmentTree {
  int n;
  vector<Info> info;
  vector<Tag> tag;

  LazySegmentTree(vector<Info>& a) : n(1 << (32 - __builtin_clz(a.size() - 1))) {
    info.resize(n << 1);
    tag.resize(n << 1);
    for (int i = 0; i < (int) a.size(); ++i) {
      info[i + n] = a[i];
    }
    for (int i = n - 1; i > 0; --i) {
      info[i] = info[lch].unite(info[rch]);
    }
  }

  void push(int i, int nl, int nr) {
    if (tag[i].put != -1) {
      tag[i].apply(info[i], nl, nr);
      if (nl ^ nr) {
        tag[lch].put = tag[rch].put = tag[i].put;
      }
      tag[i].put = -1;
    }
  }

  void modify(int ql, int qr, int val, int i = 1, int nl = 0, int nr = -1) {
    if (nr == -1) nr = n - 1;
    push(i, nl, nr);
    if (nl > qr || nr < ql) return;

    if (nl >= ql && nr <= qr) {
      tag[i].put = val;
      push(i, nl, nr);
      return;
    }

    int mid = (nl + nr) / 2;
    modify(ql, qr, val, lch, nl, mid);
    modify(ql, qr, val, rch, mid + 1, nr);

    info[i] = info[lch].unite(info[rch]);
  }

  Info query(int ql, int qr, int i = 1, int nl = 0, int nr = -1) {
    if (nr == -1) nr = n - 1;
    push(i, nl, nr);
    if (nl > qr || nr < ql) {
      return Info();
    }
    if (nl >= ql && nr <= qr) {
      return info[i];
    }

    int mid = (nl + nr) >> 1;
    Info a = query(ql, qr, lch, nl, mid);
    Info b = query(ql, qr, rch, mid + 1, nr);

    return a.unite(b);
  }
  
  int bs(int ql, int qr, int x, int i = 1, int nl = 0, int nr = -1) {
    if (nr == -1) nr = n - 1;
    if (nr < ql || nl > qr || info[i].mx < x) {
      return -1;
    }
    if (nl == nr) {
      return nr;
    } 
    push(i, nl, nr);
    int m = (nl + nr) / 2;
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
  
  int n, q; cin >> n >> q;
  vector<int> v(n);
  for (auto& i : v) cin >> i;
  
  
  vector<vector<pair<int, int>>> qrs(n);
  vector<int> ans(q);

  for (int i = 0; i < q; i++) {
    int a, b; cin >> a >> b;
    qrs[a - 1].push_back({b - 1, i});
  }

  vector<int> pref(n + 1);
  for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + v[i - 1];
  vector<int> right(n, n);
  stack<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    while (!s.empty() && v[i] > s.top().first) {
      right[s.top().second] = i;
      s.pop();
    }
    s.push({v[i], i});
  }

  vector<Info> info(n + 1);
  for (int i = 0; i < n; i++) info[i] = v[i];
  LazySegmentTree st(info);

  for (int i = n - 1; i >= 0; i--) {
    st.modify(i, right[i] - 1, v[i]);
    for (auto& [r, id] : qrs[i]) {
      ans[id] = st.query(i, r).sum - (pref[r + 1] - pref[i]);
    }
  }

  for (auto& i : ans) cout << i << endl;

  return 0;
}