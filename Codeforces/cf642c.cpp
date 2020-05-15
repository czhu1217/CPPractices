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
    ll n; cin >> n;
    ll ans=0;
    for(ll i=n;i>1;i-=2){
        ll mo = i/2;
        ans += mo*(i*i-(i-2)*(i-2));

    }
    cout << ans << "\n";

}
int main(){
    ll t; cin >> t;
    while(t--)solve();
    return 0;
}