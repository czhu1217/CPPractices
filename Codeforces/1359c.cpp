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
#include <climits>
#define f first
#define s second
using namespace std;
typedef long long ll;
void solve(){
    ll h, c, t; ll ans=1;
    cin >> h >> c >> t;
    if(t-c<=h-t){
        cout << 2 << "\n"; return;
    }
    if(h==t){cout << 1 << "\n"; return;}
    double approx = (double)(h-t)/(double)(2*t-h-c);
    int lo = floor(approx), hi = ceil(approx);
    if(abs((double)(lo*(h+t)+h)/(double)(2*lo+1)-t)<abs((double)(hi*(h+t)+h)/(double)(2*hi+1)-t)){
        ans = lo;
    }
    else ans = hi;
    cout << ans*2+1 << "\n";
    


}
int main(){
    ll t; cin >> t;
    while(t--)solve();
    return 0;
}