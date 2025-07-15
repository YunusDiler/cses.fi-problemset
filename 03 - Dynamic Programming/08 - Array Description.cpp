#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const int MOD = 1e9 + 7;
int dp[100005][102];

int32_t main() {
    need_for_speed
    
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    
    if (!v[0]) for (int i = 1; i <= m; i++) dp[0][i] = 1;
    else dp[0][v[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        if (!v[i]) for (int j = 1; j <= m; j++) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
        else dp[i][v[i]] = (dp[i - 1][v[i] - 1] + dp[i - 1][v[i]] + dp[i - 1][v[i] + 1]) % MOD;
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) ans += dp[n - 1][i];
    cout << ans % MOD;
    
    
    return 0;
}