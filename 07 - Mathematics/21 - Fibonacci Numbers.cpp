#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;

map<int, bool> mp;
map<int, int> val;


int fib(int n) {
    if (n < 2) return 1;
    int a = 0, b = 0;
    if (!mp[n / 2]) {
        a = fib(n / 2);
        mp[n / 2] = true;
        val[n / 2] = a;
    }
    else a = val[n / 2];
    
    if (!mp[n / 2 - 1]) {
        b = fib(n / 2 - 1);
        mp[n / 2 - 1] = true;
        val[n / 2 - 1] = b;
    }
    else b = val[n / 2 - 1];

    int ans;
    if (n & 1) {
        int c = 0;
        if (!mp[n / 2 + 1]) {
            c = fib(n / 2 + 1);
            mp[n / 2 + 1] = true;
            val[n / 2 + 1] = c;
        }
        else c = val[n / 2 + 1];

        ans = a * (c + b) % MOD;
    }
    else {
        ans = (a * a % MOD + b * b % MOD) % MOD;
    }
    mp[n] = true;
    val[n] = ans; 
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    mp[0] = 1;
    mp[1] = 1;
    val[0] = 1;
    val[1] = 1;

    
    int n; cin >> n;
    cout << (n ? fib(n - 1) : 0);
    
    return 0;
}

/*
F8
F7 F6
2F6 F5
3F5 2F4
5F4 3F3
8F3 5F2


F5
F4 F3
2F3 F2
3F2 2F1

0 1 1 2 3 5 8
*/