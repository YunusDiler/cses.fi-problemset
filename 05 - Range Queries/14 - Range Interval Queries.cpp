#include <bits/stdc++.h>
 
using namespace std;

class FenwickTree {
 public:
  vector<int> fenw;
  int n;

  FenwickTree() : n(0) {}
  FenwickTree(int n_) : n(n_) {
    fenw.resize(n);
  }

  void Modify(int x, int v) {
    assert(0 <= x && x <= n);
    while (x < n) {
      fenw[x] += v;
      x |= x + 1;
    }
  }

  int Query(int x) {
    assert(0 <= x && x <= n);
    int v{};
    while (x > 0) {
      v += fenw[x - 1];
      x &= x - 1;
    }
    return v;
  }

  int Range(int l, int r) {
    return Query(r + 1) - Query(l);
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q; cin >> n >> q;
  vector<int> v(n);
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    s[i] = v[i];
  }
  vector<array<int, 4>> qs(q);
  vector<int> id(q);
  iota(id.begin(), id.end(), 0);
  vector<int> ans(q);
 
  for (int i = 0; i < q; i++) {
    cin >> qs[i][0] >> qs[i][1] >> qs[i][2] >> qs[i][3];
    s.push_back(qs[i][2]);
    s.push_back(qs[i][3]);
  }
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  auto idx = [&](int x){return lower_bound(s.begin(), s.end(), x) - s.begin();};

 
  sort(id.begin(), id.end(), [&](int& a, int& b){return qs[a][0] < qs[b][0];});
  int qit = 0;
  FenwickTree ft((int) s.size() + 1);
  for (int i = 0; i < n; i++) {
    while (qit < q && qs[id[qit]][0] == i + 1) {
      int c = qs[id[qit]][2], d = qs[id[qit]][3];
      int x = ft.Range(idx(c), idx(d));
      ans[id[qit]] -= x;
      qit++;
    }
    ft.Modify(idx(v[i]), 1);
  }
  
  sort(id.begin(), id.end(), [&](int& a, int& b){return qs[a][1] < qs[b][1];});
  ft = FenwickTree((int) s.size() + 1);
  qit = 0;
  for (int i = 0; i < n; i++) {
    ft.Modify(idx(v[i]), 1);
    while (qit < q && qs[id[qit]][1] == i + 1) {
      int c = qs[id[qit]][2], d = qs[id[qit]][3];
      int x = ft.Range(idx(c), idx(d));
      ans[id[qit]] += x;
      qit++;
    }
  }
 
  for (auto& i : ans) cout << i << endl;
 
  return 0;
}