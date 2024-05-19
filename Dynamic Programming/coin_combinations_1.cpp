#include <bits/stdc++.h>
 
#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 
vector<int> v;
vector<bool> vis(1000031);
vector<int> val(1000069);
int coin(int target)
{
    if (target < 0) return 0;
    if (target == 0) return 1;
    if (vis[target]) return val[target];
 
    int ans = 0;
    for (int i : v)
    {
        ans += coin(target - i);
    } 
 
    vis[target] = true;
    val[target] = ans % 1000000007;
    return ans % 1000000007;
}
 
int32_t main() {
    need_for_speed
    
    int n, target; cin >> n >> target;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << coin(target);
 
    return 0;
}