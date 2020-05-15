#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;
typedef long long ll;
void solve(){
    ll n, m; cin >> n >> m;
    if(n==1){
        cout << 0 << "\n";
    }
    else if(n==2){
        cout << m << "\n";
    }
    else{
        cout << m*2 << "\n";
    }

}
int main(){
    ll t; cin >> t;
    while(t--)solve();
    return 0;
}