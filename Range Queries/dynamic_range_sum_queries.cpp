#include <bits/stdc++.h>

#define int long long
#define need_for_speed                                                                                                 \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);                                                                                                     \
    cout.tie(NULL)

using namespace std;

vector<int> tree;
int N = 1;


void update(int index, int value)
{
    index += N - 1;
    int dif = value - tree[index];
    while (index)
    {
        tree[index] += dif;
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


int32_t main()
{
    need_for_speed;
    int n, q;
    cin >> n >> q;
    while (N < n)
        N <<= 1;
    tree.resize(2 * N, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> tree[i + N];
    }

    for (int i = 2 * N - 1; i > 1; i -= 2)
    {
        tree[i / 2] = tree[i] + tree[i - 1];
    }

    while (q--)
    {
        int t, k, u; cin >> t >> k >> u;
        if (t & 1) update(k, u);
        else cout << range(k, u) << endl;
    }

    return 0;
}