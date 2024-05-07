#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds; 
using namespace std;
  
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
  
#define ll long long
#define endl "\n"
#define need_for_speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


int main()
{
    need_for_speed;

    int n, q;
    cin >> n >> q;

    ordered_set s;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert({a[i], i});
    }

    while (q--)
    {
        char c;
        cin >> c;

        if (c == '!')
        {
            int k, x;
            cin >> k >> x;
            k--;

            s.erase({a[k], k});
            a[k] = x;
            s.insert({a[k], k});
        }
        else
        {
            int l, r;
            cin >> l >> r;

            cout << s.order_of_key({r + 1, 0}) - s.order_of_key({l, 0}) << endl;
        }
    }
    

    return 0;
}