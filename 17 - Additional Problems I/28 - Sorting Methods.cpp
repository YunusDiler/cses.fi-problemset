#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;

struct BIT {
  int n;
  std::vector<int> bit;

  BIT(int size) : n(size), bit(size + 1, 0) {}

  void add(int idx, int val) {
    for (; idx <= n; idx += idx & -idx) bit[idx] += val;
  }

  void range_add(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
  }

  int point_query(int idx) {
    int res = 0;
    for (; idx > 0; idx -= idx & -idx) res += bit[idx];
    return res;
  }
};

template<typename T>
int LIS(const vector<T>& a) {
  vector<T> u;
  for (const T& x : a) {
    auto it = lower_bound(u.begin(), u.end(), x);
    if (it == u.end()) {
      u.push_back(x);
    } else {
      *it = x;
    }
  }
  return (int) u.size();
}

main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vector<int> v(n);
  for (auto& i : v) cin >> i;

  int ans1 = 0;
  BIT bit(n);
  for (int i = 0; i < n; i++) {
    ans1 += bit.point_query(v[i]);
    bit.range_add(1, v[i], 1);
  }

  vector<int> v2 = v;
  int ans2 = 0;
  while (true) {
    bool noswap = true;
    for (int i = 0; i < n; i++) {
      if (v2[i] != i + 1) {
        swap(v2[i], v2[v2[i] - 1]);
        ans2++;
        noswap = false;
      }
    }
    if (noswap) break;
  }

  int ans3 = n - LIS(v);

  int ans4 = 0;
  int it = 1;
  for (int i = 0; i < n; i++) {
    if (v[i] == it) it++;
    else if (v[i] > it) {
      ans4 = v[i] - 1;
      it = v[i] + 1;
    }
  }

  cout << ans1 << ' ' << ans2 << ' ' << ans3 << ' ' << ans4;

  return 0;
}
