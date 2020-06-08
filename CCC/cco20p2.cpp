
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
typedef long double ld;
typedef pair<ll, ll> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<ll> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define FOR(i, a, b) for (ll i=a; i<=(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define FORd(i,a,b) for (ll i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (ll i = (a)-1; i >= 0; i--)
 
#define sz(x) (ll)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const ll MM = 2e5+5;
ll n, ddl[MM], bit[MM], ans[MM];
priority_queue<ll> pq;
vector<ll> v[MM];
ll query(ll pos){
    ll sum=0;
    for(ll i=pos;i>0;i-=i&-i){
        sum+=bit[i];
    }
    return sum;
}

void update(ll pos, ll v){
    for(ll i=pos; i<=n;i+=i&-i){
        bit[i]+=v ;
    }
}
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;

    for(ll i=1;i<=n;i++){
        cin >> ddl[i];
        v[ddl[i]].pb(i);
    }
    for(ll i=n;i>0;i--){
        for(auto e:v[i]){
            pq.push(e);
        }
        if(pq.empty()){
            cout << -1 << "\n";
            return 0;
        }
        ans[i] = pq.top(); pq.pop();
        
    }
    ll res = 0; ll cur=0;
 
    for(ll i=n;i>0;i--){
        res += query(ans[i]);
        update(ans[i], 1);
    }
    cout << res << "\n";
    return 0;



}