#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<ll, ll> pi;
#define FOR(i, a, b) for (ll i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
const ll MM = 2e5+5;
struct fr{
    ll p, w, d;
} a[MM];
ll n;

vector<pair<ll, pi>> op, cl;
ll lco[2*MM], rco[2*MM];
int main(){
    cin >> n;
    FOR(i, 1, n){
        cin >> a[i].p >> a[i].w >> a[i].d;
    }
    FOR(i,1, n){
        op.pb( {a[i].p+a[i].d, {a[i].w, 1}});
        op.pb( {a[i].p-a[i].d, {a[i].w, 0}});
    }
    sort(op.begin(), op.end());
    FOR(i, 1, n){
        cl.pb( {a[i].p-a[i].d, {a[i].w, 1}});
        cl.pb( {a[i].p+a[i].d, {a[i].w, 0}});
    }
    sort(cl.begin(), cl.end());
    ll sum=0, ans=0;
    // for(auto e:op){
    //     cout << e.f << " ";
    // }
    // cout << "\n";
    for(ll i=1;i<op.size();i++){
        lco[i] = lco[i-1]+sum*(op[i].f-op[i-1].f);
        if(op[i].s.s)
        sum += op[i].s.f;
        // cout << op[i].f << " " << sum << "\n";
        // cout << lco[i] << " ";
        // cout << "\n";
    }
    // cout << "\n";
    sum=0;
    for(ll i=cl.size()-1;i>=0;i--){
        rco[i] = rco[i+1]+sum*(cl[i+1].f-cl[i].f);
        if(cl[i].s.s)
        sum += cl[i].s.f;
        // cout << rco[i] << " ";
    }
    // cout << "\n";
    ans = LLONG_MAX;
    FOR(i, 0, cl.size()-1){
        ans = min(ans, lco[i]+rco[i]);
    }
    cout << ans << "\n";
    // cout << lco[3] << " " << rco[3] << "\n";
    return 0;
}