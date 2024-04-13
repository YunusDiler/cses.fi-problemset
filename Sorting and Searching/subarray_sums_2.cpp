#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int32_t main() {
    need_for_speed
    
    int n, t, ans = 0; cin >> n >> t;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    map<int, int> m;
    m[0]++;

    vector<int> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pref[i] = v[i - 1] + pref[i - 1];
        m[pref[i]]++;

        ans += m[pref[i] - t];
    }

    if (!t) ans -= n;

    cout << ans;
    

    return 0;
}