#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  auto Ask = [&](int i, int j) -> bool {
    cout << "? " << i << ' ' << j << endl;
    cout.flush();
    string s; cin >> s;
    return s[0] == 'Y';
  };

  auto Report = [&](vector<int>& v) -> void {
    cout << "!";
    for (auto& i : v) cout << ' ' << i;
    cout.flush();
  };

  auto Merge = [&](vector<int>& a, vector<int>& b) -> vector<int> {
    int i = 0, j = 0, as = a.size(), bs = b.size();
    vector<int> v(as + bs);
    while (i < as && j < bs) {
      if (Ask(a[i], b[j])) {
        v[i + j] = a[i];
        i++;
      } 
      else {
        v[i + j] = b[j];
        j++;
      }
    }
    if (i == as) {
      for (; j < bs; j++) v[i + j] = b[j];
    }
    if (j == bs) {
      for (; i < as; i++) v[i + j] = a[i];
    }
    return v;
  };

  auto MergeSort = [&](auto&& self, vector<int>& v) -> void {
    vector<int> a, b;
    for (int i = 0; i < v.size() / 2; i++) {
      a.push_back(v[i]);
    }
    for (int i = v.size() / 2; i < v.size(); i++) {
      b.push_back(v[i]);
    }

    if (a.size() != 1) self(self, a);
    if (b.size() != 1) self(self, b);

    v = Merge(a, b);
  };
  
  int n; cin >> n;
  vector<int> v(n);
  iota(v.begin(), v.end(), 1);
  MergeSort(MergeSort, v);
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    ans[v[i] - 1] = i + 1;
  }
  Report(ans);

  return 0;
}