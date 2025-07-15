#include <bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
#define endl '\n'
#define lch (i << 1)
#define rch (i << 1 | 1)
 
constexpr int INF = 1ll << 61;
 
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
    for (int i = 0; i < a.size(); ++i) {
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
 
  int N; cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) cin >> v[i];
  
  vector<vector<int>> adj(2 * N + 1), rev(2 * N + 1); // 2-SAT
  vector<Info> info(N + 1);
  LazySegmentTree st(info);
 
  vector<vector<pair<int, int>>> resp(N);
  vector<bool> seen(N + 1);
  int top = 1;
 
  for (int i = 0; i < N; i++) {
    while (seen[top]) top++;
    seen[v[i]] = 1;
 
    if (v[i] == top) continue;
 
    int last = st.query(top, v[i] - 1).mx;
    st.modify(v[i], v[i], i);
    
    if (last == -INF) continue;
 
    resp[last].push_back({top, v[i]});
    last = v[last];
    
    adj[2 * v[i] - 1].push_back(2 * last);
    rev[2 * last].push_back(2 * v[i] - 1);
    adj[2 * last - 1].push_back(2 * v[i]);
    rev[2 * v[i]].push_back(2 * last - 1);
    
    adj[2 * v[i]].push_back(2 * last - 1);
    rev[2 * last - 1].push_back(2 * v[i]);
    adj[2 * last].push_back(2 * v[i] - 1);
    rev[2 * v[i] - 1].push_back(2 * last);
  }
 
  vector<Info> info2(N + 1);
  LazySegmentTree st2(info2);
 
  for (int i = 0; i < N; i++) {
    for (auto [l, r] : resp[i]) {
      int last = st2.query(l, r).mn;
      if (last == INF) continue;
      
      last = v[last];
      
      adj[2 * r - 1].push_back(2 * last);
      rev[2 * last].push_back(2 * r - 1);
      adj[2 * last - 1].push_back(2 * r);
      rev[2 * r].push_back(2 * last - 1);
      
      adj[2 * r].push_back(2 * last - 1);
      rev[2 * last - 1].push_back(2 * r);
      adj[2 * last].push_back(2 * r - 1);
      rev[2 * r - 1].push_back(2 * last);
    }
    st2.modify(v[i], v[i], i);
  }
  
  vector<bool> visited(2 * N + 1);
  vector<int> order;
 
  auto dfs1 = [&](auto&& self, int from) -> void {
    visited[from] = 1;
    for (auto& to : adj[from]) {
      if (!visited[to]) self(self, to);
    }
    order.push_back(from);
  };
 
  vector<int> scc(2 * N + 1);
 
  auto dfs2 = [&](auto&& self, int from, int counter) -> void {
    scc[from] = counter;
    for (auto& to : rev[from]) {
      if (!scc[to]) self(self, to, counter);
    }
    return;
  };
 
  for (int i = 1; i <= 2 * N; i++) {
    if (!visited[i]) dfs1(dfs1, i);
  }
 
  int counter = 1;
  for (int i = 2 * N - 1; i >= 0; i--) {
    if (!scc[order[i]]) dfs2(dfs2, order[i], counter++);
    
  }
 
  vector<int> ans(N + 1);
  bool flag = false;
 
  
  for (int i = 1; i <= N && !flag; i++) {
    if (scc[2 * i] == scc[2 * i - 1]) flag = true;
    
    ans[i] = (scc[2 * i - 1] < scc[2 * i] ? 2 : 1);
  }
  
 
  if (flag) cout << "IMPOSSIBLE";
  else for (int i = 1; i <= N; i++) cout << ans[v[i - 1]] << ' ';
 
 
 
  return 0;
}