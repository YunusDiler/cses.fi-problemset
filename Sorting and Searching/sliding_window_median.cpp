#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    ordered_set s;
    for (int i = 0; i < k; i++) s.insert(v[i]);
    auto p = *s.find_by_order(k / 2);
    auto q = *s.find_by_order(k / 2 - 1);
    if (k % 2 == 0) cout << min(p, q) << ' ';
    else cout << p << ' ';

    for (int i = k; i < n; i++)
    {
        s.erase(s.upper_bound(v[i - k]));
        s.insert(v[i]);
        auto p = *s.find_by_order(k / 2);
        auto q = *s.find_by_order(k / 2 - 1);
        if (k % 2 == 0) cout << min(p, q) << ' ';
        else cout << p << ' ';
    }

    return 0;
}