//https://codeforces.com/problemset/problem/1342/C
#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
void solve(){
    ll a, b, q;
    cin >> a >> b >> q;
    if(a>b)swap(a, b);
    ll l, r;
    while(q--){
        cin >> l >> r; ll lo, hi; ll ans;
        ll lcm = a*b/(__gcd(a, b));
        ll firstCycle;
        if(lcm*l/lcm+b>=l) firstCycle = lcm*l/lcm+b;
        else firstCycle = lcm*l/lcm+b+lcm;
        ans = (r-firstCycle)/lcm*(lcm-b);
        if(firstCycle - b > l) ans += min(r-l+1, firstCycle-b-l);
        if(lcm*(r-firstCycle)/lcm+firstCycle+(lcm-b)<=r) ans += r-lcm*(r-firstCycle)/lcm+firstCycle+(lcm-b);
        if(firstCycle>r) ans=0;
        cout << ans << "\n";
    }
    cout << "\n";
}
int main(){
    ll t; cin >> t;
    while(t--)solve();
    return 0;
}