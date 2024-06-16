#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
 
/*** Needs C++11 or C++14 ***/
 
/// Treap supporting duplicating values in set
/// Maximum value of treap * ADD must fit in long long
 
struct Treap{ /// hash = 96814
    int len;
    const int ADD = 1000010;
    const int MAXVAL = 1000000010;
    unordered_map <long long, int> mp; /// Change to int if only int in treap
    tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> T;
 
    Treap(){
        len = 0;
        T.clear(), mp.clear();
    }
 
    inline void clear(){
        len = 0;
        T.clear(), mp.clear();
    }
 
    inline void insert(long long x){
        len++, x += MAXVAL;
        int c = mp[x]++;
        T.insert((x * ADD) + c);
    }
 
    inline void erase(long long x){
        x += MAXVAL;
        int c = mp[x];
        if (c){
            c--, mp[x]--, len--;
            T.erase((x * ADD) + c);
        }
    }
 
    /// 1-based index, returns the K'th element in the treap, -1 if none exists
    inline long long kth(int k){
        if (k < 1 || k > len) return -1;
        auto it = T.find_by_order(--k);
        return ((*it) / ADD) - MAXVAL;
    }
 
    /// Count of value < x in treap
    inline int count(long long x){
        x += MAXVAL;
        int c = mp[--x];
        return (T.order_of_key((x * ADD) + c));
    }
 
    /// Number of elements in treap
    inline int size(){
        return len;
    }
};
 
 
int32_t main()
{
    need_for_speed
 
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    Treap s;
    for (int i = 0; i < k; i++) s.insert(v[i]);
    auto t = s.kth(k / 2 + 1);
    int cost = 0;
    for (int i = 0; i < k; i++) cost += abs(v[i] - t);
    cout << cost << ' ';
 
    for (int i = k; i < n; i++)
    {
        s.erase(v[i - k]);
        s.insert(v[i]);
        cost -= abs(v[i - k] - t);
        auto b = s.kth(k / 2 + 1);
        cost += abs(v[i] - b);
        if (!(k & 1)) cost += b - t;
        t = b;
        cout << cost << ' ';
    }
 
    return 0;
}