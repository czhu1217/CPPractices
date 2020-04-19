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
int main(){
    ll T; cin >> T;
    for(ll t=1;t<=T;t++){
        printf("Case #%lld: ", t);
        ll N, D; cin >> N >> D;
        ll a[1002]; bool vis[1002]; ll cnt=0, ans=0;
        for(ll i=1;i<=N;i++){
            scanf("%lld", &a[i]);
        }
        ans = D;
        for(ll i=N;i>0;i--){
            ll rem = ans%a[i];
            ans -= rem;
        }
        printf("%lld\n", ans);

    }
    return 0;
}