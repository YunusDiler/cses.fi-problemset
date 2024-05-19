#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MOD = 1e9 + 7;

using namespace std;

int32_t main() {
    need_for_speed
    
    int n; cin >> n;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<char>> grid(n, vector<char>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
        
    dp[0][0] = 1;
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (x < n - 1 && grid[x + 1][y] == '.')
        {
            if (dp[x + 1][y] == 0) q.push({x + 1, y});
            dp[x + 1][y] += dp[x][y] % MOD;
        }
        if (y < n - 1 && grid[x][y + 1] == '.')
        {
            if (dp[x][y + 1] == 0) q.push({x, y + 1});
            dp[x][y + 1] += dp[x][y] % MOD;
        }
    }

    if (grid[0][0] == '*') cout << 0;
    else cout << dp[n - 1][n - 1] % MOD;
    
    return 0;
}