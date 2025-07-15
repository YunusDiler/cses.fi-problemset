#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    int ans = 0;

    __int128 k = 1;
    while (k <= n) {
        __int128 t = n / k, kmax = n / t, kmin = n / (t + 1) + 1, s = (kmax - kmin + 1) * (kmax + kmin) / 2;
        ans = (ans + t * s) % MOD;
        k = kmax + 1;
    }
    cout << ans << endl;
    
    
    
    return 0;
}