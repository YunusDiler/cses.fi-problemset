#include <bits/stdc++.h>
 
#define need_for_speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
int main()
{
    need_for_speed
    int x, n;
    cin >> x >> n;
    map<int, int> index;
    index[0] = x;
    map<int, int> len;
    len[x] = 1;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        index[p] = 0;
        auto it = index.find(p);
        it--;
        int l = it->second;
        len[l]--;
        if (len[l] == 0)
            len.erase(l);
        it->second = p - it->first;
        index[p] = l - p + it->first;
        len[p - it->first]++;
        len[l - p + it->first]++;
        cout << len.rbegin()->first << " ";
    }
    return 0;
}