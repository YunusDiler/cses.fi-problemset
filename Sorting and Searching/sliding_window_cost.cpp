#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
 
int32_t main()
{
    need_for_speed
 
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    ordered_set s;
    for (int i = 0; i < k; i++) s.insert(v[i]);
    auto t = *s.find_by_order(k / 2);
    int cost = 0;
    for (int i = 0; i < k; i++) cost += abs(v[i] - t);
    cout << cost << ' ';
 
    for (int i = k; i < n; i++)
    {
        s.erase(s.upper_bound(v[i - k]));
        s.insert(v[i]);
        cost -= abs(v[i - k] - t);
        auto b = *s.find_by_order(k / 2);
        cost += abs(v[i] - b);
        if (!(k & 1)) cost += b - t;
        t = b;
        cout << cost << ' ';
    }
 
    return 0;
}