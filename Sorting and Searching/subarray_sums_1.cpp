#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int32_t main() {
    need_for_speed
    
    int n, t; cin >> n >> t;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    int i = 0, j = 0, sum = v[0], ans = 0;
    while (i < n && j <s n)
    {
        if (sum == t) 
        {
            ans++;
            i++;
            sum += v[i];
        }
        else if (sum < t)
        {
            i++;
            sum += v[i];
        }
        else
        {
            sum -= v[j];
            j++;
        }
    }
    
    cout << ans;

    return 0;
}