#include <bits/stdc++.h>
 
#define int long long
#define endl '\n'
 
using namespace std;
 
const int MOD = 1e9 + 7;
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
    a.sum += val;
    a.mn += val;
    a.mx += val;
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
  
  int n; cin >> n;
  vector<int> v(n);
  map<int, int> mp;
  for (auto& i : v) {cin >> i; mp[i] = 1;}
  
  
  int c = 0;
  for (auto& [x, y] : mp) {
    mp[x] = c++;
  }
 
  vector<Info> info(n);
  SimpleSegmentTree st(info);
 
  vector<int> pref(n), suff(n);
  for (int i = 0; i < n; i++) {
    int x = mp[v[i]];
    int inv = st.query(0, x).sum;
    pref[i] = inv;
 
    st.modify(x, 1);
  }
 
  vector<Info> info2(n);
  SimpleSegmentTree st2(info);
 
  for (int i = n - 1; i >= 0; i--) {
    int x = mp[v[i]];
    int inv = st2.query(0, x).sum;
    suff[i] = inv;
 
    st2.modify(x, 1);
  }
 
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += min(i - pref[i], n - i - 1 - suff[i]);
  }
 
  cout << ans << endl;
  
  
  return 0;
}

