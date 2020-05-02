#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;
typedef long long ll;
ll N; pair<ll, ll> a[5005];
ll ans = LLONG_MAX;
const ll mx = 25e6/2+5;
ll dp[mx];
int main(){
    cin >> N; ll tot=0;
    memset(dp, 0x3f, sizeof(dp));
    dp[0]=0;

    for(ll i=1;i<=N;i++){
        scanf("%lld %lld", &a[i].first, &a[i].second);
        tot += a[i].second;
    }
        tot = tot/2+1;
        // cout << tot << endl;
    for(ll i=1;i<=N;i++){
        ll t = a[i].first/2+1;
        for(ll j=tot*2+1;j>=a[i].second;j--){
            dp[j] = min(dp[j], dp[j-a[i].second]+t);
            if(j>=tot){ans = min(ans, dp[j]);}
        }

    }
    cout << ans << "\n";
    return 0;
}