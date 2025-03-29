#include <bits/stdc++.h>
using namespace std;

#define int long long
constexpr int INF = 1ll << 61;

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
  int delta = 0;
  int put = -1;
  Tag() : put(-1), delta(0) {}

  void apply(Info& a, int nl, int nr) {
    a.sum += (delta * (nr - nl + 1));
    a.mn += delta;
    a.mx += delta;
  }
};

struct LazySegmentTree {
  int n;
  vector<Info> info;
  vector<Tag> tag;
  LazySegmentTree(vector<Info>& a) : n(1 << (32 - __builtin_clz(a.size() - 1))) {
    info.resize(n << 1);
    tag.resize(n << 1);
    for (int i = 0; i < a.size(); ++i) {
      info[i + n] = a[i];
    }
    for (int i = n - 1; i > 0; --i) {
      info[i] = info[lch].unite(info[rch]);
    }
  }

  void push(int i, int nl, int nr) {   
    if (tag[i].delta == 0) return;
    tag[i].apply(info[i], nl, nr);
    if (nl ^ nr) {
      tag[lch].delta += tag[i].delta;
      tag[rch].delta += tag[i].delta;
    }
    tag[i].delta = 0;
  }

  void modify(int ql, int qr, int val, int i = 1, int nl = 0, int nr = -1) {
    if (nr == -1) nr = n - 1;
    push(i, nl, nr);
    if (nl > qr || nr < ql) return;

    if (nl >= ql && nr <= qr) {
      tag[i].delta += val;
      push(i, nl, nr);
      return;
    }

    int mid = (nl + nr) / 2;
    modify(ql, qr, val, lch, nl, mid);
    modify(ql, qr, val, rch, mid+1, nr);

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

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<Info> info(N);
  vector<int> arr(N);
  int x = 0;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    x += arr[i];
    info[i] = {x};
  }
  LazySegmentTree st(info);
  while (Q--) {
    int qt; cin >> qt;
    if (qt == 1) {
      int k, u;
      cin >> k >> u;
      --k;
      st.modify(k, N - 1, u - arr[k]);
      arr[k] = u;
    } else {
      int l, r;
      cin >> l >> r;
      --l, --r;
      int s = st.query(l, r).mx;
      if (l) s -= st.query(l - 1, l - 1).mx;
      s = max(0ll, s);
      cout << s << '\n';
    }
  }
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1; // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}