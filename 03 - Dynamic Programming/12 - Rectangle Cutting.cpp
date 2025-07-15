#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
vector<vector<int>> dp(501, vector<int>(501, 1031));

int solve(int i, int j)
{
    if (dp[i][j] != 1031 || dp[j][i] != 1031) return min(dp[i][j], dp[j][i]);
    int ans = 1031;
    for (int x = 1; x < i; x++)
    {
        ans = min(ans, solve(x, j) + solve(i - x, j) + 1);
    }
    for (int y = 1; y < j; y++)
    {
        ans = min(ans, solve(i, y) + solve(i, j - y) + 1);
    }
    dp[i][j] = ans;
    dp[j][i] = ans;
    return ans;
}

int32_t main() {
    need_for_speed
    
    cin >> n >> m;
    for (int i = 1; i <= 500; i++) dp[i][i] = 0;
    solve(n, m);
    cout << dp[n][m];
    
    
    return 0;
}