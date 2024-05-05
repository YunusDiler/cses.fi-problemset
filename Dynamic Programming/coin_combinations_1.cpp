#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> v;
int ans = 0;
vector<bool> vis(1000031);
vector<int> val(1000069);
void coin(int target)
{
    if (target < 0) return;
    if (!target) {ans++; return;}
    if (vis[target]) {ans += val[target]; return;}
    for (auto c : v)
    {
        coin(target - c);
    }
    vis[target] = true;
    val[target] = ans;
    return;
}

int32_t main() {
    need_for_speed
    
    int n, target; cin >> n >> target;
    
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), greater<int>());
    coin(target);
    cout << ans;
    
    

    return 0;
}