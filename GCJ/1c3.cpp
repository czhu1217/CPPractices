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
ll a[10005]; 
void solve(){
    map<ll, ll> mp; bool two=0, thr=0, half=0; ll mx=0; int ans=2;
    ll N, D; cin >> N >> D;
    if(D==2){
        for(ll i=1;i<=N;i++){
        cin >> a[i];
        mp[a[i]]++;
        if(mp[a[i]]>=2)two=1;
        }
        if(two)ans=0;
        else ans=1;
    }
    if(D==3){
        for(int i=1;i<=N;i++){
            cin >> a[i];
            mp[a[i]]++;
            if(mp[a[i]]>=3)thr=1;
            mx = max(mx, a[i]);

        }
        if(thr){
            cout << 0 << "\n"; return;
        }
        for(int i=1;i<=N;i++){
            if(a[i]!=mx&&mp[a[i]]==2) ans=1;
            else if(mp[a[i]*2]>0) ans=1;
        }
    }
    cout << ans << "\n";

    
}
int main(){
    ll T; cin >> T;
    for(ll t=1;t<=T;t++){
        printf("Case #%lld: ", t);
        solve();

    }
    return 0;
}