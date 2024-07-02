#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

struct Edge {
    int weigth;
    int from;
    int to;
};


vector<int> dist(2501, LLONG_MIN);

int32_t main() {
    need_for_speed
    
    int n, m; cin >> n >> m;
    vector<Edge> v(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> v[i].from >> v[i].to >> v[i].weigth;
    
    dist[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int l = v[j].from, r = v[j].to, w = v[j].weigth;
            if (dist[l] != LLONG_MIN && dist[l] + w > dist[r]) dist[r] = dist[l] + w;
        }
        for (int j = 1; j <= m; j++)
        {
            int l = v[j].from, r = v[j].to, w = v[j].weigth;
            if (dist[l] != LLONG_MIN && dist[l] + w > dist[r]) 
            if (r == n) {cout << -1; return 0;}
        }
    }

    cout << dist[n];
    
    return 0;
}