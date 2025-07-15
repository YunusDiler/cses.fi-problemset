#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int32_t main() {
    need_for_speed
    
    int n, x1, y1, x2, y2, x3, y3; cin >> n;
    while (n--)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int area = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
        if (area == 0) cout << "TOUCH\n";
        else if (area < 0) cout << "RIGHT\n";
        else cout << "LEFT\n";
    }
    
    return 0;
}