// URL: https://cses.fi/problemset/task/1647
#include <bits/stdc++.h>
 
#define need_for_speed                                                                                                 \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);                                                                                                     \
    cout.tie(NULL)
 
using namespace std;
 
int main()
{
    need_for_speed;
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<long long>> dp(n, vector<long long>(20, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = a[i];
    for (int j = 1; j < 20; j++)
    {
        for (int i = 0; i + (1 << j) <= n; i++)
        {
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        long long ans = 1e18;
        for (int j = 19; j >= 0; j--)
        {
            if ((1 << j) <= r - l + 1)
            {
                ans = min(ans, dp[l][j]);
                l += (1 << j);
            }
        }
        cout << ans << endl;
    }
}
