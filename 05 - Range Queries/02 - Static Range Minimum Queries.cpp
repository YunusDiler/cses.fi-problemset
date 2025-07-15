#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> tree;
vector<pair<int, int>> width;
int N = 1;



int range(int left, int right, int node = 1)
{
    auto [l, r] = width[node];

    if (l >= left && right >= r) return tree[node];
    else if (r < left || right < l) return INT_MAX;
    else return min(range(left, right, node * 2), range(left, right, node * 2 + 1));
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    while (N < n)
        N <<= 1;
    tree.resize(2 * N, INT_MAX);
    width.resize(2 * N, {0, 0});

    for (int i = 1; i < 2 * N; i <<= 1)
    {
        for (int j = i; j < i + i; j++)
        {
            width[j] = {N + (j - i) * N / i, N + N / i - 1 + (j - i) * N / i};
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> tree[i + N];
    }

    for (int i = 2 * N - 1; i > 1; i -= 2)
    {
        tree[i / 2] = min(tree[i], tree[i - 1]);
    }

    while (q--)
    {
        int l, r; cin >> l >> r;
        cout << range(l + N - 1, r + N - 1) << endl;
    }

    return 0;
}