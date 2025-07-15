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
    
    int n, ans; cin >> n >> ans;
    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        if ((i & (n - 1)) == i) ans ^= x;
    }

    cout << ans << endl;
    
    return 0;
}