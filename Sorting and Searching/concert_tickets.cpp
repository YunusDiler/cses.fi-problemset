#include <bits/stdc++.h>

using namespace std;
 
 
int main(){
    int n, m; cin >> n >> m;
    map<int, int> a;
    vector<int> b(m);
 
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a[x]++;
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    for(int i = 0; i < m; i++){
        auto it = a.upper_bound(b[i]);
        if(it == a.begin()){
            cout << -1 << endl;
        }else{
            it--;
            cout << it->first << endl;
            if(--it->second == 0){
                a.erase(it);
            }
        }
    }
 
    
}