#include <bits/stdc++.h>

#define ll long long
#define endl "\n"
#define need_for_speed                                                                                                 \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);                                                                                                     \
    cout.tie(NULL);

using namespace std;

int main()
{
    need_for_speed

        int n;
    cin >> n;

    int count = n, i = 0;
    bool kill = false;

    vector<bool> v(n, true);

    while (count)
    {
        if (v[i])
        {
            if (kill)
            {
                v[i] = false;
                kill = false;
                count--;
                cout << i + 1 << ' ';
            }
            else kill = true;
        }
        i++;
        i %= n;
    }

    return 0;
}