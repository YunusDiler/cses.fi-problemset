#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long ans = 1e18;
    int l = 0, r = 1e9;
    while (l <= r)
    {
        long long sum = 0, sum2 = 0;
        int m = (l + r) / 2;
        for (auto x : a)
        {
            sum += abs(x - m);
            sum2 += abs(x - m - 1);
        }
        ans = min(ans, sum);
        if (sum2 < sum)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    cout << ans << endl;
}