#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

struct point {
    int x, y;
};

int ccw(point a, point b, point c) {
    int area = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
    if (area > 0) return 1;
    return 0;
}

int area(point a, point b, point c) {
    return abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

int32_t main() {
    need_for_speed
    
    int n; cin >> n;
    int x, y; cin >> x >> y;
    int a, b; cin >> a >> b;

    int left = 0, right = 0;

    for (int i = 2; i < n; i++)
    {
        int x1, y1; cin >> x1 >> y1;
        if (ccw({x, y}, {a, b}, {x1, y1})) left += area({x, y}, {a, b}, {x1, y1});
        else right += area({x, y}, {a, b}, {x1, y1});
        a = x1, b = y1;
    }
    
    cout << abs(left - right);
    
    
    return 0;
}