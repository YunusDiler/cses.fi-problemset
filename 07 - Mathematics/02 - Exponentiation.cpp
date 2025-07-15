#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;

int modpow(int a, int b, int mod) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t; cin >> t;
    while (t--)
    {
        int a, b; cin >> a >> b;
        cout << modpow(a, b, MOD) << endl;
    }
    
    
    
    return 0;
}