#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define endl "\n"
#define need_for_speed                                                                                                 \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);                                                                                                     \
    cout.tie(NULL)

using namespace __gnu_pbds;
using namespace std;

int main()
{
    need_for_speed;

    int n, k;
    cin >> n >> k;

    ordered_set s;

    for (int i = 1; i <= n; i++)
        s.insert(i);

    int pos = 0;

    while (s.size() > 0)
    {
        pos = (pos + k) % s.size();
        auto it = s.find_by_order(pos);
        cout << *it << " ";
        s.erase(it);
    }

    return 0;
}