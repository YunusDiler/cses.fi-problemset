#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
int32_t main()
{
    int n; cin >> n;
    map<int, int> mp;
    int x, ans = 0, sum = 0;
    while (cin >> x) 
    {
        if (x < 0) x = n - abs(x) % n;
        else x = x % n;
        mp[abs(sum % n)]++;
        sum += x;
        ans += mp[abs(sum % n)];
    }
    cout << ans;
}