#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

 
int32_t main() {
    need_for_speed

    long long n, sum = 0; cin >> n;
    long long m = 0, x;
    for (int i = 0; i < n; i++) {cin >> x; sum += x; m = max(m, x);}
    
    if (2 * m > sum) cout << 2 * m;
    else cout << sum;
    
    return 0;
}