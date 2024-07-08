#include <bits/stdc++.h>
 
using namespace std;
 
 
const int MOD = 1e9 + 7;
const int N = 2e5+1;
 
int n, k, a, b, deepest, sub[N];
vector<int> tree[N];
bitset<N> banned;
long long ans;
int counter[N];
 
void dfs2(int node, int parent, int r = 1, bool flag = false){
    if (flag) ans += counter[k - r];
    else ++counter[r];
    deepest = max(deepest, r);
    for(auto& child: tree[node]){
        if(child == parent || banned[child]) continue;
        if (r + 1 > k) continue;
        dfs2(child, node, r + 1, flag);
    }
}
 
void solve(int cntr){
    fill(counter + 1, counter + deepest + 1, 0);
    for(auto& nd: tree[cntr]){
        if(banned[nd]) continue;
        dfs2(nd, cntr, 1, 1);
        dfs2(nd, cntr, 1, 0);
    }
    ans += counter[k];
}
 
 
int calc(int node, int parent){
    sub[node] = 1;
    for(auto& child: tree[node]){
        if(child == parent || banned[child]) continue;
        sub[node] += calc(child, node);
    }
 
    return sub[node];
}
 
 
 
int centroid(int node, int parent, int sz){
    for(auto& child: tree[node]){
        if(child == parent || banned[child]) continue;
        if(sub[child] > (sz>>1))return centroid(child, node, sz);
    }
 
    return node;
}
 
void build(int node, int parent){
 
    calc(node, parent);
    int cntr = centroid(node, parent, sub[node]);
    banned[cntr] = true;
 
    //cout << cntr << " " << parent << endl;
 
    solve(cntr);
 
    for(auto& child: tree[cntr]){
        if(child == parent || banned[child]) continue;
        build(child, cntr);
    }
 
}
 
int32_t main(){
 
    //fri("in.txt");
    //fro("out.txt");
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> k;
 
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
 
    build(1, -1);
 
    cout << ans << endl;
 
 
 
 
    return 0;
}