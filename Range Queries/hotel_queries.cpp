#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

vector<int> tree;
int N = 1;

void update(int index, int value)
{
    tree[index] -= value;
    index >>= 1;
    while (index)
    {
        tree[index] = max(tree[index * 2], tree[index * 2 + 1]);
        index >>= 1;
    }
}

int search(int value, int node = 1)
{
    if (tree[node] < value) return INT_MAX;

    if (node < N && tree[node * 2] >= value) return search(value, node * 2);
    if (node < N && tree[node * 2 + 1] >= value) return search(value, node * 2 + 1);
    return node - N + 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    while (N < n)
        N <<= 1;
    tree.resize(2 * N, -INT_MAX);

    for (int i = 0; i < n; i++)
    {
        cin >> tree[i + N];
    }

    for (int i = 2 * N - 1; i > 1; i -= 2)
    {
        tree[i / 2] = max(tree[i], tree[i - 1]);
    }

    while (q--)
    {
        int i; cin >> i;
        int ans = search(i);
        if (ans == INT_MAX) cout << 0 << endl;
        else
        {
            cout << ans << endl;
            update(ans + N - 1, i);
        }
    }

    return 0;
}