#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    long long c; cin >> c;
    for(;;){
        cout << c << " ";
        if(c==1) break;
        if(c&1){c*=3;c++;}
        else c/= 2;
    }
}