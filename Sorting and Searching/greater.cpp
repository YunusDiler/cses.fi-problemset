// not a question in cses, this is sub-part of solution for Nested Ranges Count
// prints a vector for a vector, for each element the count of elements greater than or equal with smaller index

#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> tree;
int N = 1;


void update(int index)
{
    index += N - 1;
    while (index)
    {
        tree[index]++;
        index >>= 1;
    } 
}

int range(int left, int right)
{
    left += N - 1;
    right += N - 1;
    int sum = 0;

    while (left < right)
    {
        if (left & 1) sum -= tree[left ^ 1];
        left >>= 1;
        if (!(right & 1)) sum -= tree[right ^ 1];
        right >>= 1;
    }
    sum += tree[right];
    return sum;
}

int32_t main() {
    need_for_speed
    
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    map<int, int> mp;
    for (auto x : v) mp[x] = true;
    vector<int> f;
    int t = 1;
    for (auto m : mp)
    {
        f.push_back(t);
        mp[m.first] = t;
        t++;
    }

    while (N < f.size())
        N <<= 1;
    tree.resize(2 * N, 0);

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = range(mp[v[i]], f.size());
        update(mp[v[i]]);
    }

    for (auto x : ans) cout << x << ' ';
    
    return 0;
}