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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n, q; cin >> n >> q;
  vector<int> v(n);
  for (auto& i : v) cin >> i;
  
  vector<int> a(n);
  stack<int> s;
  for (int i = 0; i < n; i++) {
    while (!s.empty() && v[s.top()] < v[i]) s.pop();
    a[i] = s.empty() ? 0 : s.top() + 1;
    s.push(i);
  }

  vector<array<int, 3>> qry(q);
  vector<int> ans(q);
  for (int i = 0; i < q; i++) qry[i][2] = i;
  for (auto& i : qry) cin >> i[1] >> i[0];
  sort(qry.begin(), qry.end());
  
  vector<Info> info(n + 1);
  LazySegmentTree st(info);

  int it = 0;
  for (int i = 0; i < q; i++) {
    while (it < qry[i][0]) {
      st.modify(a[it] + 1, it + 1, 1);
      it++;
    }
    int res = st.query(qry[i][1], qry[i][1]).sum;
    ans[qry[i][2]] = res;
  }

  for (auto& i : ans) cout << i << endl;
  
  return 0;
}