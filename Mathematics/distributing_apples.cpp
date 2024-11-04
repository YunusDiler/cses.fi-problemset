#include<bits/stdc++.h>
#define int long long
using namespace std;
 
const int mod = 1e9 + 7;
 
int fp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
 
int32_t main()
{
    int n, k; cin >> n >> k;
    vector<int> v(n + k);
    v[0] = v[1] = 1;
    for (int i = 2; i < n + k; i++) {
        v[i] = v[i - 1] * i % mod;
    }
    cout << (v[n + k - 1] * fp(v[n - 1], mod - 2) % mod) * fp(v[k], mod - 2) % mod;
    return 0;
}