#include <bits/stdc++.h>
 
#define need_for_speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;
 
int main()
{
    need_for_speed 
    int n, ans = 0;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
 
    vector<int> index(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!index[v[i] - 1])
        {
            ans++;
        }
        index[v[i]] = i;
    }
 
    cout << ans;
 
 
    return 0;
}