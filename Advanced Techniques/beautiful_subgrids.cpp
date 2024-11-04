#include <bits/stdc++.h>
#pragma GCC target("popcnt")
 
#define int long long
#define endl '\n'
 
using namespace std;
 
const int MAXN = 3005;
 
bitset<MAXN> grid[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
 
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int corners = (grid[i] & grid[j]).count();
            ans += (corners - 1) * corners / 2;
        }
    }
 
    cout << ans << endl;
    
    
    
    return 0;
}
