#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define endl "\n"

using namespace __gnu_pbds;
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;

  ordered_set s;

  for (int i = 1; i <= n; i++) s.insert(i);

  int pos = 0;

  while (s.size() > 0) {
    pos = (pos + k) % s.size();
    auto it = s.find_by_order(pos);
    cout << *it << " ";
    s.erase(it);
  }

  return 0;
}