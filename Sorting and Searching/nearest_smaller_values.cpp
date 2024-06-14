#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
int32_t main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    priority_queue<pair<int, int>> pq;
    vector<int> ans(n);
    
    for (int i = n; i >= 0; i--)
    {
        while (!pq.empty() && pq.top().first > v[i])
        {
            ans[pq.top().second] = i;
            pq.pop();
        }
        pq.push({v[i], i - 1});
    }
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    return 0;
}