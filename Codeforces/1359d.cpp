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
const ll MM = 1e5+2, LOG=19;
ll st[LOG][MM];
ll rmq(ll x, ll y){
    ll lvl = log2(y-x+1);
    return max(st[lvl][x], st[lvl][y-(1<<lvl)+1]);
}
void solve(){
    ll n, a[MM]; ll ans=0; ll pre[MM];
    pre[0]=0;
    cin >> n;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        st[0][i] = a[i];
        pre[i] = pre[i-1]+a[i];
    }
        for(ll i=1;i<LOG;i++){
        for(ll j=1;j+(1<<i)-1<=n;j++){
            st[i][j] = max(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }
    ll ed=n;
    for(ll i=1;i<=n;i++){
        ll best=LLONG_MIN, id=ed;
        for(ll j=i;j<=ed;j++){
            ll sum = pre[j]-pre[i-1];
            ll temp = sum-rmq(i, j);
            if(temp>best){
                id = j; best = temp;
            }
        }
        ans = max(ans, best);
        ed = id;
    }
    cout << ans << "\n";

}
int main(){
    solve();
    return 0;
}