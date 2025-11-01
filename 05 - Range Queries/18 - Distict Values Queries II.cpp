#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

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
  SimpleSegmentTree(vector<Info>& a)
      : n(1 << (32 - __builtin_clz(a.size() - 1))) {
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
    Info left, right;
    while (l <= r) {
      if (l & 1) {
        left = left.unite(info[l++]);
      }
      if (~r & 1) {
        right = info[r--].unite(right);
      }
      l >>= 1, r >>= 1;
    }
    return left.unite(right);
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

  int n, q;
  cin >> n >> q;
  vector<int> v(n + 1);
  vector<Info> info(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  
  set<pair<int, int>> s;

  auto next = [&](int pos, int value) -> int {
    auto it = s.upper_bound({value, pos});
    if (it == s.end() || it->first != value) {
      return INF;
    }
    return it->second;
  };

  auto prev = [&](int pos, int value) -> int {
    auto it = s.lower_bound({value, pos});
    if (it == s.begin()) return 0;
    it--;
    if (it->first != value) return 0;
    return it->second;
  };

  for (int i = 1; i <= n; i++) {
    s.insert({v[i], i});
  }

  for (int i = 1; i <= n; i++) {
    int next_pos = next(i, v[i]);
    info[i] = Info(next_pos);
  }
  SimpleSegmentTree seg(info);

  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int k, u;
      cin >> k >> u;

      int prev_pos, next_pos;

      prev_pos = prev(k, v[k]);
      next_pos = next(k, v[k]);
      seg.modify(prev_pos, next_pos);
      s.erase({v[k], k});

      v[k] = u;

      prev_pos = prev(k, v[k]);
      seg.modify(prev_pos, k);
      next_pos = next(k, v[k]);
      seg.modify(k, next_pos);
      s.insert({v[k], k});
    } else {
      int a, b;
      cin >> a >> b;
      int pos = seg.query(a, b).mn;
      if (pos <= b) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    }
  }

  return 0;
}