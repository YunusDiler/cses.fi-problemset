#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int32_t main() {
    need_for_speed
    
    int n, x; cin >> n >> x;
    vector<int> p(n), m(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> m[i];
    
    vector<int> dp(x + 1);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = x; j >= p[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - p[i]] + m[i]);
        }
    cout << dp[x];
    
    return 0;
}