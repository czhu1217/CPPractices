#include <bits/stdc++.h>
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
const ll MM = 3e5+5;
ll n;
struct ev{
    ll l, r, op;
    bool operator<(const ev &x){
        return l==x.l?op<x.op:l < x.l;
    }
};
vector<ev> v;
int main(){
    cin >> n;
    ll x, y;
    FOR(i, 1, n){
        cin >> x >> y;
        v.pb({x,y, 1}); v.pb({y, x, 0});

    }
    sort(v.begin(), v.end());
    priority_queue<pi> pq;
    ll cur = 0, cnt=0;
    for(auto e:v){
        if(e.op){
            pq.push({e.r, e.l});
        }
        else{
            ll l = e.r, r = e.l;
            while(pq.top().f<l) pq.pop();
            if(cur>l) continue;
            cnt ++;
            cur = pq.top().f;

        }
    }
    cout << cnt << "\n";

    return 0;
}