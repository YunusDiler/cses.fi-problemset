#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int32_t main() {
    need_for_speed
    
    int n, q; cin >> n >> q;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    { 
        cin >> v[i];
        v[i] ^= v[i - 1];    
    }
    
    while (q--)
    {
        int a, b; cin >> a >> b;
        cout << (v[a - 1] ^ v[b]) << endl;
    }    
    
    return 0;
}