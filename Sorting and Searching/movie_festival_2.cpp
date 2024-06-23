#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int32_t main() {
    need_for_speed
    
    int n, k; cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].second >> v[i].first;
    sort(v.begin(), v.end());

    int ans = 0;
    multiset<int> ms;

    for (int i = 0; i < k; i++) ms.insert(0);

    for (int i = 0; i < n; i++)
    {
        auto it = ms.upper_bound(v[i].second);
        if (it == ms.begin()) continue;
        ms.erase(--it);
        ms.insert(v[i].first);
        ans++;
    }
    cout << ans;
    
    
    return 0;
}