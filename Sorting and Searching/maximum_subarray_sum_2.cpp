#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int32_t main() {
    need_for_speed
    
    int n, a, b; cin >> n >> a >> b;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre[i] += v[i - 1] + pre[i - 1];
    }

    multiset<int> ms;
    int ans = LLONG_MIN;
    for (int i = a; i <= n; i++)
    {
        if (i > b)
        {
            ms.erase(ms.find(pre[i - b - 1]));
        }
        ms.insert(pre[i - a]);
        ans = max(ans, pre[i] - *ms.begin());
    }

    cout << ans;

    return 0;
}