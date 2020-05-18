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
    ll ans=0;
    ll a, b, c, d; cin >> a >> b >>c >>d;
    if(b<a&&c<=d){cout << -1 << "\n"; return;}
    a -= b;
    ans += b;
    if(a>0)ans += max((double)0, ceil((double)a/(double)(c-d)))*c;
    cout << ans << "\n";



}
int main(){
    ll t; cin >> t;
    while(t--)solve();
    return 0;
}