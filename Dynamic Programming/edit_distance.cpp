#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

string a, b;
vector<vector<int>> dp(5001, vector<int>(5001, -1));

int solve(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    if (x == 0) return dp[x][y] = y;
    if (y == 0) return dp[x][y] = x;
    if (a[x - 1] == b[y - 1]) 
        return dp[x][y] = solve(x - 1, y - 1);
    return dp[x][y] = min(solve(x - 1, y) + 1, min(solve(x, y - 1) + 1, solve(x - 1, y - 1) + 1));
}

int32_t main() {
    need_for_speed
    
    cin >> a >> b;
    for (int i = 0; i <= a.size(); i++) dp[i][0] = i;
    for (int j = 0; j <= b.size(); j++) dp[0][j] = j;
    
    cout << solve(a.size(), b.size());
    
    return 0;
}
