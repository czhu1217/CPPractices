//https://codeforces.com/contest/1358/problem/D
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
const ll MM = 2e5+5;
ll a[MM], sum[MM];

void solve(){
    ll ans=0;
    ll n, x; cin >> n >> x; 
    for(ll i=0;i<n;i++){
        cin >> a[i];
        sum[i] = (1+a[i])*a[i]/2;
    }
    ll res=0;         ll d = 0;         ll it = n; 
    for(ll i=n-1;i>=0;i--){

        if(i!=n-1){
            res -= sum[i+1];
            d -= a[i+1];
        }
        while(d+a[it]<x){
            res += sum[it];
            d += a[it];
            it = (it-1+n)%n;
        }
        ll rem = x-d;
        ll val = (a[it]+a[it]-rem+1)*rem/2;
        ans = max(ans, res+val);
    }

    cout << ans << "\n";



}
int main(){
    solve();
    return 0;
}