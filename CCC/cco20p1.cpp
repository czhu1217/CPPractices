
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
const ll MM = 1e5+5;
ll n, l, r, y , ans[MM];
map<ll, ll> cnt;
map<ll, vector<ll>> ve;
vector<ll> qu;

int main(){
    memset(ans, 0, sizeof ans);
    cin >> n; cin >> l >> r >> y;
    for(ll i=1, ai, v, h;i<=n;i++){
        cin >> ai >> v>> h;
        ll lft = ai + y*(-h)/v;
        ll rt = ai + y*h/v;
        if(y*h%v==0){ rt--; lft++;}
        rt = min(r, rt);
        lft = max(lft, l);
        ve[lft].pb(rt+1);
        qu.pb(lft); qu.pb(rt+1);
    }
    qu.pb(l); qu.pb(r);
    sort(qu.begin(), qu.end());
    qu.erase(unique(qu.begin(), qu.end()), qu.end());

    ll cur=0;
    for(int i=0;i<qu.size();i++){
        for(auto e:ve[qu[i]]){
            cur++; cnt[e]++;
        }
        cur -= cnt[qu[i]];
        int nxt;
        if(i+1==qu.size()) nxt = r+1;
        else nxt = qu[i+1];
        ans[cur] += nxt - qu[i];

    }
    cout << ans[0] << "\n";
    for(int i=1;i<=n;i++){
        ans[i] += ans[i-1];
        cout << ans[i] << "\n";
    }

    
    
    return 0;
}
