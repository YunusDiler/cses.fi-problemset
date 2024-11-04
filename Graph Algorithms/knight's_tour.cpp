#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

vector<vector<bool>> board(8, vector<bool>(8, true));

int check(int x, int y) {
    int ans = 0;
    ans += (x > 1 && y > 0 && board[y - 1][x - 2]);
    ans += (x > 0 && y > 1 && board[y - 2][x - 1]);
    ans += (x < 6 && y > 0 && board[y - 1][x + 2]);
    ans += (x < 7 && y > 1 && board[y - 2][x + 1]);
    ans += (x > 1 && y < 7 && board[y + 1][x - 2]);
    ans += (x > 0 && y < 6 && board[y + 2][x - 1]);
    ans += (x < 6 && y < 7 && board[y + 1][x + 2]);
    ans += (x < 7 && y < 6 && board[y + 2][x + 1]);
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int x, y; cin >> x >> y;
    x--; y--;
    vector<vector<int>> ans(8, vector<int>(8));
    ans[y][x] = 1;
    board[y][x] = false;
    for (int i = 2; i <= 64; i++) {
        int a = 9, nx = 0, ny = 0;
        if (x > 1 && y > 0 && board[y - 1][x - 2] && check(x - 2, y - 1) <= a) {nx = x - 2; ny = y - 1; a = check(nx, ny);} 
        if (x > 0 && y > 1 && board[y - 2][x - 1] && check(x - 1, y - 2) <= a) {nx = x - 1; ny = y - 2; a = check(nx, ny);} 
        if (x < 7 && y > 1 && board[y - 2][x + 1] && check(x + 1, y - 2) <= a) {nx = x + 1; ny = y - 2; a = check(nx, ny);} 
        if (x > 1 && y < 7 && board[y + 1][x - 2] && check(x - 2, y + 1) <= a) {nx = x - 2; ny = y + 1; a = check(nx, ny);} 
        if (x > 0 && y < 6 && board[y + 2][x - 1] && check(x - 1, y + 2) < a) {nx = x - 1; ny = y + 2; a = check(nx, ny);} 
        if (x < 7 && y < 6 && board[y + 2][x + 1] && check(x + 1, y + 2) <= a) {nx = x + 1; ny = y + 2; a = check(nx, ny);} 
        if (x < 6 && y < 7 && board[y + 1][x + 2] && check(x + 2, y + 1) < a) {nx = x + 2; ny = y + 1; a = check(nx, ny);}
        if (x < 6 && y > 0 && board[y - 1][x + 2] && check(x + 2, y - 1) <= a) {nx = x + 2; ny = y - 1; a = check(nx, ny);} 
        x = nx; y = ny;
        ans[y][x] = i;
        board[y][x] = false;
    }

    for (auto v : ans) {
        for (auto i : v) {
            if (i < 10) cout << ' ' << i << ' ';
            else cout << i << ' ';
        }
        cout << endl;
    }
    
    return 0;
}