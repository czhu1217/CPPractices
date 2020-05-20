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
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
long double B[55];
const ll MM = 3e5+5, MM2 = 20, mod = 998244353; ll cnt=1;
ll n, q, lv[MM],st[MM2][2*MM+1], idx[MM], inv[MM], memo[MM][55];
vector<ll> adj[MM];
ll min_dis(ll a, ll b){
    return lv[a]<lv[b]?a:b;
}
ll quick_pow(ll x, ll exp){
    if(exp==0)return 1;
    ll t = quick_pow(x, exp/2);
    t = t*t%mod;
    return (exp&1)?t*x%mod:t;
}
ll query(ll a, ll b){
    a = idx[a]; b = idx[b];
    if(a>b)swap(a, b);
    ll d = b-a; ll mx=1, mxidx=0;
    for(ll i=MM2; i>=0;i--){
        if(d&(1<<i)){
            mxidx = i; mx = (1<<i); break;
        }
    }
    return min_dis(st[mxidx][a], st[mxidx][b-mx+1]);
}

void dfs(ll cur, ll pa, ll lvl){
    st[0][cnt++] = cur;
    lv[cur] = lvl;
    for(auto e:adj[cur]){
        if(e!=pa){dfs(e, cur, lvl+1);
        st[0][cnt++] = cur;}
    }
}

void build(){
    for(ll i=1;i<=cnt;i++){
        if(!idx[st[0][i]]){
            idx[st[0][i]] = i;
        }
    }
    for(ll i=1;i<=MM2;i++){
        ll jump = 1 << (i - 1), e = cnt - (1 << i) + 1;
        for(ll j=1;j<=e;j++){
            st[i][j] = min_dis(st[i-1][j], st[i-1][j+jump]);
        }
    }
}
int main(){
    cin >> n;
    for(ll i=1, u, v;i<n;i++){
        scanf("%lld%lld", &u, &v);
        adj[v].push_back(u); adj[u].push_back(v);
    }
    dfs(1, -1, 0);
    build();


    scanf("%lld", &q);
    ll u, v, k;
    while(q--){
        ll sum=0;
        scanf("%lld%lld%lld", &u, &v, &k);
        ll lca = query(u, v);
        for(ll i=lv[u];i>lv[lca];i--){
            ll po;
            if(!memo[i][k]) memo[i][k] = quick_pow(i, k);
            sum = (sum + memo[i][k])%mod;
        }

        for(ll i=lv[v];i>lv[lca];i--){
            if(!memo[i][k]) memo[i][k] = quick_pow(i, k);
            sum = (sum+memo[i][k])%mod;
        }
        if(!memo[lv[lca]][k]) memo[lv[lca]][k] = quick_pow(lv[lca], k);
        sum = (sum+memo[lv[lca]][k])%mod;
        cout << sum << "\n";

    }
    return 0;

}