#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int32_t main() {
    need_for_speed
    
    int n, q; cin >> n >> q;
    vector<vector<int>> forest(n + 1 , vector<int> (n + 1));
    
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            char c; cin >> c;
            if (c == '*') sum++;
            forest[i][j] = forest[i - 1][j] + sum;
        }
    }
    
    while (q--)
    {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;

        cout << forest[y1 - 1][x1 - 1] - forest[y2][x1 - 1] - forest[y1 - 1][x2] + forest[y2][x2] << endl;
    }
    
    return 0;
}