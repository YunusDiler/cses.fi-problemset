#include <bits/stdc++.h>

#define ll long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

struct point {
    ll x, y;
};

ll ccw(point a, point b, point c) {
    ll area = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
    if (area > 0) return 1;
    if (area < 0) return -1;
    return 0;
}

bool on_segment(point a, point b, point c) {
    if (b.x <= max(a.x, c.x) && b.x >= min(a.x, c.x) && b.y <= max(a.y, c.y) && b.y >= min(a.y, c.y)) return true;
    return false;
}

bool intersect(point a, point b, point c, point d) {
    ll abc = ccw(a, b, c);
    ll abd = ccw(a, b, d);
    ll cda = ccw(c, d, a);
    ll cdb = ccw(c, d, b);

    if (abc != abd && cda != cdb) return true;

    if (abc == 0 && on_segment(a, c, b)) return true;
    if (abd == 0 && on_segment(a, d, b)) return true;
    if (cda == 0 && on_segment(c, a, d)) return true;
    if (cdb == 0 && on_segment(c, b, d)) return true;
    return false;
}

int32_t main() {
    need_for_speed
    
    ll n, x1, y1, x2, y2, x3, y3, x4, y4; cin >> n;
    while (n--)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if (intersect({x1, y1}, {x2, y2}, {x3, y3}, {x4, y4})) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}