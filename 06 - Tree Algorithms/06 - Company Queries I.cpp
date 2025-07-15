#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

vector<vector<int>> par;


int32_t main() {
    need_for_speed
    
    int n, q; cin >> n >> q;
    par.resize(n + 1, vector<int>(20));
    for (int i = 2; i <= n; i++)
    {
        cin >> par[i][0];
    }
    for (int j = 1; j < 19; j++)
    {
        for (int i = 2; i <= n; i++)
        {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }

    while (q--) {
        int node, h, a = 0; cin >> node >> h;
        while (h) {
            if (h & 1)
                node = par[node][a];
            if (!node) break;

            a++;
            h >>= 1;
        }
        if (!node) node = -1;
        cout << node << endl;
    }
    
    return 0;
}