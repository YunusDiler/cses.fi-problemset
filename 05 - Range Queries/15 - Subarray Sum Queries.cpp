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
  int seg, pref, suff;

  Info() : sum(0), mn(INF), mx(-INF), seg(0), pref(0), suff(0) {}
  Info(int x) : sum(x), mn(x), mx(x), seg(max(x, 0LL)), pref(max(x, 0LL)), suff(max(x, 0LL)) {}

  Info unite(const Info& b) {
    Info res;
    res.sum = sum + b.sum;
    res.mn = min(mn, b.mn);
    res.mx = max(mx, b.mx);
    res.pref = max(pref, sum + b.pref);
    res.suff = max(b.suff, b.sum + suff);
    res.seg = max(max(seg, b.seg), suff + b.pref);
    return res;
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
    a.seg = max(val, 0LL);
    a.pref = max(val, 0LL);
    a.suff = max(val, 0LL);
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
        res = info[r--].unite(res);
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
  
  vector<Info> info(n);
  for (int i = 0; i < n; i++) info[i] = v[i];
  SimpleSegmentTree st(info);

  while (q--) {
    int a, b; cin >> a >> b;
    st.modify(a - 1, b);
    cout << st.query(0, n - 1).seg << endl;
  }
  
  
  return 0;
}