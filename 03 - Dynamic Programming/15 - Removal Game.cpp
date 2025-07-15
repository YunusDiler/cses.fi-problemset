#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int n;
vector<int> v;
int dp[5005][5005][2];

void solve(int l, int r)
{
    if (l > r) return;
    if (dp[l][r][0] != LLONG_MIN) return;
    if (l == r) {
        dp[l][r][0] = v[l];
        dp[l][r][1] = 0;
        return;
    }
    solve(l + 1, r);
    solve(l, r - 1);
    if (v[l] + dp[l + 1][r][1] > v[r] + dp[l][r - 1][1]) {
        dp[l][r][0] = v[l] + dp[l + 1][r][1];
        dp[l][r][1] = dp[l + 1][r][0];
    } else {
        dp[l][r][0] = v[r] + dp[l][r - 1][1];
        dp[l][r][1] = dp[l][r - 1][0];
    }


    return;
}

int32_t main() {
    need_for_speed
    
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n + 1; i++) for (int j = 0; j < n + 1; j++) dp[i][j][0] = dp[i][j][1] = LLONG_MIN;
    
    solve(0, n - 1);
    cout << dp[0][n - 1][0] << endl;
    
    return 0;
}