#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
  int q, n, in1, in2, cur;
  cin >> n >> q;
  int sq = sqrt(n);
  vector<int> v(n);
  vector<int> cnt(200007);
  for (int i = 0; i < n; i++) cin >> v[i];
  set<int> xd;
  for (int i = 0; i < n; i++) {
    xd.insert(v[i]);
  }
  map<int, int> m;
  auto it = xd.begin();
  int counter = 0;
  while (it != xd.end()) {
    m[*it] = counter;
    it++;
    counter++;
  }
  for (int i = 0; i < v.size(); i++) {
    v[i] = m[v[i]];
  }
  vector<int> ans(q);
  vector<vector<pair<pair<int, int>, int> > > queries(sq + 2);
  for (int i = 0; i < q; i++) {
    cin >> in1 >> in2;
    in1--;
    in2--;
    queries[in1 / sq].push_back({{in2, in1}, i});
  }
  for (int i = 0; i < sq + 2; i++) {
    sort(queries[i].begin(), queries[i].end());
  }
  for (int i = 0; i < sq + 2; i++) {
    for (int j = 0; j < queries[i].size(); j++) {
      swap(queries[i][j].first.first, queries[i][j].first.second);
    }
  }
  for (int k = 0; k < sq + 2; k++) {
    int left = 0, right = -1, cur = 0;
    cnt.assign(200007, 0);
    for (int i = 0; i < queries[k].size(); i++) {
      while (right < queries[k][i].first.second) {
        right++;
        if (cnt[v[right]] == 0) cur++;
        cnt[v[right]]++;
      }
      while (left > queries[k][i].first.first) {
        left--;
        if (cnt[v[left]] == 0) cur++;
        cnt[v[left]]++;
      }
      while (left < queries[k][i].first.first) {
        if (cnt[v[left]] == 1) cur--;
        cnt[v[left]]--;
        left++;
      }
      ans[queries[k][i].second] = cur;
    }
  }
  for (auto i : ans) cout << i << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}