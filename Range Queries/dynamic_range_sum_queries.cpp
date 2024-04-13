#include <bits/stdc++.h>

#define need_for_speed                                                                                                 \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);                                                                                                     \
    cout.tie(NULL)

using namespace std;



int main()
{
    need_for_speed;
    int n, q;
    cin >> n >> q;
    int v = 1;
    while (v < n)
        v *= 2;
    int len = v * 2 - 1;
    vector<long long> a(len, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int j = v; 
    for (int i = 0; i < len - 1; i+=2)
    {
        a[j] = a[i] + a[i + 1];
        j++;
    }

    reverse(a.begin(), a.end());
    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            l = v + l - 1;
            int diff = r - a[l];
            a[l] = r;
            while (--l)
            {
                l /= 2;
                a[l] += diff;
            }
        }
        else
        {
            long long ans = a[0];
            int li = 0, ri = v - 1;
            cout << ans << endl;
        }
    }   
}