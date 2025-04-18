#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1ll << 30;

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
  
  int n, q; cin >> n >> q;
  vector<int> v(n);
  for (auto& i : v) cin >> i;

  vector<Info> v1(n), v2(n);
  for (int i = 0; i < n; i++) {
    v1[i] = {i + v[i]};
    v2[i] = {n - i - 1 + v[i]};
  }

  SimpleSegmentTree st1(v1), st2(v2);

  while (q--) {
    int qt; cin >> qt;
    if (qt == 1) {
      int k, x; cin >> k >> x;
      k--;
      st1.modify(k, k + x);
      st2.modify(k, n - k - 1 + x);
    }
    else {
      int k; cin >> k;
      k--;
      int left = st2.query(0, k).mn - (n - k - 1);
      int right = st1.query(k, n - 1).mn - k;
      int ans = min(left, right);
      cout << (ans == INF ? v[0] : ans) << endl;
    }
  }
  
  
  
  return 0;
}