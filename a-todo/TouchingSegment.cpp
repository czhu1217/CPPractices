#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
#define f first
#define s second
const ll MM = 2e5+5;
struct node{ll l, r, val, lz;} seg[3*MM];
ll T, N; pi a[MM];
struct event{
    ll l, i, v;
    bool operator<(const event &e){
        return l<e.l;
    }
};
void build(ll l, ll r, ll rt){
    seg[rt].l=l; seg[rt].r = r;
    if(l==r)return;

    ll mid = (seg[rt].l+seg[rt].r)/2;
    build(l, mid, 2*rt); build(mid+1, r, 2*rt+1);


}
void push_down(ll rt){
    seg[2*rt].lz += seg[rt].lz; seg[2*rt+1].lz += seg[rt].lz;
    seg[2*rt].val += seg[rt].lz; seg[2*rt+1].val += seg[rt].lz;
    seg[rt].lz=0;
}
void update(ll l, ll r, ll v, ll rt){
    if(seg[rt].l==l&&seg[rt].r==r){
        seg[rt].val+=v; seg[rt].lz+=v;return;
    }
    if(seg[rt].lz)push_down(rt);
    ll mid = (seg[rt].l+seg[rt].r)/2;
    if(r<=mid)update(l, r, v, 2*rt);
    else if(l>mid)update(l, r, v, 2*rt+1);
    else{
        update(l, mid, v, 2*rt);
        update(mid+1, r, v, 2*rt+1);
    }
    seg[rt].val = max(seg[2*rt].val, seg[2*rt+1].val);
}
int main(){
    cin >> T;
    for(ll t=1;t<=T;t++){
        map<ll, ll> mp; vector<event> p;
        memset(seg, 0, sizeof seg);
        cin >> N; ll ans=0, cnt=0, line=0;
        for(ll i=1;i<=N;i++){
            scanf("%lld %lld", &a[i].f, &a[i].s);
            mp[a[i].f]=0; mp[a[i].s] = 0;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            it->s = ++cnt;
        }
        build(1, cnt, 1);
        for(ll i=1;i<=N;i++){
            update(mp[a[i].f], mp[a[i].s], 1, 1);
            p.push_back({mp[a[i].f],i,  -1});
            p.push_back({mp[a[i].s], i, 1});
        }
        sort(p.begin(), p.end());
        for(auto e:p){
            ll i=e.i, lft = mp[a[i].f], rit = mp[a[i].s];
            if(e.v<0){
                line++; update(lft, rit, -1, 1);
            }
            else
            {
                line--; update(lft, rit, 1, 1);
            }
            ans = max(ans, line+seg[1].val);
            
        }
        printf("Case %lld: %lld\n", t, ans);
    }
    return 0;
    
}
