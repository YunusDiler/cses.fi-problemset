#include <bits/stdc++.h>
 
#define int long long
#define endl '\n'
 
using namespace std;
 
vector<int> tree;
vector<pair<int, int>> width;
int N = 1;
 
 
void update(int left, int right, int value, int node = 1)
{
    auto[l, r] = width[node];
 
    if (l > right || r < left) return;
    else if (left <= l && r <= right) tree[node] += value;
    else
    {
        update(left, right, value, node * 2);
        update(left, right, value, node * 2 + 1);
    }
    return;
}
 
int sum(int index)
{
    int s = 0;
    while (index)
    {
        s += tree[index];
        index >>= 1;
    }
    return s;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    while (N < n)
        N <<= 1;
    tree.resize(2 * N, 0);
    width.resize(2 * N, {0, 0});
 
    for (int i = 1; i < 2 * N; i <<= 1)
    {
        for (int j = i; j < i + i; j++)
        {
            width[j] = {N + (j - i) * N / i, N + N / i - 1 + (j - i) * N / i};
        }
    }
 
 
 
    vector<int> list(n + 1);
    vector<int> last(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> list[i];
    }
 
    for (int i = 1; i <= n; i++)
    {
        int index; cin >> index;
        int l = sum(index + last[index] + N - 1);
        while (l != sum(index + l + N - 1))
        {
            l = sum(index + l + N - 1);
            last[index] = l + 1;
        }
        cout << list[index + l] << ' ';
        update(index + l + N - 1, n + N - 1, 1);
    }
 
 
    return 0;
}