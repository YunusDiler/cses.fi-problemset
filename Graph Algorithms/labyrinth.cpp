#include <bits/stdc++.h>
 
using namespace std;
 
#define needforspeed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long
 
 
 
int main() 
{
    needforspeed
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    vector<vector<char>> parent(n, vector<char>(m));
    int Ax, Ay, Bx, By;
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        size_t a = grid[i].find('A');
        if (a != string::npos)
        {
            Ax = i; Ay = a;
        }
        size_t b = grid[i].find('B');
        if (b != string::npos)
        {
            Bx = i; By = b;
        }
    }
    
    grid[Bx][By] = '.';
    queue<pair<int, int>> s;
    s.push({Ax, Ay});
    parent[Ax][Ay] = 'f';
    while (!s.empty())
    {
        if (parent[Bx][By]) break;
        auto p = s.front();
        int x = p.first;
        int y = p.second;
        s.pop();
        if (y < m - 1 && grid[x][y+1] == '.' && !parent[x][y+1])
        {
            s.push({x, y+1});
            parent[x][y+1] = 'R';
        }
        if (y > 0 && grid[x][y-1] == '.' && !parent[x][y-1])
        {
            s.push({x, y-1});
            parent[x][y-1] = 'L';
        }
        if (x < n - 1 && grid[x+1][y] == '.' && !parent[x+1][y])
        {
            s.push({x+1, y});
            parent[x+1][y] = 'D';
        }
        if (x > 0 && grid[x-1][y] == '.' && !parent[x-1][y])
        {
            s.push({x-1, y});
            parent[x-1][y] = 'U';
        }
    }
    
    if (!parent[Bx][By]){
        cout << "NO";
        return 0;
    }

    int tx = Bx, ty = By;
    vector<char> ans;
    while (parent[tx][ty] != 'f')
    {
        char c = parent[tx][ty];
        ans.push_back(c);
        if (c == 'U') tx++;
        else if (c == 'D') tx--;
        else if (c == 'L') ty++;
        else ty--;
    }

    cout << "YES" << endl << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
    return 0;
}
