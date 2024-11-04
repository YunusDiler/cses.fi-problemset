#include <bits/stdc++.h>

#define int long long
#define endl '\n'
 
using namespace std;
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    vector<int> v(n), c(1e6 + 1);
    for (auto& i : v) {cin >> i; ++c[i];}

    for (int i = 1e6; i > 0; i--) {
        int div = 0;
        for (int j = i; j <= 1e6; j += i) div += c[j];
        if (div > 1) {cout << i << endl; return 0;}
    }
    
    return 0;
}