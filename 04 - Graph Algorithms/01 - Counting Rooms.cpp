#include <bits/stdc++.h>

#define needforspeed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long

using namespace std;


int main() 
{
    needforspeed
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    vector<vector<bool>> visited(n, vector<bool>(m));
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];   
    }

    int ans = 0;
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                ans++;
                s.push({i, j});
                visited[i][j] = true;
                while (!s.empty())
                {
                    auto [x, y] = s.top();
                    s.pop();
                    if (y < m - 1 && grid[x][y+1] == '.' && !visited[x][y+1])
                    {
                        s.push({x, y+1});
                        visited[x][y+1] = true;
                    }
                    if (y > 0 && grid[x][y-1] == '.' && !visited[x][y-1])
                    {
                        s.push({x, y-1});
                        visited[x][y-1] = true;
                    }
                    if (x < n - 1 && grid[x+1][y] == '.' && !visited[x+1][y])
                    {
                        s.push({x+1, y});
                        visited[x+1][y] = true;
                    }
                    if (x > 0 && grid[x-1][y] == '.' && !visited[x-1][y])
                    {
                        s.push({x-1, y});
                        visited[x-1][y] = true;
                    }
                }
            }
        }
    }
    cout << ans;
}