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
    ll a, b, c, d; ll ans=0;
    cin >> a >> b >> c >> d;
    for(ll y=c;y>=b;y--){
        ll lo = max(a, c-y+1), hi;
        if(lo>b)continue;
        if(lo+y-c>=d-c+1){
            ans += (d-c+1)*(b-lo+1);
        }
        else if(b+y-c<=d-c+1){
            ans += (lo+y-c+b+y-c)*(b-lo+1)/2;
        }
        else{
            hi = d+1-y;
             ans += (lo+y-c+hi+y-c)*(hi-lo+1)/2;
             ans += max((ll)0, (b-hi)*(d-c+1));
        }
    }
    cout << ans << "\n";

}
int main(){
   solve();
   return 0;
}
